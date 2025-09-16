#include "stm32f1xx_hal.h"
#include "uart.h"

// Forward declaration
void SystemClock_Config(void);

int main(void)
{
    // Initialize the HAL library (sets up SysTick, NVIC, etc.)
    HAL_Init();

    // Configure system clock
    SystemClock_Config();

    // Initialize UART
    uart_init();

    // Send a welcome message
    uart_send_string("Hello from STM32 UART!\r\n");

    // Main loop
    while (1)
    {
        uart_send_string("Looping...\r\n");
        HAL_Delay(1000); // 1 sec delay
    }
}

