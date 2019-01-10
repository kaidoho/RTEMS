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

#include <libchip/sersupp.h>

#include <bsp.h>
#include <bsp/irq.h>
#include <bsp/usart.h>
#include <bsp/stm32f7xxxx.h>
#include <stm32f7xx.h>
#include <stm32f7xx_hal.h>
UART_HandleTypeDef ConsoleUart;

static void usart_initialize(int minor)
{
	ConsoleUart.Instance        	= USART2;
	ConsoleUart.Init.BaudRate   	= 115200;
	ConsoleUart.Init.WordLength 	= UART_WORDLENGTH_8B;
  ConsoleUart.Init.StopBits   	= UART_STOPBITS_1;
  ConsoleUart.Init.Parity     	= UART_PARITY_NONE;
  ConsoleUart.Init.HwFlowCtl  	= UART_HWCONTROL_NONE;
  ConsoleUart.Init.Mode       	= UART_MODE_TX_RX;
  ConsoleUart.Init.OverSampling = UART_OVERSAMPLING_16;

  if (HAL_UART_Init(&ConsoleUart) != HAL_OK)
  {

  }

}

static int usart_first_open(int major, int minor, void *arg)
{
  return 0;
}

static int usart_last_close(int major, int minor, void *arg)
{
  return 0;
}

static int usart_read_polled(int minor)
{
  return -1;
}

static void usart_write_polled(int minor, char c)
{

	if(HAL_UART_STATE_RESET == ConsoleUart.gState)
	{
		usart_initialize(minor);
	}
	HAL_UART_Transmit(&ConsoleUart, (uint8_t *)&c, 1, 0xFFFF);

  return;
}

static ssize_t usart_write_support_polled(
  int minor,
  const char *s,
  size_t n
)
{
  return n;
}

static int usart_set_attributes(int minor, const struct termios *term)
{
  return -1;
}

const console_fns stm32f7xx_usart_fns = {
  .deviceProbe = libchip_serial_default_probe,
  .deviceFirstOpen = usart_first_open,
  .deviceLastClose = usart_last_close,
  .deviceRead = usart_read_polled,
  .deviceWrite = usart_write_support_polled,
  .deviceInitialize = usart_initialize,
  .deviceWritePolled = usart_write_polled,
  .deviceSetAttributes = usart_set_attributes,
  .deviceOutputUsesInterrupts = false
};
