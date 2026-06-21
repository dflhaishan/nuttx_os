/****************************************************************************
 * boards/arm/stm32/stm32f103-eval/src/stm32_lcd.c
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

/* This driver supports the following LCDs:
 *
 * 1. Ampire AM-240320LTNQW00H
 * 2. Orise Tech SPFD5408B
 * 3. RenesasSP R61580
 *
 * The driver dynamically selects the LCD based on the reported LCD ID value.
 * However, code size can be reduced by suppressing support for individual
 * LCDs using:
 *
 *   CONFIG_STM32F103_AM240320_DISABLE
 *   CONFIG_STM32F103_SPFD5408B_DISABLE
 *   CONFIG_STM32F103_R61580_DISABLE
 *
 * Omitting the above (or setting them to "n") enables support for the LCD.
 * Setting any of the above to "y" will disable support for the
 * corresponding LCD.
 */

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <sys/types.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <debug.h>

#include <nuttx/arch.h>
#include <nuttx/board.h>
#include <nuttx/spi/spi.h>
#include <nuttx/lcd/lcd.h>

#include <arch/board/board.h>
#include <nuttx/power/pm.h>

#include "arm_internal.h"
#include "stm32.h"
#include "stm32f103_alientek.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Configuration ************************************************************/

/* Check contrast selection */

#if !defined(CONFIG_LCD_MAXCONTRAST)
#  define CONFIG_LCD_MAXCONTRAST 1
#endif

/* Display/Color Properties *************************************************/

/* Display Resolution */
#  define STM32F103_XRES       480
#  define STM32F103_YRES       800


/* Color depth and format */

#define STM32F103_BPP          16
#define STM32F103_COLORFMT     FB_FMT_RGB16_565

/* STM32F103-EVAL LCD Hardware Definitions ***********************************/

/* LCD /CS is CE4,  Bank 4 of NOR/SRAM Bank 1~4 */

#define STM32F103_LCDBASE      ((uint32_t)(0x60000000 | 0x0c000000) | 0x7FE)
#define LCD                   ((struct lcd_regs_s *) STM32F103_LCDBASE)

#define LCD_REG_CURSOR_X             0x2A00
#define LCD_REG_CURSOR_Y             0x2B00
#define LCD_REG_WRITE_GRAM           0x2C00
#define LCD_REG_READ_GRAM            0x2E00

/****************************************************************************
 * Private Types
 ****************************************************************************/

/* LCD type */

enum lcd_type_e
{
  LCD_TYPE_UNKNOWN = 0,
  LCD_TYPE_AL5510,
};

/* This structure describes the LCD registers */

struct lcd_regs_s
{
  volatile uint16_t address;
  volatile uint16_t value;
};

/* This structure describes the state of this driver */

struct stm32f103_dev_s
{
  /* Publicly visible device structure */

  struct lcd_dev_s dev;

  /* Private LCD-specific information follows */

  uint8_t  type;        /* LCD type. See enum lcd_type_e */
  uint8_t  power;       /* Current power setting */
};

/****************************************************************************
 * Private Function Protototypes
 ****************************************************************************/

/* Low Level LCD access */

static void stm32f103_writereg(uint16_t regaddr, uint16_t regval);
// static uint16_t stm32f103_readreg(uint16_t regaddr);
static inline void stm32f103_writegram(uint16_t rgbval);

static void stm32f103_setcursor(uint16_t col, uint16_t row);
static void stm32f103_lcdclear(uint16_t color);
/* LCD Data Transfer Methods */

static int stm32f103_putrun(struct lcd_dev_s *dev,
                           fb_coord_t row, fb_coord_t col,
                           const uint8_t *buffer,
                           size_t npixels);
static int stm32f103_getrun(struct lcd_dev_s *dev,
                           fb_coord_t row, fb_coord_t col,
                           uint8_t *buffer,
                           size_t npixels);

/* LCD Configuration */

static int stm32f103_getvideoinfo(struct lcd_dev_s *dev,
                                 struct fb_videoinfo_s *vinfo);
