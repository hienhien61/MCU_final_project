#ifndef INC_UART_H_
#define INC_UART_H_

#include "global.h"
#include <stdio.h>

extern UART_HandleTypeDef huart2;

void sendTimerCounter();
void sendTimeDuration();
void sendTimeInc();
void sendModeNoti();
void sendSetNoti();

#endif /* INC_UART_H_ */
