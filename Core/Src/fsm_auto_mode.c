#include "fsm_auto_mode.h"

void fsmAutoModeRun() {
	// FSM for AUTO MODE

	switch (mode) {
		case MODE_INIT:
			mode = AUTO_MODE;
			resetLights();
			sendModeNoti();
			break;

		case AUTO_MODE:
			// Switch to MANUAL MODE when press MODE button
			if (isButtonPressed(BUTTON_MODE)) {
				mode = MAN_MODE;
				sendModeNoti();
			}

			// Display single LEDs according to the traffic rules
			LEDsDisplay();
			sendTimerCounter();

			break;

		default:
			break;
	}
}
