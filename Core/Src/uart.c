#include "uart.h"

int count = 0;
int count1 = 0;
int count2 = 0;
char str[50];
UART_HandleTypeDef huart2;

void sendTimerCounter() {

	// Send current time counter of horizontal traffic lights
	if (count1 != currentCounter(0) / 100) {
		count1 = currentCounter(0) / 100;
		HAL_UART_Transmit(&huart2, str, sprintf(str, "%s%d - ", "H: ", count1), 100);

		count2 = currentCounter(1) / 100;
		HAL_UART_Transmit(&huart2, str, sprintf(str, "%s%d\r\n", "V: ", count2), 100);
	}

//	if (count2 != currentCounter(1) / 100) {
//		count2 = currentCounter(1) / 100;
//		HAL_UART_Transmit(&huart2, str, sprintf(str, "%s%d\r\n", "V: ", count2), 100);
//	}
}

void sendTimeDuration() {
	switch (mode) {
		case MAN_MODE:
			count = 0;
			break;

		case MAN_RED:
			// Send duration time of red lights
			if (count != RED_time / 1000)
			{
				count = RED_time / 1000;
				HAL_UART_Transmit(&huart2, str, sprintf(str, "%s%d\r\n", "Red = ", count), 100);
			}
			break;

		case MAN_GREEN:
			// Send duration time of green lights
			if (count != GREEN_time / 1000)
			{
				count = GREEN_time / 1000;
				HAL_UART_Transmit(&huart2, str, sprintf(str, "%s%d\r\n", "Green = ", count), 100);
			}
			break;

		case MAN_YELLOW:
			// Send duration time of yellow lights
			if (count != YELLOW_time / 1000)
			{
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

		switch (mode) {
			case INC_RED:
				// Send counter to increase duration time of red lights
				HAL_UART_Transmit(&huart2, str, sprintf(str, "%s%d\r\n", "R_inc = ", count), 100);
				break;

			case INC_GREEN:
				// Send counter to increase duration time of red lights
				HAL_UART_Transmit(&huart2, str, sprintf(str, "%s%d\r\n", "G_inc = ", count), 100);
				break;

			case INC_YELLOW:
				// Send counter to increase duration time of red lights
				HAL_UART_Transmit(&huart2, str, sprintf(str, "%s%d\r\n", "Y_inc = ", count), 100);
				break;

			default:
				break;
		}
	}
}

void sendModeNoti() {
	switch (mode) {
		case AUTO_MODE:
			HAL_UART_Transmit(&huart2, str, sprintf(str, "%s\r\n", "AUTO MODE"), 100);
			break;
		case MAN_MODE:
			HAL_UART_Transmit(&huart2, str, sprintf(str, "%s\r\n", "MANUAL MODE"), 100);
			break;
		case INC_RED:
			HAL_UART_Transmit(&huart2, str, sprintf(str, "%s\r\n", "TUNING MODE"), 100);
			break;
		case INC_GREEN:
			HAL_UART_Transmit(&huart2, str, sprintf(str, "%s\r\n", "TUNING MODE"), 100);
			break;
		case INC_YELLOW:
			HAL_UART_Transmit(&huart2, str, sprintf(str, "%s\r\n", "TUNING MODE"), 100);
			break;
		default:
			break;
	}
}

void sendSetNoti() {
	switch (mode) {
	case INC_RED:
		HAL_UART_Transmit(&huart2, str, sprintf(str, "%s\r\n", "SET RED"), 100);
		break;
	case INC_GREEN:
		HAL_UART_Transmit(&huart2, str, sprintf(str, "%s\r\n", "SET GREEN"), 100);
		break;
	case INC_YELLOW:
		HAL_UART_Transmit(&huart2, str, sprintf(str, "%s\r\n", "SET YELLOW"), 100);
		break;
		default:
			break;
	}
}
