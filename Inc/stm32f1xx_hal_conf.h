/* Inc/stm32f1xx_hal_conf.h - universal config for Blue Pill (STM32F103xB) */
#ifndef __STM32F1xx_HAL_CONF_H
#define __STM32F1xx_HAL_CONF_H

/* ------------- HAL Modules ------------- */
#define HAL_MODULE_ENABLED
#define HAL_RCC_MODULE_ENABLED
#define HAL_GPIO_MODULE_ENABLED
#define HAL_FLASH_MODULE_ENABLED
#define HAL_CORTEX_MODULE_ENABLED
#define HAL_DMA_MODULE_ENABLED
#define HAL_ADC_MODULE_ENABLED
#define HAL_CAN_MODULE_ENABLED
#define HAL_CEC_MODULE_ENABLED
#define HAL_CRC_MODULE_ENABLED
#define HAL_DAC_MODULE_ENABLED
#define HAL_I2C_MODULE_ENABLED
#define HAL_IWDG_MODULE_ENABLED
#define HAL_PWR_MODULE_ENABLED
#define HAL_RTC_MODULE_ENABLED
#define HAL_SPI_MODULE_ENABLED
#define HAL_TIM_MODULE_ENABLED
#define HAL_UART_MODULE_ENABLED
#define HAL_USART_MODULE_ENABLED
#define HAL_WWDG_MODULE_ENABLED

/* ------------- System Values ------------- */
#define VDD_VALUE             3300U       /* mV */
#define TICK_INT_PRIORITY     0x0FU       /* SysTick interrupt priority */

/* Oscillator values (Hz) */
#define HSE_VALUE             8000000U    /* External crystal on Blue Pill */
#define HSI_VALUE             8000000U    /* Internal RC */
#define LSE_VALUE             32768U
#define LSI_VALUE             40000U

/* Timeouts (ms) */
#define HSE_STARTUP_TIMEOUT   100U
#define LSE_STARTUP_TIMEOUT   5000U

/* ------------- Full Assert (optional) ------------- */
/* #define USE_FULL_ASSERT */

#ifdef USE_FULL_ASSERT
  #define assert_param(expr) ((expr) ? (void)0U : assert_failed((uint8_t *)__FILE__, __LINE__))
  void assert_failed(uint8_t* file, uint32_t line);
#else
  #define assert_param(expr) ((void)0U)
#endif

/* ------------- Required HAL headers ------------- */
#include "stm32f1xx_hal_rcc.h"
#include "stm32f1xx_hal_gpio.h"
#include "stm32f1xx_hal_cortex.h"
#include "stm32f1xx_hal_flash.h"
#include "stm32f1xx_hal_dma.h"
#include "stm32f1xx_hal_adc.h"
#include "stm32f1xx_hal_can.h"
#include "stm32f1xx_hal_cec.h"
#include "stm32f1xx_hal_crc.h"
#include "stm32f1xx_hal_dac.h"
#include "stm32f1xx_hal_i2c.h"
#include "stm32f1xx_hal_iwdg.h"
#include "stm32f1xx_hal_pwr.h"
#include "stm32f1xx_hal_rtc.h"
#include "stm32f1xx_hal_spi.h"
#include "stm32f1xx_hal_tim.h"
#include "stm32f1xx_hal_uart.h"
#include "stm32f1xx_hal_usart.h"
#include "stm32f1xx_hal_wwdg.h"

#endif /* __STM32F1xx_HAL_CONF_H */