static int stm32f103_getplaneinfo(struct lcd_dev_s *dev,
                                 unsigned int planeno,
                                 struct lcd_planeinfo_s *pinfo);

/* LCD Specific Controls */

static int stm32f103_getpower(struct lcd_dev_s *dev);
static int stm32f103_setpower(struct lcd_dev_s *dev, int power);
static int stm32f103_getcontrast(struct lcd_dev_s *dev);
static int stm32f103_setcontrast(struct lcd_dev_s *dev,
                                unsigned int contrast);

/* Initialization */

static inline void stm32f103_lcdinitialize(void);

/****************************************************************************
 * Private Data
 ****************************************************************************/

/* This is working memory allocated by the LCD driver for each LCD device
 * and for each color plane.  This memory will hold one raster line of data.
 * The size of the allocated run buffer must therefore be at least
 * (bpp * xres / 8).  Actual alignment of the buffer must conform to the
 * bitwidth of the underlying pixel type.
 *
 * If there are multiple planes, they may share the same working buffer
 * because different planes will not be operate on concurrently.  However,
 * if there are multiple LCD devices, they must each have unique run buffers.
 */

static uint16_t g_runbuffer[STM32F103_XRES];

/* This structure describes the overall LCD video controller */

static const struct fb_videoinfo_s g_videoinfo =
{
  .fmt     = STM32F103_COLORFMT,    /* Color format: RGB16-565: RRRR RGGG GGGB BBBB */
  .xres    = STM32F103_XRES,        /* Horizontal resolution in pixel columns */
  .yres    = STM32F103_YRES,        /* Vertical resolution in pixel rows */
  .nplanes = 1,                    /* Number of color planes supported */
};

/* This is the standard, NuttX Plane information object */

static const struct lcd_planeinfo_s g_planeinfo =
{
  .putrun = stm32f103_putrun,        /* Put a run into LCD memory */
  .getrun = stm32f103_getrun,        /* Get a run from LCD memory */
  .buffer = (uint8_t *)g_runbuffer, /* Run scratch buffer */
  .bpp    = STM32F103_BPP,           /* Bits-per-pixel */
};

/* This is the standard, NuttX LCD driver object */

static struct stm32f103_dev_s g_lcddev =
{
  .dev =
  {
    /* LCD Configuration */

    .getvideoinfo = stm32f103_getvideoinfo,
    .getplaneinfo = stm32f103_getplaneinfo,

    /* LCD RGB Mapping -- Not supported */

    /* Cursor Controls -- Not supported */

    /* LCD Specific Controls */

    .getpower     = stm32f103_getpower,
    .setpower     = stm32f103_setpower,
    .getcontrast  = stm32f103_getcontrast,
    .setcontrast  = stm32f103_setcontrast,
  },
};

typedef struct 
{
    uint16_t cmd;
    uint16_t val;
}lcd_cmd_t;

