#include "fsm_manual_mode.h"

void fsmManualModeRun() {
	// FSM for MANUAL MODE

	switch (mode){
		case MAN_MODE:
			mode = MAN_RED;
			break;

		case MAN_RED:
			manRedDisplay();

			if (isButtonPressed(BUTTON_SET)) {
				mode = MAN_GREEN;
			}

			// Switch to TUNING MODE when press MODE button
			if (isButtonPressed(BUTTON_MODE)) {
				mode = INC_RED;
			}
			break;

		case MAN_GREEN:
			manGreenDisplay();

			if (isButtonPressed(BUTTON_SET)) {
				mode = MAN_YELLOW;
			}

			// Switch to TUNING MODE when press MODE button
			if (isButtonPressed(BUTTON_MODE)) {
				mode = INC_GREEN;
			}
			break;

		case MAN_YELLOW:
			manYellowDisplay();

			if (isButtonPressed(BUTTON_SET)) {
				mode = MAN_RED;
			}

			// Switch to TUNING MODE when press MODE button
			if (isButtonPressed(BUTTON_MODE)) {
				mode = INC_YELLOW;
			}
			break;
	}
}
