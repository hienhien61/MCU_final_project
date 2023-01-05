#include "fsm_pedestrian_mode.h"

TIM_HandleTypeDef htim3;

int ver_ped = PED_OFF;
int hor_ped = PED_OFF;
int buzzer_time = BUZZER_time;
int pul = BUZZER_pul;
int state = 0;

void fsmVerPedRun(){
	switch(ver_ped){
		case PED_OFF:
			//Reset buzzer
			buzzer_time = BUZZER_time;
			pul = BUZZER_pul;
			state = 0;
			//Bat che do nguoi di bo
			if(isButtonPressed(BUTTON_PED)){
				ver_ped = PED_ON;
				hor_ped = PED_ON;
			}
			break;
		case PED_ON:
			//Tat che do nguoi di bo
			if(isButtonPressed(BUTTON_PED)){
				ver_ped = PED_OFF;
				hor_ped = PED_OFF;
			}
			//Cho phep di
			if(vertical_status == AUTO_RED){
				ver_ped = WALK_ALLOW;
			}
			//Dung lai
			if((vertical_status == AUTO_GREEN) || (vertical_status == AUTO_YELLOW)){
				ver_ped = WALK_STOP;
			}
			break;
		case WALK_ALLOW:
			//Tat che do nguoi di bo
			if(isButtonPressed(BUTTON_PED)){
				ver_ped = PED_OFF;
				hor_ped = PED_OFF;
			}
			//Thoi gian con 3s -> Bat buzzer
			if(currentCounter(1) <= 3000){
				ver_ped = BUZZER_ON;
				setTimer(3, 100);
			}
			break;
		case BUZZER_ON:
			//Tat che do nguoi di bo
			if(isButtonPressed(BUTTON_PED)){
				ver_ped = PED_OFF;
				hor_ped = PED_OFF;
			}
			//Dung lai
			if(vertical_status == AUTO_GREEN){
				ver_ped = WALK_STOP;
				//Reset buzzer
				buzzer_time = BUZZER_time;
				pul = BUZZER_pul;
				state = 0;
			}
			break;
		case WALK_STOP:
			//Tat che do nguoi di bo
			if(isButtonPressed(BUTTON_PED)){
				ver_ped = PED_OFF;
				hor_ped = PED_OFF;
			}
			//Cho phep di
			if(vertical_status == AUTO_RED){
				ver_ped = WALK_ALLOW;
			}
			break;
		default:
			break;
	}
}

void fsmHorPedRun(){
	switch(hor_ped){
		case PED_OFF:
			//Reset buzzer
			buzzer_time = BUZZER_time;
			pul = BUZZER_pul;
			state = 0;
			//Bat che do nguoi di bo
			if(isButtonPressed(BUTTON_PED)){
				ver_ped = PED_ON;
				hor_ped = PED_ON;
			}
			break;
		case PED_ON:
			//Tat che do nguoi di bo
			if(isButtonPressed(BUTTON_PED)){
				ver_ped = PED_OFF;
				hor_ped = PED_OFF;
			}
			//Cho phep di
			if(horizontal_status == AUTO_RED){
				hor_ped = WALK_ALLOW;
			}
			//Dung lai
			if((horizontal_status == AUTO_GREEN) || (horizontal_status == AUTO_YELLOW)){
				hor_ped = WALK_STOP;
			}
			break;
		case WALK_ALLOW:
			//Tat che do nguoi di bo
			if(isButtonPressed(BUTTON_PED)){
				ver_ped = PED_OFF;
				hor_ped = PED_OFF;
			}
			//Thoi gian con 3s -> Bat buzzer
			if(currentCounter(0) <= 3000){
				hor_ped = BUZZER_ON;
				setTimer(2, 100);
			}
			break;
		case BUZZER_ON:
			//Tat che do nguoi di bo
			if(isButtonPressed(BUTTON_PED)){
				ver_ped = PED_OFF;
				hor_ped = PED_OFF;
			}
			//Dung lai
			if(horizontal_status == AUTO_GREEN){
				hor_ped = WALK_STOP;
				//Reset buzzer
				buzzer_time = BUZZER_time;
				pul = BUZZER_pul;
				state = 0;
			}
			break;
		case WALK_STOP:
			//Tat che do nguoi di bo
			if(isButtonPressed(BUTTON_PED)){
				ver_ped = PED_OFF;
				hor_ped = PED_OFF;
			}
			//Cho phep di
			if(horizontal_status == AUTO_RED){
				hor_ped = WALK_ALLOW;
			}
			break;
		default:
			break;
	}
}

