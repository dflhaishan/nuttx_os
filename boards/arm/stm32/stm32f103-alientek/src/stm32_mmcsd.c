/****************************************************************************
 * boards/arm/stm32/stm32f103-minimum/src/stm32_mmcsd.c
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

#include <debug.h>
#include <nuttx/config.h>
#include <nuttx/mmcsd.h>
#include <nuttx/spi/spi.h>
#include <pthread.h>
#include <sched.h>
#include <time.h>
#include <unistd.h>

#include "stm32.h"
#include "stm32f103_alientek.h"
#include "stm32_spi.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#ifdef CONFIG_DISABLE_MOUNTPOINT
#  error "SD driver requires CONFIG_DISABLE_MOUNTPOINT to be disabled"
#endif

/****************************************************************************
 * Private Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/* NOTE:  We are using a SDCard adapter/module without Card Detect pin!
 * Then we don't need to Card Detect callback here.
 */

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: stm32_mmcsd_initialize
 *
 * Description:
 *   Initialize SPI-based SD card and card detect thread.
 ****************************************************************************/

int stm32_mmcsd_initialize(int minor)
{
  struct sdio_dev_s *sdio;
  int ret;

  mcinfo("INFO: Initializing mmcsd card\n");

  sdio = sdio_initialize(minor);
  if (sdio == NULL)
    {
      mcerr("ERROR: Failed to initialize SDIO slot %d\n", minor);
      return -ENODEV;
    }

  ret = mmcsd_slotinitialize(minor, sdio);
  if (ret != OK)
    {
      mcerr("ERROR: Failed to bind SDIO to the MMC/SD driver: %d\n",
            ret);
      return ret;
    }

  sdio_mediachange(sdio, true);
  mcinfo("INFO: mmcsd card has been initialized successfully\n");
  return OK;
}
