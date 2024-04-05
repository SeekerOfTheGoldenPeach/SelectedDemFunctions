#include "logger.h"

extern UART_HandleTypeDef huart3;

void logger(const char *message)
{
  char buffer[128];
  sprintf(buffer, message);
  HAL_UART_Transmit(&huart3, (uint8_t *)message, strlen(message), 50);
  HAL_Delay(50);
}