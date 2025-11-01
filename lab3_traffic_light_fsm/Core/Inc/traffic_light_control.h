#ifndef INC_TRAFFIC_LIGHT_CONTROL_H_
#define INC_TRAFFIC_LIGHT_CONTROL_H_

#include "main.h"

#define RED    0
#define YELLOW  1
#define GREEN  2

void setRoad1(int color);
void setRoad2(int color);

void blink_leds(int color);

#endif /* INC_TRAFFIC_LIGHT_CONTROL_H_ */
