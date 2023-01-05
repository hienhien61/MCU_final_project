#include "fsm_manual_mode.h"

void fsmManualModeRun()
{
	// FSM for MANUAL MODE

	switch (mode)
	{
	case MAN_MODE:
		sendTimeDuration();
		mode = MAN_RED;
		break;

	case MAN_RED:
		HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, LED_ON);
		HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, LED_OFF);

		HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, LED_ON);
		HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, LED_OFF);

		sendTimeDuration();

		if (isButtonPressed(BUTTON_SET))
		{
			mode = MAN_GREEN;
		}

		// Switch to TUNING MODE when press MODE button
		if (isButtonPressed(BUTTON_MODE))
		{
			mode = INC_RED;
			time_count = RED_time / 1000;
		}

		break;

	case MAN_GREEN:
		HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, LED_OFF);
		HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, LED_ON);

		HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, LED_OFF);
		HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, LED_ON);

		sendTimeDuration();

		if (isButtonPressed(BUTTON_SET))
		{
			mode = MAN_YELLOW;
		}

		// Switch to TUNING MODE when press MODE button
		if (isButtonPressed(BUTTON_MODE))
		{
			mode = INC_GREEN;
			time_count = GREEN_time / 1000;
		}

		break;

	case MAN_YELLOW:
		HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, LED_ON);
		HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, LED_ON);

		HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, LED_ON);
		HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, LED_ON);

		sendTimeDuration();

		if (isButtonPressed(BUTTON_SET))
		{
			mode = MAN_RED;
		}

		// Switch to TUNING MODE when press MODE button
		if (isButtonPressed(BUTTON_MODE))
		{
			mode = INC_YELLOW;
			time_count = YELLOW_time / 1000;
		}

		break;
	}
}