const lcd_cmd_t lcd_cmd[] =
{
    {0xF000, 0x55}, {0xF001, 0xAA}, {0xF002, 0x52}, {0xF003, 0x08}, {0xF004, 0x01}, 
    //AVDD Set AVDD 5.2V
    {0xB000, 0x0D}, {0xB001, 0x0D}, {0xB002, 0x0D}, 
    //AVDD ratio
    {0xB600, 0x34}, {0xB601, 0x34}, {0xB602, 0x34}, 
    //AVEE -5.2V
    {0xB100, 0x0D}, {0xB101, 0x0D}, {0xB102, 0x0D}, 
    //AVEE ratio
    {0xB700, 0x34}, {0xB701, 0x34}, {0xB702, 0x34}, 
    //VCL -2.5V
    {0xB200, 0x00}, {0xB201, 0x00}, {0xB202, 0x00}, 
    //VCL ratio
    {0xB800, 0x24}, {0xB801, 0x24}, {0xB802, 0x24}, 
    //VGH 15V (Free pump)
    {0xBF00, 0x01}, {0xB300, 0x0F}, {0xB301, 0x0F}, {0xB302, 0x0F}, 
    //VGH ratio
    {0xB900, 0x34}, {0xB901, 0x34}, {0xB902, 0x34}, 
    //VGL_REG -10V
    {0xB500, 0x08}, {0xB501, 0x08}, {0xB502, 0x08}, {0xC200, 0x03}, 
    //VGLX ratio
    {0xBA00, 0x24}, {0xBA01, 0x24}, {0xBA02, 0x24}, 
    //VGMP/VGSP 4.5V/0V
    {0xBC00, 0x00}, {0xBC01, 0x78}, {0xBC02, 0x00}, 
    //VGMN/VGSN -4.5V/0V
    {0xBD00, 0x00}, {0xBD01, 0x78}, {0xBD02, 0x00}, 
    //VCOM
    {0xBE00, 0x00}, {0xBE01, 0x64}, {0xD100, 0x00}, {0xD101, 0x33}, 
    {0xD102, 0x00}, {0xD103, 0x34}, {0xD104, 0x00}, {0xD105, 0x3A}, 
    {0xD106, 0x00}, {0xD107, 0x4A}, {0xD108, 0x00}, {0xD109, 0x5C}, 
    {0xD10A, 0x00}, {0xD10B, 0x81}, {0xD10C, 0x00}, {0xD10D, 0xA6}, 
    {0xD10E, 0x00}, {0xD10F, 0xE5}, {0xD110, 0x01}, {0xD111, 0x13}, 
    {0xD112, 0x01}, {0xD113, 0x54}, {0xD114, 0x01}, {0xD115, 0x82}, 
    {0xD116, 0x01}, {0xD117, 0xCA}, {0xD118, 0x02}, {0xD119, 0x00}, 
    {0xD11A, 0x02}, {0xD11B, 0x01}, {0xD11C, 0x02}, {0xD11D, 0x34}, 
    {0xD11E, 0x02}, {0xD11F, 0x67}, {0xD121, 0x84}, {0xD122, 0x02}, 
    {0xD123, 0xA4}, {0xD124, 0x02}, {0xD125, 0xB7}, {0xD126, 0x02}, 
    {0xD127, 0xCF}, {0xD128, 0x02}, {0xD129, 0xDE}, {0xD12A, 0x02}, 
    {0xD12B, 0xF2}, {0xD12C, 0x02}, {0xD12D, 0xFE}, {0xD12E, 0x03}, 
    {0xD12F, 0x10}, {0xD130, 0x03}, {0xD131, 0x33}, {0xD132, 0x03}, 
    {0xD133, 0x6D}, {0xD200, 0x00}, {0xD201, 0x33}, {0xD202, 0x00}, 
    {0xD203, 0x34}, {0xD204, 0x00}, {0xD205, 0x3A}, {0xD206, 0x00}, 
    {0xD207, 0x4A}, {0xD208, 0x00}, {0xD209, 0x5C}, {0xD20A, 0x00}, 
    {0xD20B, 0x81}, {0xD20C, 0x00}, {0xD20D, 0xA6}, {0xD20E, 0x00}, 
    {0xD20F, 0xE5}, {0xD210, 0x01}, {0xD211, 0x13}, {0xD212, 0x01}, 
    {0xD213, 0x54}, {0xD214, 0x01}, {0xD215, 0x82}, {0xD216, 0x01}, 
    {0xD217, 0xCA}, {0xD218, 0x02}, {0xD219, 0x00}, {0xD21A, 0x02}, 
    {0xD21B, 0x01}, {0xD21C, 0x02}, {0xD21D, 0x34}, {0xD21E, 0x02}, 
    {0xD21F, 0x67}, {0xD220, 0x02}, {0xD221, 0x84}, {0xD222, 0x02}, 
    {0xD223, 0xA4}, {0xD224, 0x02}, {0xD225, 0xB7}, {0xD226, 0x02}, 
    {0xD227, 0xCF}, {0xD228, 0x02}, {0xD229, 0xDE}, {0xD22A, 0x02}, 
    {0xD22B, 0xF2}, {0xD22C, 0x02}, {0xD22D, 0xFE}, {0xD22E, 0x03}, 
    {0xD22F, 0x10}, {0xD230, 0x03}, {0xD231, 0x33}, {0xD232, 0x03}, 
    {0xD233, 0x6D}, {0xD300, 0x00}, {0xD301, 0x33}, {0xD302, 0x00}, 
    {0xD303, 0x34}, {0xD304, 0x00}, {0xD305, 0x3A}, {0xD306, 0x00}, 
    {0xD307, 0x4A}, {0xD308, 0x00}, {0xD309, 0x5C}, {0xD30A, 0x00}, 
    {0xD30B, 0x81}, {0xD30C, 0x00}, {0xD30D, 0xA6}, {0xD30E, 0x00}, 
    {0xD30F, 0xE5}, {0xD310, 0x01}, {0xD311, 0x13}, {0xD312, 0x01}, 
    {0xD313, 0x54}, {0xD314, 0x01}, {0xD315, 0x82}, {0xD316, 0x01}, 
    {0xD317, 0xCA}, {0xD318, 0x02}, {0xD319, 0x00}, {0xD31A, 0x02}, 
    {0xD31B, 0x01}, {0xD31C, 0x02}, {0xD31D, 0x34}, {0xD31E, 0x02}, 
    {0xD31F, 0x67}, {0xD320, 0x02}, {0xD321, 0x84}, {0xD322, 0x02}, 
    {0xD323, 0xA4}, {0xD324, 0x02}, {0xD325, 0xB7}, {0xD326, 0x02}, 
    {0xD327, 0xCF}, {0xD328, 0x02}, {0xD329, 0xDE}, {0xD32A, 0x02}, 
    {0xD32B, 0xF2}, {0xD32C, 0x02}, {0xD32D, 0xFE}, {0xD32E, 0x03}, 
    {0xD32F, 0x10}, {0xD330, 0x03}, {0xD331, 0x33}, {0xD332, 0x03}, 
    {0xD333, 0x6D}, {0xD400, 0x00}, {0xD401, 0x33}, {0xD402, 0x00}, 
    {0xD403, 0x34}, {0xD404, 0x00}, {0xD405, 0x3A}, {0xD406, 0x00}, 
    {0xD407, 0x4A}, {0xD408, 0x00}, {0xD409, 0x5C}, {0xD40A, 0x00}, 
    {0xD40B, 0x81}, {0xD40C, 0x00}, {0xD40D, 0xA6}, {0xD40E, 0x00}, 
    {0xD40F, 0xE5}, {0xD410, 0x01}, {0xD411, 0x13}, {0xD412, 0x01}, 
    {0xD413, 0x54}, {0xD414, 0x01}, {0xD415, 0x82}, {0xD416, 0x01}, 
    {0xD417, 0xCA}, {0xD418, 0x02}, {0xD419, 0x00}, {0xD41A, 0x02}, 
    {0xD41B, 0x01}, {0xD41C, 0x02}, {0xD41D, 0x34}, {0xD41E, 0x02},
    {0xD41F, 0x67}, {0xD420, 0x02}, {0xD421, 0x84}, {0xD422, 0x02}, 
    {0xD423, 0xA4}, {0xD424, 0x02}, {0xD425, 0xB7}, {0xD426, 0x02}, 
    {0xD427, 0xCF}, {0xD428, 0x02}, {0xD429, 0xDE}, {0xD42A, 0x02}, 
    {0xD42B, 0xF2}, {0xD42C, 0x02}, {0xD42D, 0xFE}, {0xD42E, 0x03}, 
    {0xD42F, 0x10}, {0xD430, 0x03}, {0xD431, 0x33}, {0xD432, 0x03}, 
    {0xD433, 0x6D}, {0xD500, 0x00}, {0xD501, 0x33}, {0xD502, 0x00}, 
    {0xD503, 0x34}, {0xD504, 0x00}, {0xD505, 0x3A}, {0xD506, 0x00}, 
    {0xD507, 0x4A}, {0xD508, 0x00}, {0xD509, 0x5C}, {0xD50A, 0x00}, 
    {0xD50B, 0x81}, {0xD50C, 0x00}, {0xD50D, 0xA6}, {0xD50E, 0x00}, 
    {0xD50F, 0xE5}, {0xD510, 0x01}, {0xD511, 0x13}, {0xD512, 0x01}, 
    {0xD513, 0x54}, {0xD514, 0x01}, {0xD515, 0x82}, {0xD516, 0x01}, 
    {0xD517, 0xCA}, {0xD518, 0x02}, {0xD519, 0x00}, {0xD51A, 0x02}, 
    {0xD51B, 0x01}, {0xD51C, 0x02}, {0xD51D, 0x34}, {0xD51E, 0x02}, 
    {0xD51F, 0x67}, {0xD520, 0x02}, {0xD521, 0x84}, {0xD522, 0x02}, 
    {0xD523, 0xA4}, {0xD524, 0x02}, {0xD525, 0xB7}, {0xD526, 0x02}, 
    {0xD527, 0xCF}, {0xD528, 0x02}, {0xD529, 0xDE}, {0xD52A, 0x02}, 
    {0xD52B, 0xF2}, {0xD52C, 0x02}, {0xD52D, 0xFE}, {0xD52E, 0x03}, 
    {0xD52F, 0x10}, {0xD530, 0x03}, {0xD531, 0x33}, {0xD532, 0x03}, 
    {0xD533, 0x6D}, {0xD600, 0x00}, {0xD601, 0x33}, {0xD602, 0x00}, 
    {0xD603, 0x34}, {0xD604, 0x00}, {0xD605, 0x3A}, {0xD606, 0x00}, 
    {0xD607, 0x4A}, {0xD608, 0x00}, {0xD609, 0x5C}, {0xD60A, 0x00}, 
    {0xD60B, 0x81}, {0xD60C, 0x00}, {0xD60D, 0xA6}, {0xD60E, 0x00}, 
    {0xD60F, 0xE5}, {0xD610, 0x01}, {0xD611, 0x13}, {0xD612, 0x01}, 
    {0xD613, 0x54}, {0xD614, 0x01}, {0xD615, 0x82}, {0xD616, 0x01}, 
    {0xD617, 0xCA}, {0xD618, 0x02}, {0xD619, 0x00}, {0xD61A, 0x02}, 
    {0xD61B, 0x01}, {0xD61C, 0x02}, {0xD61D, 0x34}, {0xD61E, 0x02}, 
    {0xD61F, 0x67}, {0xD620, 0x02}, {0xD621, 0x84}, {0xD622, 0x02}, 
    {0xD623, 0xA4}, {0xD624, 0x02}, {0xD625, 0xB7}, {0xD626, 0x02}, 
    {0xD627, 0xCF}, {0xD628, 0x02}, {0xD629, 0xDE}, {0xD62A, 0x02}, 
    {0xD62B, 0xF2}, {0xD62C, 0x02}, {0xD62D, 0xFE}, {0xD62E, 0x03}, 
    {0xD62F, 0x10}, {0xD630, 0x03}, {0xD631, 0x33}, {0xD632, 0x03}, 
    {0xD633, 0x6D}, 
    //LV2 Page 0 enable
    {0xF000, 0x55}, {0xF001, 0xAA}, {0xF002, 0x52}, {0xF003, 0x08}, 
    {0xF004, 0x00}, 
    //Display control
    {0xB100,  0xCC}, {0xB101,  0x00}, 
    //Source hold time
    {0xB600, 0x05}, 
    //Gate EQ control
    {0xB700, 0x70}, {0xB701, 0x70}, 
    //Source EQ control (Mode 2)
    {0xB800, 0x01}, {0xB801, 0x03}, {0xB802, 0x03}, {0xB803, 0x03}, 
    //Inversion mode (2-dot)
    {0xBC00, 0x02}, {0xBC01, 0x00}, {0xBC02, 0x00}, 
    //Timing control 4H w/ 4-delay
    {0xC900, 0xD0}, {0xC901, 0x02}, {0xC902, 0x50}, {0xC903, 0x50}, 
    {0xC904, 0x50}, {0x3500, 0x00}, 
    //16-bit/pixel
    {0x3A00, 0x55},   
};

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name:  stm32f103_writereg
 *
 * Description:
 *   Write to an LCD register
 *
 ****************************************************************************/

