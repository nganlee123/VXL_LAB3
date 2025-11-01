#include "display_7seg.h"
#include "main.h"


void enable_EN0(void){
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
}

void enable_EN1(void){
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
}

void enable_EN2(void){
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
}

void enable_EN3(void){
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
}

int index_led = 0;

void display7SEG_Group1(int num){
	  if (num < 0 || num > 9) 	return;

	  //OFF ALL
	  HAL_GPIO_WritePin(LED7_a1_GPIO_Port, LED7_a1_Pin, SET);
	  HAL_GPIO_WritePin(LED7_b1_GPIO_Port, LED7_b1_Pin, SET);
	  HAL_GPIO_WritePin(LED7_c1_GPIO_Port, LED7_c1_Pin, SET);
	  HAL_GPIO_WritePin(LED7_d1_GPIO_Port, LED7_d1_Pin, SET);
	  HAL_GPIO_WritePin(LED7_e1_GPIO_Port, LED7_e1_Pin, SET);
	  HAL_GPIO_WritePin(LED7_f1_GPIO_Port, LED7_f1_Pin, SET);
	  HAL_GPIO_WritePin(LED7_g1_GPIO_Port, LED7_g1_Pin, SET);

	  //ON
	  if(num!=1 && num!=4)
		  HAL_GPIO_WritePin(LED7_a1_GPIO_Port, LED7_a1_Pin, RESET);
	  if(num!=5 && num!=6)
		  HAL_GPIO_WritePin(LED7_b1_GPIO_Port, LED7_b1_Pin, RESET);
	  if(num!=2)
		  HAL_GPIO_WritePin(LED7_c1_GPIO_Port, LED7_c1_Pin, RESET);
	  if(num!=1 && num!=4 && num!=7)
		  HAL_GPIO_WritePin(LED7_d1_GPIO_Port, LED7_d1_Pin, RESET);
	  if(num!=1 && num!=3 && num!=4 && num!=5 && num!=7 && num!=9)
		  HAL_GPIO_WritePin(LED7_e1_GPIO_Port, LED7_e1_Pin, RESET);
	  if(num!=1 && num!=2 && num!=3 && num!=7)
		  HAL_GPIO_WritePin(LED7_f1_GPIO_Port, LED7_f1_Pin, RESET);
	  if(num!=1 && num!=7 && num!=0)
		  HAL_GPIO_WritePin(LED7_g1_GPIO_Port, LED7_g1_Pin, RESET);
}

void display7SEG_Group2(int num){
	  if (num < 0 || num > 9) 	return;

	  //OFF ALL
	  HAL_GPIO_WritePin(LED7_a2_GPIO_Port, LED7_a2_Pin, SET);
	  HAL_GPIO_WritePin(LED7_b2_GPIO_Port, LED7_b2_Pin, SET);
	  HAL_GPIO_WritePin(LED7_c2_GPIO_Port, LED7_c2_Pin, SET);
	  HAL_GPIO_WritePin(LED7_d2_GPIO_Port, LED7_d2_Pin, SET);
	  HAL_GPIO_WritePin(LED7_e2_GPIO_Port, LED7_e2_Pin, SET);
	  HAL_GPIO_WritePin(LED7_f2_GPIO_Port, LED7_f2_Pin, SET);
	  HAL_GPIO_WritePin(LED7_g2_GPIO_Port, LED7_g2_Pin, SET);

	  //ON
	  if(num!=1 && num!=4)
		  HAL_GPIO_WritePin(LED7_a2_GPIO_Port, LED7_a2_Pin, RESET);
	  if(num!=5 && num!=6)
		  HAL_GPIO_WritePin(LED7_b2_GPIO_Port, LED7_b2_Pin, RESET);
	  if(num!=2)
		  HAL_GPIO_WritePin(LED7_c2_GPIO_Port, LED7_c2_Pin, RESET);
	  if(num!=1 && num!=4 && num!=7)
		  HAL_GPIO_WritePin(LED7_d2_GPIO_Port, LED7_d2_Pin, RESET);
	  if(num!=1 && num!=3 && num!=4 && num!=5 && num!=7 && num!=9)
		  HAL_GPIO_WritePin(LED7_e2_GPIO_Port, LED7_e2_Pin, RESET);
	  if(num!=1 && num!=2 && num!=3 && num!=7)
		  HAL_GPIO_WritePin(LED7_f2_GPIO_Port, LED7_f2_Pin, RESET);
	  if(num!=1 && num!=7 && num!=0)
		  HAL_GPIO_WritePin(LED7_g2_GPIO_Port, LED7_g2_Pin, RESET);
}

/*
void update7SEG_group1(int val1, int val2){
	static int led_index = 0;
	int dig1 = val1 / 10;
	int dig2 = val1 % 10;
	int dig3 = val2 / 10;
	int dig4 = val2 % 10;

	switch(led_index){
	case 0:
		enable_EN0();
		display7SEG_Group1(dig1);
		break;
	case 1:
		enable_EN1();
		display7SEG_Group1(dig2);
		break;
	case 2:
		enable_EN2();
		display7SEG_Group2(dig3);
		break;
	case 3:
		enable_EN3();
		display7SEG_Group2(dig4);
		break;
	}
	led_index = (led_index + 1) % 4;
}*/

void update7SEG_group1(int val1){
	static int led_index = 0;
	int dig1 = val1 / 10;
	int dig2 = val1 % 10;

	switch(led_index){
	case 0:
		enable_EN0();
		display7SEG_Group1(dig1);
		led_index=1;
		break;
	case 1:
		enable_EN1();
		display7SEG_Group1(dig2);
		led_index=0;
		break;
	}
}

void update7SEG_group2(int val2){
	static int led_index = 2;
	int dig3 = val2 / 10;
	int dig4 = val2 % 10;

	switch(led_index){
	case 2:
		enable_EN2();
		display7SEG_Group2(dig3);
		led_index=3;
		break;
	case 3:
		enable_EN3();
		display7SEG_Group2(dig4);
		led_index=2;
		break;
	}
}



