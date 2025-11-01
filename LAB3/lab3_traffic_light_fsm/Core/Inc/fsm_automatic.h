#ifndef INC_FSM_AUTOMATIC_H_
#define INC_FSM_AUTOMATIC_H_

#include "main.h"

#define RED    0
#define YELLOW  1
#define GREEN  2

extern int red_time;
extern int yellow_time;
extern int green_time;

typedef enum {INIT, RED_GREEN, RED_YELLOW, GREEN_RED, YELLOW_RED} AutoState;
extern AutoState auto_state;

void fsm_automatic_run(void);

#endif /* INC_FSM_AUTOMATIC_H_ */