static void stm32f103_writereg(uint16_t regaddr, uint16_t regval)
{
  /* Write the register address then write the register value */

  LCD->address = regaddr;
  LCD->value   = regval;
}

/****************************************************************************
 * Name:  stm32f103_readreg
 *
 * Description:
 *   Read from an LCD register
 *
 ****************************************************************************/

// static uint16_t stm32f103_readreg(uint16_t regaddr)
// {
//   /* Write the register address then read the register value */

//   LCD->address = regaddr;
//   return LCD->value;
// }

/****************************************************************************
 * Name:  stm32f103_writegram
 *
 * Description:
 *   Write one pixel to the GRAM memory
 *
 ****************************************************************************/

static inline void stm32f103_writegram(uint16_t rgbval)
{
  /* Write the value (GRAM register already selected) */
  stm32f103_writereg(LCD_REG_WRITE_GRAM, rgbval);
}

/****************************************************************************
 * Name:  stm32f103_readgram
 *
 * Description:
 *   Read one pixel from the GRAM memory
 *
 ****************************************************************************/

static inline uint16_t stm32f103_readgram(void)
{
  /* Write the value (GRAM register already selected) */
  uint16_t r = 0, g = 0, b = 0;
  LCD->address = LCD_REG_READ_GRAM;
  up_mdelay(2);
  r = LCD->value;
  up_mdelay(2);
  g = LCD->value;
  up_mdelay(2);
  b = LCD->value;

  return  (((r>>11)<<11)| ((g>>10)<<5) | (b>>11));
}

