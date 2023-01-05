# MCU_final_project
This is a project about 2-way traffic light and pedestrian scramble
This system have 3 modes for traffic light: AUTO, MANUAL and TUNING (with vertical and horizontal roads)
And 4 modes for pedestrian: PED_OFF, WALK_ALLOW, BUZZER_ON and WALK_STOP

Some pinout in code:
- Horizontal road: 
  + LED_RED_1
  + LED_GREEN_1
  + LED_RED_P1 for pedestrian
  + LED_GREEN_P1
  + TIM3_CH1 for buzzer
- Vertical road:
  + LED_RED_2
  + LED_GREEN_2
  + LED_RED_P2 for pedestrian
  + LED_GREEN_P2
  + TIM3_CH2 for buzzer
 - Buttons:
  + BUTTON_MODE: change mode
  + BUTTON_SET: change current light in MANUAL mode, set current light time in TUNING mode
  + BUTTON_INC: increase light time in TUNING mode
  + BUTTON_PED: turn on/off pedestrian modes


