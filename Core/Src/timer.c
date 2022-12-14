#include "timer.h"

int timer_counter[NO_OF_TIMER];
int timer_flag[NO_OF_TIMER];

int currentCounter(int timer) {
	return timer_counter[timer];
}

int isTimerUp(int timer) {
	return (timer_flag[timer] == 1);
}

void setTimer(int timer, int duration){
	timer_counter[timer] = duration / timer_cycle;
	timer_flag[timer] = 0;
}
void timerRun(){
	for (int timer = 0; timer < NO_OF_TIMER; timer++) {
		if(timer_counter[timer] > 0){
			timer_counter[timer]--;
			if(timer_counter[timer] == 0) {
				timer_flag[timer] = 1;
			}
		}
	}
}