/****************************************************************************
 * Name:  stm32f103_setcursor
 *
 * Description:
 *   Set the cursor position.  In landscape mode, the "column" is actually
 *   the physical Y position and the "row" is the physical X position.
 *
 ****************************************************************************/

static void stm32f103_setcursor(uint16_t col, uint16_t row)
{
//   stm32f103_writereg(LCD_REG_CURSOR_X, row); /* GRAM horizontal address */
//   stm32f103_writereg(LCD_REG_CURSOR_Y, col); /* GRAM vertical address */
    LCD->address = LCD_REG_CURSOR_X;
    LCD->value = (row >> 8);
    LCD->address = LCD_REG_CURSOR_X + 1;
    LCD->value = (row & 0xff);
    LCD->address = LCD_REG_CURSOR_Y;
    LCD->value = (col >> 8);
    LCD->address = LCD_REG_CURSOR_Y + 1;
    LCD->value = (col & 0xff);  
}

/****************************************************************************
 * Name:  stm32f103_putrun
 *
 * Description:
 *   This method can be used to write a partial raster line to the LCD:
 *
 *   dev     - The lcd device
 *   row     - Starting row to write to (range: 0 <= row < yres)
 *   col     - Starting column to write to (range: 0 <= col <= xres-npixels)
 *   buffer  - The buffer containing the run to be written to the LCD
 *   npixels - The number of pixels to write to the LCD
 *             (range: 0 < npixels <= xres-col)
 *
 ****************************************************************************/

