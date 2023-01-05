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
				if (time_count >= 99) time_count = 5;
				else time_count++;
			}

			sendTimeInc();

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
				if (time_count >= 89) time_count = 3;
				else time_count++;
			}

			sendTimeInc();

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
				if (time_count >= 10) time_count = 2;
				else time_count++;
			}

			sendTimeInc();

			break;

		default:
			break;
	}
}
