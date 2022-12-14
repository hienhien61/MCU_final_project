#include "fsm_auto_mode.h"

void fsmAutoModeRun() {
	// FSM for AUTO MODE

	switch (mode) {
		case MODE_INIT:
			mode = AUTO_MODE;
			break;

		case AUTO_MODE:
			// Switch to MANUAL MODE when press MODE button
			if (isButtonPressed(BUTTON_MODE)) {
				mode = MAN_MODE;
			}

			// Display single LEDs according to the traffic rules
			LEDsDisplay();

			break;

		default:
			break;
	}
}
