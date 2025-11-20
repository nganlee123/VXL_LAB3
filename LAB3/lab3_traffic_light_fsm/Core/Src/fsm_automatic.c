#include "fsm_automatic.h"
#include "software_timer.h"
#include "main.h"
#include "display_7seg.h"
#include "traffic_light_control.h"

int red_time = 7;
int yellow_time = 2;
int green_time = 5;

AutoState auto_state = INIT;

int counter1 = 0;
int counter2 = 0;

void fsm_automatic_run(void){
    switch(auto_state){
    case INIT:
        auto_state = RED_GREEN;
        break;

    case RED_GREEN:
        if(timer3_flag){
            setRoad1(RED);
            setRoad2(GREEN);
            counter1 = red_time;
            counter2 = green_time;
            auto_state = RED_YELLOW;
            setTimer3(green_time*1000);
            setTimer4(1000);
        }
        break;

    case RED_YELLOW:
        if(timer3_flag){
            setRoad1(RED);
            setRoad2(YELLOW);
            counter1 = yellow_time;
            counter2 = yellow_time;
            auto_state = GREEN_RED;
            setTimer3(yellow_time*1000);
            setTimer4(1000);
        }
        break;

    case GREEN_RED:
        if(timer3_flag){
            setRoad1(GREEN);
            setRoad2(RED);
            counter1 = green_time;
            counter2 = red_time;
            auto_state = YELLOW_RED;
            setTimer3(green_time*1000);
            setTimer4(1000);
        }
        break;

    case YELLOW_RED:
        if(timer3_flag){
            setRoad1(YELLOW);
            setRoad2(RED);
            counter1 = yellow_time;
            counter2 = yellow_time;
            auto_state = RED_GREEN;
            setTimer3(yellow_time*1000);
            setTimer4(1000);
        }
        break;
    }

    if(timer2_flag){
        timer2_flag = 0;
        update7SEG_group1(counter1);
        update7SEG_group2(counter2);
        setTimer2(100);  //scan 100ms
    }
    /*
    if(timer5_flag){
        timer5_flag = 0;
        update7SEG_group2(counter2);
        setTimer5(500);
    }*/

    if(timer4_flag){
        if(counter1 > 0) counter1--;
        if(counter2 > 0) counter2--;
        setTimer4(1000);
    }

	//update7SEG(counter1, counter2);
}
