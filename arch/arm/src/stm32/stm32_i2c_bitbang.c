/****************************************************************************
 * arch/arm/src/stm32/stm32_i2c_bitbang.c
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

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#ifdef CONFIG_STM32_I2C_BITBANG
#include <assert.h>
#include <nuttx/i2c/i2c_master.h>
#include <nuttx/i2c/i2c_bitbang.h>
#include <nuttx/kmalloc.h>
#include <arch/board/board.h>
#include "chip.h"

#define I2C_BITBANG_SCLPIN  (GPIO_OUTPUT|GPIO_CNF_OUTPP|GPIO_MODE_50MHz|\
                             GPIO_OUTPUT_SET|GPIO_PORTB|GPIO_PIN1)
#define I2C_BITBANG_SDAPIN  (GPIO_OUTPUT|GPIO_CNF_OUTPP|GPIO_MODE_50MHz|\
                             GPIO_OUTPUT_SET|GPIO_PORTF|GPIO_PIN9)


// #define STRINGIFY(x) #x
// #define TOSTRING(x) STRINGIFY(x)

// #ifndef I2C_BITBANG_SCLPIN
// #error "i2c bitbang is needed to define scl pin"
// #else
// #pragma message("i2c bitbang scl pin is " TOSTRING(I2C_BITBANG_SCLPIN))
// #endif

// #ifndef I2C_BITBANG_SDAPIN
// #error "i2c bitbang is needed to define sda pin"
// #else
// #pragma message("i2c bitbang sda pin is " TOSTRING(I2C_BITBANG_SDAPIN))
// #endif

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Types
 ****************************************************************************/

struct stm32_i2c_bitbang_dev_s
{
  struct i2c_bitbang_lower_dev_s lower;
  int sda_pin;
  int scl_pin;
};

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

static void stm32_i2c_bitbang_init(struct i2c_bitbang_lower_dev_s *lower);
static void stm32_i2c_bitbang_set_scl(struct i2c_bitbang_lower_dev_s *lower,
                                    bool value);
static void stm32_i2c_bitbang_set_sda(struct i2c_bitbang_lower_dev_s *lower,
                                    bool value);
static bool stm32_i2c_bitbang_get_scl(struct i2c_bitbang_lower_dev_s *lower);
static bool stm32_i2c_bitbang_get_sda(struct i2c_bitbang_lower_dev_s *lower);

/****************************************************************************
 * Private Data
 ****************************************************************************/

/* Lower-half I2C bitbang data  */

const static struct i2c_bitbang_lower_ops_s g_ops =
{
  .initialize = stm32_i2c_bitbang_init,
  .set_scl    = stm32_i2c_bitbang_set_scl,
  .set_sda    = stm32_i2c_bitbang_set_sda,
  .get_scl    = stm32_i2c_bitbang_get_scl,
  .get_sda    = stm32_i2c_bitbang_get_sda
};

/****************************************************************************
 * Public Data
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: stm32_i2c_bitbang_init
 *
 * Description:
 *   Initialize the I2C bit-bang driver
 *
 * Input Parameters:
 *   lower - A pointer the publicly visible representation of
 *           the "lower-half" driver state structure.
 *
 * Returned Value:
 *   None
 *
 ****************************************************************************/

static void stm32_i2c_bitbang_init(struct i2c_bitbang_lower_dev_s *lower)
{
  struct stm32_i2c_bitbang_dev_s *dev = lower->priv;

  stm32_configgpio(dev->scl_pin);
  stm32_configgpio(dev->sda_pin);

}

/****************************************************************************
 * Name: stm32_i2c_bitbang_set_scl
 *
 * Description:
 *   Set SCL line value
 *
 * Input Parameters:
 *   lower - A pointer the publicly visible representation of
 *           the "lower-half" driver state structure.
 *   value - The value to be written (0 or 1).
 *
 * Returned Value:
 *   None
 *
 ****************************************************************************/

static void stm32_i2c_bitbang_set_scl(struct i2c_bitbang_lower_dev_s *lower,
                                    bool value)
{
  struct stm32_i2c_bitbang_dev_s *dev =
    (struct stm32_i2c_bitbang_dev_s *)lower->priv;

  stm32_gpiowrite(dev->scl_pin, value);
}

/****************************************************************************
 * Name: stm32_i2c_bitbang_set_sda
 *
 * Description:
 *   Set SDA line value
 *
 * Input Parameters:
 *   lower - A pointer the publicly visible representation of
 *           the "lower-half" driver state structure.
 *   value - The value to be written (0 or 1).
 *
 * Returned Value:
 *   None
 *
 ****************************************************************************/

static void stm32_i2c_bitbang_set_sda(struct i2c_bitbang_lower_dev_s *lower,
                                    bool value)
{
  struct stm32_i2c_bitbang_dev_s *dev =
    (struct stm32_i2c_bitbang_dev_s *)lower->priv;

  stm32_gpiowrite(dev->sda_pin, value);
}

/****************************************************************************
 * Name: stm32_i2c_bitbang_get_scl
 *
 * Description:
 *   Get value from SCL line
 *
 * Input Parameters:
 *   lower - A pointer the publicly visible representation of
 *           the "lower-half" driver state structure.
 *
 * Returned Value:
 *   The boolean representation of the SCL line value (true/false).
 *
 ****************************************************************************/

static bool stm32_i2c_bitbang_get_scl(struct i2c_bitbang_lower_dev_s *lower)
{
  struct stm32_i2c_bitbang_dev_s *dev =
    (struct stm32_i2c_bitbang_dev_s *)lower->priv;

  return stm32_gpioread(dev->scl_pin);
}

/****************************************************************************
 * Name: stm32_i2c_bitbang_get_sda
 *
 * Description:
 *   Get value from SDA line
 *
 * Input Parameters:
 *   lower - A pointer the publicly visible representation of
 *           the "lower-half" driver state structure.
 *
 * Returned Value:
 *   The boolean representation of the SDA line value (true/false).
 *
 ****************************************************************************/

static bool stm32_i2c_bitbang_get_sda(struct i2c_bitbang_lower_dev_s *lower)
{
  struct stm32_i2c_bitbang_dev_s *dev =
    (struct stm32_i2c_bitbang_dev_s *)lower->priv;

  return stm32_gpioread(dev->sda_pin);
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: stm32_i2cbus_bitbang_initialize
 *
 * Description:
 *   Initialize the I2C bitbang driver. And return a unique instance of
 *   struct struct i2c_master_s. This function may be called to obtain
 *   multiple instances of the interface, each of which may be set up with
 *   a different frequency and slave address.
 *
 * Input Parameters:
 *   None
 *
 * Returned Value:
 *   Valid I2C device structure reference on success; a NULL on failure
 *
 ****************************************************************************/

struct i2c_master_s *stm32_i2cbus_bitbang_initialize(void)
{
  struct stm32_i2c_bitbang_dev_s *dev =
      (struct stm32_i2c_bitbang_dev_s *)
          kmm_malloc(sizeof(struct stm32_i2c_bitbang_dev_s));

  DEBUGASSERT(dev);

  dev->lower.ops = &g_ops;
  dev->lower.priv = dev;
  dev->scl_pin = I2C_BITBANG_SCLPIN;
  dev->sda_pin = I2C_BITBANG_SDAPIN;

  return i2c_bitbang_initialize(&dev->lower);
}
#endif /* CONFIG_STM32_I2C_BITBANG */
