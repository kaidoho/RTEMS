/*
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Copyright (C) 2019, Markus Bernd Moessner
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <rtems/bspIo.h>

#include <libchip/serial.h>

#include <bspopts.h>
#include <bsp/irq.h>
#include <bsp/usart.h>
#include <bsp/stm32f7xxxx.h>

console_tbl Console_Configuration_Ports [] = {
    {
      .sDeviceName = "/dev/console",
      .deviceType = SERIAL_CUSTOM,
      .pDeviceFns = &stm32f7xx_usart_fns,
#if    defined( STM32F7XX_ENABLE_CONSOLE_USART_1)
      .ulCtrlPort1 = (uint32_t) USART1,
      .ulCtrlPort2 = 0,
#elif  defined( STM32F7XX_ENABLE_CONSOLE_USART_2)
      .ulCtrlPort1 = (uint32_t) USART2,
      .ulCtrlPort2 = 1,
#elif  defined( STM32F7XX_ENABLE_CONSOLE_USART_3)
      .ulCtrlPort1 = (uint32_t) USART3,
      .ulCtrlPort2 = 2,
#elif  defined( STM32F7XX_ENABLE_CONSOLE_USART_4)
      .ulCtrlPort1 = (uint32_t) USART4,
      .ulCtrlPort2 = 3,
#elif  defined( STM32F7XX_ENABLE_CONSOLE_USART_5)
      .ulCtrlPort1 = (uint32_t) USART5,
      .ulCtrlPort2 = 4,
#elif  defined(  STM32F7XX_ENABLE_CONSOLE_USART_6)
      .ulCtrlPort1 = (uint32_t) USART6,
      .ulCtrlPort2 = 5,
#elif  defined( STM32F7XX_ENABLE_CONSOLE_USART_7)
      .ulCtrlPort1 = (uint32_t) USART7,
      .ulCtrlPort2 = 6,
#elif  defined( STM32F7XX_ENABLE_CONSOLE_USART_8)
      .ulCtrlPort1 = (uint32_t) USART8,
      .ulCtrlPort2 = 7,
#else
      #error "No UART port specified for console"
#endif
      .ulClock = STM32F7XX_CONSOLE_BAUDRATE,
      .ulIntVector = 0
    },

};

#define PORT_COUNT \
  (sizeof(Console_Configuration_Ports) \
    / sizeof(Console_Configuration_Ports [0]))

unsigned long Console_Configuration_Count = PORT_COUNT;

static void output_char(char c)
{
  const console_fns *con =
    Console_Configuration_Ports [Console_Port_Minor].pDeviceFns;

  con->deviceWritePolled((int) Console_Port_Minor, c);
}

BSP_output_char_function_type BSP_output_char = output_char;

BSP_polling_getchar_function_type BSP_poll_char = NULL;
