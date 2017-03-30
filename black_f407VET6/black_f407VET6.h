/******************************************************************************
 * The MIT License
 *
 * Copyright (c) 2011 LeafLabs, LLC.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *****************************************************************************/

/**
 * @file   black_f407VET6.h, was aeroquad32.h
 * @author Marti Bolivar <mbolivar@leaflabs.com>
 * @brief  Private include file for Maple Native in boards.h
 *
 * See maple.h for more information on these definitions.
 */

#ifndef _BOARD_BLACKVET6_F4_H_
#define _BOARD_BLACKVET6_F4_H_

#define Port2Pin(port, bit) ((port-'A')*16+bit)

#define CYCLES_PER_MICROSECOND  168


#undef  STM32_PCLK1
#undef  STM32_PCLK2
#define STM32_PCLK1   (CYCLES_PER_MICROSECOND*1000000/4)
#define STM32_PCLK2   (CYCLES_PER_MICROSECOND*1000000/2)

#define SYSTICK_RELOAD_VAL      (CYCLES_PER_MICROSECOND*1000-1)

#define BOARD_LED_PIN           Port2Pin('A', 6) // also A5
#define BOARD_BUTTON_PIN        Port2Pin('A', 0) // Sys_WKUP button

// ONBOARD HARDWARE: PORT USE
// SDIO uses PC8-12, PD2
// WINBOND FLASH MEMORY USES SPI1 ON PB3-5 + CS ON PB14
// STLINK USES: SWDIO = PA13, SWCLK = PA14

#define BOARD_NR_USARTS         3				// 5 really, but UART4 and UART5 conflict with SDIO pins
#define BOARD_USART1_TX_PIN     Port2Pin('A', 9) // disable - USB
#define BOARD_USART1_RX_PIN     Port2Pin('A',10)

#define BOARD_USART2_TX_PIN     Port2Pin('D', 5) // remapped PA2 or PD5
#define BOARD_USART2_RX_PIN     Port2Pin('D', 6) // PA3 or PD6

#define BOARD_USART3_TX_PIN     Port2Pin('D', 8)
#define BOARD_USART3_RX_PIN     Port2Pin('D', 9)
/**/
#define BOARD_UART4_TX_PIN      Port2Pin('C',10) // disable - SDIO uses PC8-PC12, PD2
#define BOARD_UART4_RX_PIN      Port2Pin('C',11)

#define BOARD_UART5_TX_PIN      Port2Pin('C',12)  // disable - SDIO
#define BOARD_UART5_RX_PIN      Port2Pin('D', 2)


#define BOARD_NR_SPI            2 // SPI3 deisabled due to conflicts with SDIO

// WINBOND FLASH MEMORY USES SPI1
// CS = B14, NSS UNUSED
#define BOARD_SPI1_NSS_PIN      Port2Pin('A', 4) // conflict if using DAC1
#define BOARD_SPI1_MOSI_PIN     Port2Pin('B', 5) // forced by SDIO
#define BOARD_SPI1_MISO_PIN     Port2Pin('B', 4)
#define BOARD_SPI1_SCK_PIN      Port2Pin('B', 3)

#define BOARD_SPI2_NSS_PIN      Port2Pin('C',2) // 
#define BOARD_SPI2_MOSI_PIN     Port2Pin('C',3) // remapped from PB14, PB15 for TIM12
#define BOARD_SPI2_MISO_PIN     Port2Pin('C',2) 
#define BOARD_SPI2_SCK_PIN      Port2Pin('B',13)

#define BOARD_SPI3_NSS_PIN      Port2Pin('A',15) 
#define BOARD_SPI3_MOSI_PIN     Port2Pin('B', 5)
#define BOARD_SPI3_MISO_PIN     Port2Pin('B', 4)
#define BOARD_SPI3_SCK_PIN      Port2Pin('B', 3)

/*Do not use if using SDIO */
#define BOARD_SPI3B_NSS_PIN      Port2Pin('B', 8) 
#define BOARD_SPI3B_MOSI_PIN     Port2Pin('C',12)
#define BOARD_SPI3B_MISO_PIN     Port2Pin('C',11)
#define BOARD_SPI3B_SCK_PIN      Port2Pin('C',10)


#define BOARD_NR_GPIO_PINS      80
#define BOARD_NR_PWM_PINS       22
#define BOARD_NR_ADC_PINS       16
#define BOARD_NR_USED_PINS      24 // ??
#define BOARD_JTMS_SWDIO_PIN    Port2Pin('A',13)
#define BOARD_JTCK_SWCLK_PIN    Port2Pin('A',14)
#define BOARD_JTDI_PIN          Port2Pin('A',15)
#define BOARD_JTDO_PIN          Port2Pin('B', 3) // sdio conflict
#define BOARD_NJTRST_PIN        Port2Pin('B', 4) // sdio conflict


enum {
PA0,PA1,PA2,PA3,PA4,PA5,PA6,PA7,PA8,PA9,PA10,PA11,PA12,PA13,PA14,PA15,
PB0,PB1,PB2,PB3,PB4,PB5,PB6,PB7,PB8,PB9,PB10,PB11,PB12,PB13,PB14,PB15,
PC0,PC1,PC2,PC3,PC4,PC5,PC6,PC7,PC8,PC9,PC10,PC11,PC12,PC13,PC14,PC15,
PD0,PD1,PD2,PD3,PD4,PD5,PD6,PD7,PD8,PD9,PD10,PD11,PD12,PD13,PD14,PD15,
PE0,PE1,PE2,PE3,PE4,PE5,PE6,PE7,PE8,PE9,PE10,PE11,PE12,PE13,PE14,PE15

};

#endif
