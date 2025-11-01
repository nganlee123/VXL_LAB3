#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#include "main.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET


void getKeyInput();
int isButtonPressed(int index);

#endif /* INC_BUTTON_H_ */
