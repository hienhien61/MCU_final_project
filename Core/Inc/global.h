#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "timer.h"
#include "button.h"
#include "LEDs_display.h"
#include "fsm_auto_mode.h"
#include "fsm_manual_mode.h"
#include "fsm_tuning_mode.h"
#include "fsm_pedestrian_mode.h"
#include "uart.h"

/* Define for TIMER ----------------------------*/
// Timer0 for horizontal LEDs, Timer1 for vertical LEDs,
// Timer2 for horizontal buzzer, Timer3 for vertical buzzer
#define NO_OF_TIMER				4

/* Define for BUTTON ---------------------------*/
#define NO_OF_BUTTON			4

#define BUTTON_MODE				0
#define BUTTON_SET				1
#define BUTTON_INC				2
#define BUTTON_PED				3

#define NORMAL_STATE			GPIO_PIN_SET
#define PRESSED_STATE			GPIO_PIN_RESET

/* Define for AUTO MODE ------------------------*/
#define MODE_INIT				0
#define AUTO_MODE				1
#define AUTO_RED				2
#define AUTO_GREEN				3
#define AUTO_YELLOW				4

/* Define for MANUAL MODE ----------------------*/
#define MAN_MODE				5
#define MAN_RED					6
#define MAN_GREEN				7
#define MAN_YELLOW				8

/* Define for TUNING MODE ----------------------*/
#define INC_RED					9
#define INC_GREEN				10
#define INC_YELLOW				11

/* Define for PEDESTRIAN MODE ------------------*/
#define PED_OFF					12
#define PED_ON					13
#define WALK_ALLOW				14
#define BUZZER_ON				15
#define WALK_STOP				16

/* Define for LEDs -----------------------------*/
#define LED_ON					GPIO_PIN_SET
#define LED_OFF					GPIO_PIN_RESET

/* Define for Buzzer ---------------------------*/
#define BUZZER_time				500
#define BUZZER_pul				550

/* Global Variables ----------------------------*/
extern int timer_cycle;
extern int timer_for_key_pressed;

extern int mode;

extern int RED_time;
extern int GREEN_time;
extern int YELLOW_time;

#endif /* INC_GLOBAL_H_ */
