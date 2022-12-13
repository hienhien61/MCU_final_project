#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include "global.h"

int currentCounter(int timer);
int isTimerUp(int timer);
void setTimer(int timer, int duration);
void timerRun();

#endif /* INC_TIMER_H_ */
