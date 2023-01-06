#include "LEDs_display.h"

int horizontal_status = MODE_INIT;
int vertical_status = MODE_INIT;

void fsmHorLEDsRun() {
	// FSM for horizontal LEDs

	switch (horizontal_status) {
		case MODE_INIT:
			horizontal_status = AUTO_RED;
			setTimer(0, RED_time);
			break;

		case AUTO_RED:
			if (isTimerUp(0)) {
				horizontal_status = AUTO_GREEN;
				setTimer(0, GREEN_time);
			}
			break;

		case AUTO_GREEN:
			if (isTimerUp(0)) {
				horizontal_status = AUTO_YELLOW;
				setTimer(0, YELLOW_time);
			}
			break;

		case AUTO_YELLOW:
			if (isTimerUp(0)) {
				horizontal_status = AUTO_RED;
				setTimer(0, RED_time);
			}
			break;

		default:
			break;
	}
}


void fsmVerLEDsRun() {
	// FSM for vertical LEDs

	switch (vertical_status) {
		case MODE_INIT:
			vertical_status = AUTO_GREEN;
			setTimer(1, GREEN_time);
			break;

		case AUTO_RED:
			if (isTimerUp(1)) {
				vertical_status = AUTO_GREEN;
				setTimer(1, GREEN_time);
			}
			break;

		case AUTO_GREEN:
			if (isTimerUp(1)) {
				vertical_status = AUTO_YELLOW;
				setTimer(1, YELLOW_time);
			}
			break;

		case AUTO_YELLOW:
			if (isTimerUp(1)) {
				vertical_status = AUTO_RED;
				setTimer(1, RED_time);
			}
			break;

		default:
			break;
	}
}

void LEDsDisplay() {
	// Display two ways LEDs

	fsmHorLEDsRun();
	fsmVerLEDsRun();

	switch (horizontal_status) {
		case AUTO_RED:
			HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, LED_ON);
			HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, LED_OFF);
			break;

		case AUTO_GREEN:
			HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, LED_OFF);
			HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, LED_ON);
			break;

		case AUTO_YELLOW:
			HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, LED_ON);
			HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, LED_ON);
			break;

		default:
			break;
	}

	switch (vertical_status) {
		case AUTO_RED:
			HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, LED_ON);
			HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, LED_OFF);
			break;

		case AUTO_GREEN:
			HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, LED_OFF);
			HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, LED_ON);
			break;

		case AUTO_YELLOW:
			HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, LED_ON);
			HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, LED_ON);
			break;

		default:
			break;
	}
}

void resetLights() {
	horizontal_status = MODE_INIT;
	vertical_status = MODE_INIT;
}








