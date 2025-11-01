#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "main.h"

#define TIMER_CYCLE 10 // ms

extern int timer0_flag, timer1_flag, timer2_flag, timer3_flag, timer4_flag; //timer5_flag;
void setTimer0(int duration);
void setTimer1(int duration);
void setTimer2(int duration);
void setTimer3(int duration);
void setTimer4(int duration);
//void setTimer5(int duration);

void timerRun(void);

#endif /* INC_SOFTWARE_TIMER_H_ */
