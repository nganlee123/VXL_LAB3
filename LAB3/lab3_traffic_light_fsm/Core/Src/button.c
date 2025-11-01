#include "button.h"

#define NUM_BUTTON	3

int KeyReg0 [NUM_BUTTON];
int KeyReg1 [NUM_BUTTON];
int KeyReg2 [NUM_BUTTON];

int KeyReg3 [NUM_BUTTON];
int TimeForPress [NUM_BUTTON];
int button_flag [NUM_BUTTON];

GPIO_TypeDef* BUTTON_PORT[NUM_BUTTON] = {BUTTON1_GPIO_Port, BUTTON2_GPIO_Port, BUTTON3_GPIO_Port};
uint16_t BUTTON_PIN[NUM_BUTTON] = {BUTTON1_Pin, BUTTON2_Pin, BUTTON3_Pin};


int isButtonPressed(int index)
{
	if (button_flag [index] == 1)
	{
		button_flag [index] = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess(int index)
{
	button_flag [index] = 1;
}

void getKeyInput()
{
    for (int i = 0; i < NUM_BUTTON; i++)
    {
        KeyReg0[i] = KeyReg1[i];
        KeyReg1[i] = KeyReg2[i];
        KeyReg2[i] = HAL_GPIO_ReadPin(BUTTON_PORT[i], BUTTON_PIN[i]);

        if ((KeyReg0[i] == KeyReg1[i]) && (KeyReg1[i] == KeyReg2[i]))
        {
            if (KeyReg3[i] != KeyReg2[i])
            {
                KeyReg3[i] = KeyReg2[i];
                if (KeyReg2[i] == PRESSED_STATE)
                {
                    subKeyProcess(i);
                    TimeForPress[i] = 200;
                }
            }
            else
            {
                // handle long-press
                TimeForPress[i]--;
                if (TimeForPress[i] == 0)
                {
                    if (KeyReg2[i] == PRESSED_STATE)
                    {
                        subKeyProcess(i); // repeat the action
                    }
                    TimeForPress[i] = 200;
                }
            }
        }
    }
}


