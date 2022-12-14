#include "button.h"

int button_flag[NO_OF_BUTTON];
int button_long_flag[NO_OF_BUTTON];
GPIO_PinState key_reg[NO_OF_BUTTON][4];
int counter_for_key_pressed[NO_OF_BUTTON];

int isButtonPressed(int button) {
	if (button_flag[button]) {
		button_flag[button] = 0;
		return 1;
	}
	else return 0;
}

int isButtonLongPressed(int button) {
	if (button_long_flag[button]) {
		button_long_flag[button] = 0;
		return 1;
	}
	else return 0;
}

void subKeyProcess(int button) {
	button_flag[button] = 1;
}

void subKeyLongProcess(int button) {
	button_long_flag[button] = 1;
}

void resetKey(int button) {
	button_flag[button] = 0;
	button_long_flag[button] = 0;
}

void setKeyTimer(int button) {
	counter_for_key_pressed[button] = timer_for_key_pressed / timer_cycle;
}

void getKeyInput() {
	for (int button = 0; button < NO_OF_BUTTON; button++) {
		key_reg[button][0] = key_reg[button][1];
		key_reg[button][1] = key_reg[button][2];
		switch (button) {
			case BUTTON_MODE:
				key_reg[button][2] = HAL_GPIO_ReadPin(BUTTON_MODE_GPIO_Port, BUTTON_MODE_Pin);
				break;
			case BUTTON_SET:
				key_reg[button][2] = HAL_GPIO_ReadPin(BUTTON_SET_GPIO_Port, BUTTON_SET_Pin);
				break;
			case BUTTON_INC:
				key_reg[button][2] = HAL_GPIO_ReadPin(BUTTON_INC_GPIO_Port, BUTTON_INC_Pin);
				break;
			case BUTTON_PED:
				key_reg[button][2] = HAL_GPIO_ReadPin(BUTTON_PED_GPIO_Port, BUTTON_PED_Pin);
				break;
			default:
				break;
		}

		if ((key_reg[button][0] == key_reg[button][1]) && (key_reg[button][1] == key_reg[button][2])) {

			// Press button, then release
			if (key_reg[button][3] != key_reg[button][2]) {
				key_reg[button][3] = key_reg[button][2];

				if (key_reg[button][2] == PRESSED_STATE) {
					subKeyProcess(button);
					setKeyTimer(button);
				}
				else resetKey(button);
			}
			// Press and hold button
			else {
				counter_for_key_pressed[button]--;
				if (!counter_for_key_pressed[button]) {
					if (key_reg[button][2] == PRESSED_STATE) {
						subKeyLongProcess(button);
					}
					else resetKey(button);
					setKeyTimer(button);
				}
			}
		}
	}
}