static int stm32f103_putrun(struct lcd_dev_s *dev,
                           fb_coord_t row, fb_coord_t col,
                           const uint8_t *buffer,
                           size_t npixels)
{
  const uint16_t *src = (const uint16_t *)buffer;
  int i;

  /* Buffer must be provided and aligned to a 16-bit address boundary */

  lcdinfo("row: %d col: %d npixels: %d\n", row, col, npixels);
  DEBUGASSERT(buffer && ((uintptr_t)buffer & 1) == 0);

  /* Write the run to GRAM. */

  /* Then write the GRAM data, manually incrementing Y (which is col) */

  for (i = 0; i < npixels; i++)
    {
      /* Write the next pixel to this position */

      stm32f103_setcursor(row, col);
      stm32f103_writegram(*src++);

      /* Increment to next column */

      col++;
    }


  return OK;
}

/****************************************************************************
 * Name:  stm32f103_getrun
 *
 * Description:
 *   This method can be used to read a partial raster line from the LCD:
 *
 *  dev     - The lcd device
 *  row     - Starting row to read from (range: 0 <= row < yres)
 *  col     - Starting column to read read (range: 0 <= col <= xres-npixels)
 *  buffer  - The buffer in which to return the run read from the LCD
 *  npixels - The number of pixels to read from the LCD
 *            (range: 0 < npixels <= xres-col)
 *
 ****************************************************************************/

