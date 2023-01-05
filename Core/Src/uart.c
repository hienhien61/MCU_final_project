#include "uart.h"

int count = 0;
int count1 = 0;
int count2 = 0;
char str[50];
UART_HandleTypeDef huart2;

void sendTimerCounter() {
	if (count1 != currentCounter(0) / 100) {
	  count1 = currentCounter(0) / 100;
	  HAL_UART_Transmit(&huart2, str, sprintf(str, "%s%d\r\n", "H: ", count1), 100);
	}

	else if (count2 != currentCounter(1) / 100) {
	  count2 = currentCounter(1) / 100;
	  HAL_UART_Transmit(&huart2, str, sprintf(str, "%s%d\r\n", "V: ", count2), 100);
	}
}

void sendTimeDuration() {
	switch (mode) {
		case MAN_MODE:
			count = 0;
			break;

		case MAN_RED:
			if (count != RED_time / 1000) {
				count = RED_time / 1000;
				HAL_UART_Transmit(&huart2, str, sprintf(str, "%s%d\r\n", "Red = ", count), 100);
			}
			break;

		case MAN_GREEN:
			if (count != GREEN_time / 1000) {
				count = GREEN_time / 1000;
				HAL_UART_Transmit(&huart2, str, sprintf(str, "%s%d\r\n", "Green = ", count), 100);
			}
			break;

		case MAN_YELLOW:
			if (count != YELLOW_time / 1000) {
				count = YELLOW_time / 1000;
				HAL_UART_Transmit(&huart2, str, sprintf(str, "%s%d\r\n", "Yellow = ", count), 100);
			}
			break;

		default:
			break;
	}
}

void sendTimeInc() {
	if (count != time_count) {
		count = time_count;
		HAL_UART_Transmit(&huart2, str, sprintf(str, "%d\r\n", count), 100);
	}
}
