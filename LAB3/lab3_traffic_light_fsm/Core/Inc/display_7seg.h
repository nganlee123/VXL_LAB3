#ifndef INC_DISPLAY_7SEG_H_
#define INC_DISPLAY_7SEG_H_

#include "main.h"

void enable_EN0(void);
void enable_EN1(void);
void enable_EN2(void);
void enable_EN3(void);

void display7SEG_Group1(int num);
//void display7SEG_Group2(int num);
void update7SEG_group1(int val1);
void update7SEG_group2(int val2);

#endif /* INC_DISPLAY_7SEG_H_ */
