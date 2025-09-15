#include "uart.h"

UART_HandleTypeDef huart1; // Global handle for UART1

void uart_init(void)
{
    // Enable UART1 clock
    __HAL_RCC_USART1_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();

    // -------------------- GPIO CONFIG --------------------
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    // PA9 -> TX
    GPIO_InitStruct.Pin = GPIO_PIN_9;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    // PA10 -> RX
    GPIO_InitStruct.Pin = GPIO_PIN_10;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    // -------------------- UART CONFIG --------------------
    huart1.Instance = USART1;
    huart1.Init.BaudRate = 115200;
    huart1.Init.WordLength = UART_WORDLENGTH_8B;
    huart1.Init.StopBits = UART_STOPBITS_1;
    huart1.Init.Parity = UART_PARITY_NONE;
    huart1.Init.Mode = UART_MODE_TX_RX;
    huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart1.Init.OverSampling = UART_OVERSAMPLING_16;

    if (HAL_UART_Init(&huart1) != HAL_OK)
    {
        // Error handling
        while (1);
    }
}

void uart_send_string(char *str)
{
    HAL_UART_Transmit(&huart1, (uint8_t*)str, strlen(str), HAL_MAX_DELAY);
}

void uart_send_data(uint8_t *data, uint16_t size)
{
    HAL_UART_Transmit(&huart1, data, size, HAL_MAX_DELAY);
}

void uart_send_number(int num)
{
    char buffer[20];
    sprintf(buffer, "%d", num);
    uart_send_string(buffer);
}