static int stm32f103_getrun(struct lcd_dev_s *dev,
                           fb_coord_t row, fb_coord_t col,
                           uint8_t *buffer,
                           size_t npixels)
{
  uint16_t *dest = (uint16_t *)buffer;
  int i;

  /* Buffer must be provided and aligned to a 16-bit address boundary */

  lcdinfo("row: %d col: %d npixels: %d\n", row, col, npixels);
  DEBUGASSERT(buffer && ((uintptr_t)buffer & 1) == 0);

  /* Read the run from GRAM. */

  /* Then read the GRAM data, manually incrementing Y (which is col) */

  for (i = 0; i < npixels; i++)
    {
      /* Read the next pixel from this position */

      stm32f103_setcursor(row, col);
      *dest++ = stm32f103_readgram();

      /* Increment to next column */

      col++;
    }


  return OK;
}

/****************************************************************************
 * Name:  stm32f103_getvideoinfo
 *
 * Description:
 *   Get information about the LCD video controller configuration.
 *
 ****************************************************************************/

static int stm32f103_getvideoinfo(struct lcd_dev_s *dev,
                                 struct fb_videoinfo_s *vinfo)
{
  DEBUGASSERT(dev && vinfo);
  ginfo("fmt: %d xres: %d yres: %d nplanes: %d\n",
         g_videoinfo.fmt, g_videoinfo.xres,
         g_videoinfo.yres, g_videoinfo.nplanes);
  memcpy(vinfo, &g_videoinfo, sizeof(struct fb_videoinfo_s));
  return OK;
}

/****************************************************************************
 * Name:  stm32f103_getplaneinfo
 *
 * Description:
 *   Get information about the configuration of each LCD color plane.
 *
 ****************************************************************************/

static int stm32f103_getplaneinfo(struct lcd_dev_s *dev,
                                 unsigned int planeno,
                                 struct lcd_planeinfo_s *pinfo)
{
  DEBUGASSERT(dev && pinfo && planeno == 0);
  ginfo("planeno: %d bpp: %d\n", planeno, g_planeinfo.bpp);
  memcpy(pinfo, &g_planeinfo, sizeof(struct lcd_planeinfo_s));
  pinfo->dev = dev;
  return OK;
}

/****************************************************************************
 * Name:  stm32f103_getpower
 *
 * Description:
 *   Get the LCD panel power status (0: full off - CONFIG_LCD_MAXPOWER:
 *   full on). On backlit LCDs, this setting may correspond to the backlight
 *   setting.
 *
 ****************************************************************************/

static int stm32f103_getpower(struct lcd_dev_s *dev)
{
  ginfo("power: %d\n", 0);
  return g_lcddev.power;
}

/****************************************************************************
 * Name:  stm32f103_poweroff
 *
 * Description:
 *   Enable/disable LCD panel power (0: full off - CONFIG_LCD_MAXPOWER:
 *   full on). On backlit LCDs, this setting may correspond to the backlight
 *   setting.
 *
 ****************************************************************************/

static int stm32f103_poweroff(void)
{
  stm32_configgpio(GPIO_LCD_BACKLIGHT);
  stm32_gpiowrite(GPIO_LCD_BACKLIGHT, false);
  /* Remember the power off state */

  g_lcddev.power = 0;
  return OK;
}

