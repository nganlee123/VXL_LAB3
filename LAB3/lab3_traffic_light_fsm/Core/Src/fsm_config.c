#include "fsm_config.h"
#include "button.h"
#include "software_timer.h"
#include "fsm_automatic.h"
#include "display_7seg.h"
#include "main.h"
#include "traffic_light_control.h"


#define AUTO		1
#define SET_RED		2
#define SET_YELLOW	3
#define SET_GREEN	4

int mode = AUTO;
//int temp_time = 0;
int temp_red = 0;
int temp_yellow = 0;
int temp_green = 0;

#define DEFAULT_RED 7
#define DEFAULT_YELLOW 2
#define DEFAULT_GREEN 5

void fsm_config(void){
	if(isButtonPressed(0)){
		mode++;
		if(mode > 4)
		{
			mode = 1;
			auto_state = INIT;

			if (red_time != yellow_time + green_time) {
				red_time = DEFAULT_RED;
				yellow_time = DEFAULT_YELLOW;
				green_time = DEFAULT_GREEN;
			}
		}
	}
	switch(mode){
	case AUTO:
		fsm_automatic_run();
		temp_red = 0;
		temp_yellow = 0;
		temp_green = 0;
		break;
	case SET_RED: // Config RED
		blink_leds(RED);
		if(isButtonPressed(1))
		{
			temp_red++;
			//temp_time = temp_red;
		}
		if(temp_red>99) temp_red=1;
		if(isButtonPressed(2))
		{
			red_time = temp_red;
			//temp_red = 0;
		}
		break;
	case SET_YELLOW: // Config YELLOW
		blink_leds(YELLOW);
		if(isButtonPressed(1))
		{
			temp_yellow++;
			//temp_time = temp_yellow;
		}
		if(temp_yellow>99) temp_yellow=1;
		if(isButtonPressed(2))
		{
			yellow_time = temp_yellow;
			//temp_yellow = 0;
		}
		break;
	case SET_GREEN: // Config GREEN
		blink_leds(GREEN);
		if(isButtonPressed(1))
		{
			temp_green++;
			//temp_time = temp_green;
		}
		if(temp_green>99) temp_green=1;
		if(isButtonPressed(2))
		{
			green_time = temp_green;
			//temp_green = 0;
		}
		break;
	}
    if(timer2_flag){
        timer2_flag = 0;
        if (mode!=AUTO){
        	switch(mode){
    			case SET_RED:
    				update7SEG_group1(temp_red);
    				break;
    			case SET_YELLOW:
    				update7SEG_group1(temp_yellow);
    				break;
    			case SET_GREEN:
    				update7SEG_group1(temp_green);
    				break;
        	}
            //update7SEG_group1(temp_time);
            update7SEG_group2(mode);
        }
        setTimer2(100);		//scan 100ms
    }
}