void fsmPedestrianModeRun() {
	fsmVerPedRun();
	fsmHorPedRun();

	switch(ver_ped){
		case PED_OFF:
			HAL_GPIO_WritePin(LED_RED_P2_GPIO_Port, LED_RED_P2_Pin, LED_OFF);
			HAL_GPIO_WritePin(LED_GREEN_P2_GPIO_Port, LED_GREEN_P2_Pin, LED_OFF);
			__HAL_TIM_SetCompare (&htim3, TIM_CHANNEL_2, 0);
			break;
		case PED_ON:
			break;
		case WALK_ALLOW:
			HAL_GPIO_WritePin(LED_RED_P2_GPIO_Port, LED_RED_P2_Pin, LED_OFF);
			HAL_GPIO_WritePin(LED_GREEN_P2_GPIO_Port, LED_GREEN_P2_Pin, LED_ON);
			break;
		case BUZZER_ON:
			//Buzzer se to dan va nhanh hon khi thoi gian gan het
			if(isTimerUp(3) && state == 1){
				__HAL_TIM_SetCompare (&htim3, TIM_CHANNEL_2, pul);
				setTimer(3, buzzer_time);
				state = 1 - state;
				if(pul < 950) pul += 100;
				if(buzzer_time > 100) buzzer_time -= 100;
			}
			if(isTimerUp(3) && state == 0){
				__HAL_TIM_SetCompare (&htim3, TIM_CHANNEL_2, 0);
				setTimer(3, buzzer_time);
				state = 1 - state;
				if(pul < 950) pul += 100;
				if(buzzer_time > 100) buzzer_time -= 100;
			}
			break;
		case WALK_STOP:
			HAL_GPIO_WritePin(LED_RED_P2_GPIO_Port, LED_RED_P2_Pin, LED_ON);
			HAL_GPIO_WritePin(LED_GREEN_P2_GPIO_Port, LED_GREEN_P2_Pin, LED_OFF);
			__HAL_TIM_SetCompare (&htim3, TIM_CHANNEL_2, 0);
			break;
		default:
			break;
	}

	switch(hor_ped){
		case PED_OFF:
			HAL_GPIO_WritePin(LED_RED_P1_GPIO_Port, LED_RED_P1_Pin, LED_OFF);
			HAL_GPIO_WritePin(LED_GREEN_P1_GPIO_Port, LED_GREEN_P1_Pin, LED_OFF);
			__HAL_TIM_SetCompare (&htim3, TIM_CHANNEL_1, 0);
			break;
		case PED_ON:
			break;
		case WALK_ALLOW:
			HAL_GPIO_WritePin(LED_RED_P1_GPIO_Port, LED_RED_P1_Pin, LED_OFF);
			HAL_GPIO_WritePin(LED_GREEN_P1_GPIO_Port, LED_GREEN_P1_Pin, LED_ON);
			break;
		case BUZZER_ON:
			//Buzzer se to dan va nhanh hon khi thoi gian gan het
			if(isTimerUp(2) && state == 1){
				__HAL_TIM_SetCompare (&htim3, TIM_CHANNEL_1, pul);
				setTimer(2, buzzer_time);
				state = 1 - state;
				if(pul < 950) pul += 100;
				if(buzzer_time > 100) buzzer_time -= 100;
			}
			if(isTimerUp(2) && state == 0){
				__HAL_TIM_SetCompare (&htim3, TIM_CHANNEL_1, 0);
				setTimer(2, buzzer_time);
				state = 1 - state;
				if(pul < 950) pul += 100;
				if(buzzer_time > 100) buzzer_time -= 100;
			}
			break;
		case WALK_STOP:
			HAL_GPIO_WritePin(LED_RED_P1_GPIO_Port, LED_RED_P1_Pin, LED_ON);
			HAL_GPIO_WritePin(LED_GREEN_P1_GPIO_Port, LED_GREEN_P1_Pin, LED_OFF);
			__HAL_TIM_SetCompare (&htim3, TIM_CHANNEL_1, 0);
			break;
		default:
			break;
	}


}