/****************************************************************************
 * Name:  stm32f103_setpower
 *
 * Description:
 *   Enable/disable LCD panel power (0: full off - CONFIG_LCD_MAXPOWER:
 *   full on). On backlit LCDs, this setting may correspond to the backlight
 *   setting.
 *
 ****************************************************************************/

static int stm32f103_setpower(struct lcd_dev_s *dev, int power)
{
  ginfo("power: %d\n", power);

  /* Set new power level */

  if (power > 0)
    {
      /* Turn the backlight on */

      stm32_gpiowrite(GPIO_LCD_BACKLIGHT, true);
      /* Then turn the display on */
      g_lcddev.power = power;
    }
  else
    {
      /* Turn the display off */

      stm32f103_poweroff();
    }

  return OK;
}

/****************************************************************************
 * Name:  stm32f103_getcontrast
 *
 * Description:
 *   Get the current contrast setting (0-CONFIG_LCD_MAXCONTRAST).
 *
 ****************************************************************************/

static int stm32f103_getcontrast(struct lcd_dev_s *dev)
{
  ginfo("Not implemented\n");
  return -ENOSYS;
}

/****************************************************************************
 * Name:  stm32f103_setcontrast
 *
 * Description:
 *   Set LCD panel contrast (0-CONFIG_LCD_MAXCONTRAST).
 *
 ****************************************************************************/

static int stm32f103_setcontrast(struct lcd_dev_s *dev, unsigned int contrast)
{
  ginfo("contrast: %d\n", contrast);
  return -ENOSYS;
}

static inline void stm32f103_lcdinitialize(void)
{
    g_lcddev.type = LCD_TYPE_AL5510;

    for (uint32_t i = 0; i < sizeof(lcd_cmd) / sizeof(lcd_cmd_t); i++)
    {
        LCD->address = lcd_cmd[i].cmd;
        LCD->value   = lcd_cmd[i].val;
    }

    stm32_configgpio(GPIO_LCD_BACKLIGHT);
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name:  board_lcd_initialize
 *
 * Description:
 *   Initialize the LCD video hardware.  The initial state of the LCD is
 *   fully initialized, display memory cleared, and the LCD ready to use,
 *   but with the power setting at 0 (full off).
 *
 ****************************************************************************/

int board_lcd_initialize(void)
{
  ginfo("Initializing\n");

  /* Register to receive power management callbacks */

  /* Configure GPIO pins and configure the FSMC to support the LCD */

  stm32_selectlcd();

  /* Configure and enable LCD */

  up_mdelay(50);
  stm32f103_lcdinitialize();

  /* Clear the display (setting it to the color 0=black) */

  stm32f103_lcdclear(0);

  /* Turn the backlight off */

  stm32f103_poweroff();
  return OK;
}

/****************************************************************************
 * Name:  board_lcd_getdev
 *
 * Description:
 *   Return a a reference to the LCD object for the specified LCD.  This
 *   allows support for multiple LCD devices.
 *
 ****************************************************************************/

struct lcd_dev_s *board_lcd_getdev(int lcddev)
{
  DEBUGASSERT(lcddev == 0);
  return &g_lcddev.dev;
}

/****************************************************************************
 * Name:  board_lcd_uninitialize
 *
 * Description:
 *   Uninitialize the LCD support
 *
 ****************************************************************************/

void board_lcd_uninitialize(void)
{
  stm32f103_poweroff();
  stm32_deselectlcd();
}

/****************************************************************************
 * Name:  stm32f103_lcdclear
 *
 * Description:
 *   This is a non-standard LCD interface just for the STM32F103-EVAL board.
 *   Because of the various rotations, clearing the display in the normal
 *   way by writing a sequences of runs that covers the entire display can
 *   be very slow.  Here the display is cleared by simply setting all GRAM
 *   memory to the specified color.
 *
 ****************************************************************************/

static void stm32f103_lcdclear(uint16_t color)
{
  uint32_t i = 0;

  stm32f103_setcursor(0, STM32F103_XRES - 1);
  for (i = 0; i < STM32F103_XRES * STM32F103_YRES; i++)
    {
      LCD->value = color;
    }
}
