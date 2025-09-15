#ifndef UART_H
#define UART_H

#include "stm32f1xx_hal.h"
#include <stdio.h>
#include <string.h>

void uart_init(void);
void uart_send_string(char *str);
void uart_send_data(uint8_t *data, uint16_t size);
void uart_send_number(int num);

#endif