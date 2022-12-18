#include "fsm_tuning_mode.h"

int time_count = 0;

void fsmTuningModeRun() {
	// FSM for TUNING MODE

	switch (mode) {
		case INC_RED:
			// Switch to AUTO MODE when press MODE button
			if (isButtonPressed(BUTTON_MODE)) {
				mode = AUTO_MODE;
			}

			// Set the time duration of the red LEDs when press SET button
			if (isButtonPressed(BUTTON_SET)) {
				RED_time = time_count * 1000;
			}

			// Increase the time duration of the red LEDs when INC button is pressed or long pressed
			if (isButtonPressed(BUTTON_INC) || isButtonLongPressed(BUTTON_INC)) {
				time_count %= 100;
				time_count++;
			}

			break;

		case INC_GREEN:
			// Switch to AUTO MODE when press MODE button
			if (isButtonPressed(BUTTON_MODE)) {
				mode = AUTO_MODE;
			}

			// Set the time duration of the green LEDs when press SET button
			if (isButtonPressed(BUTTON_SET)) {
				GREEN_time = time_count * 1000;
			}

			// Increase the time duration of the green LEDs when INC button is pressed or long pressed
			if (isButtonPressed(BUTTON_INC) || isButtonLongPressed(BUTTON_INC)) {
				time_count %= 90;
				time_count++;
			}

			break;

		case INC_YELLOW:
			// Switch to AUTO MODE when press MODE button
			if (isButtonPressed(BUTTON_MODE)) {
				mode = AUTO_MODE;
			}

			// Set the time duration of the yellow LEDs when press SET button
			if (isButtonPressed(BUTTON_SET)) {
				YELLOW_time = time_count * 1000;
			}

			// Increase the time duration of the yellow LEDs when INC button is pressed or long pressed
			if (isButtonPressed(BUTTON_INC) || isButtonLongPressed(BUTTON_INC)) {
				time_count %= 10;
				time_count++;
			}

			break;

		default:
			break;
	}
}
