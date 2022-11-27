/*
 * trafficlight.c
 *
 *  Created on: Nov 24, 2022
 *      Author: duyvt
 */

#include "trafficlight.h"

int redTime =5, greenTime =3, yellowTime =2;

void clearLED0 (){
	HAL_GPIO_WritePin(GPIOA, RED0_Pin, 1);
	HAL_GPIO_WritePin(GPIOA, GREEN0_Pin, 1);
	HAL_GPIO_WritePin(GPIOA, YELLOW0_Pin, 1);
}

void clearLED1 (){
	HAL_GPIO_WritePin(GPIOA, RED1_Pin, 1);
	HAL_GPIO_WritePin(GPIOA, GREEN1_Pin, 1);
	HAL_GPIO_WritePin(GPIOA, YELLOW1_Pin, 1);
}

void trafficLightRun_Way1(){
	//way1
	switch (lightState0){
	case LIGHT_INIT:
		lightState0 =LIGHT_RED;
		setTimer2(redTime*10 +3);
		break;
	case LIGHT_RED:
		HAL_GPIO_WritePin(GPIOA, RED0_Pin, 0);
		HAL_GPIO_WritePin(GPIOA, GREEN0_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, YELLOW0_Pin, 1);

		if (timer2_flag ==1){
			lightState0 =LIGHT_GREEN;
			setTimer2(greenTime*10);
		}

		if (mode == MOD2){
			setTimer2(25);
			lightState0 = RED_BLINK;
			clearLED0();
		}
		break;
	case LIGHT_GREEN:
		HAL_GPIO_WritePin(GPIOA, RED0_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, GREEN0_Pin, 0);
		HAL_GPIO_WritePin(GPIOA, YELLOW0_Pin, 1);

		if (timer2_flag ==1){
			lightState0 =LIGHT_YELLOW;
			setTimer2(yellowTime*10);
		}

		if (mode == MOD2){
			setTimer2(25);
			lightState0 = RED_BLINK;
			clearLED0();
		}
		break;
	case LIGHT_YELLOW:
		HAL_GPIO_WritePin(GPIOA, RED0_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, GREEN0_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, YELLOW0_Pin, 0);

		if (timer2_flag ==1){
			lightState0 =LIGHT_RED;
			setTimer2(redTime*10);
		}

		if (mode == MOD2){
			setTimer2(25);
			lightState0 = RED_BLINK;
			clearLED0();
		}
		break;

	case RED_BLINK:
		if (timer2_flag ==1){
			HAL_GPIO_TogglePin(GPIOA, RED0_Pin);

			lightState0 =RED_BLINK;
			setTimer2(25);
		}

		if (mode == MOD3){
			setTimer2(3);
			lightState0 = YELLOW_BLINK;
			clearLED0();
		}

		if (mode == MOD1){
			setTimer2(redTime*10);
			lightState0 = LIGHT_RED;
		}
		break;
	case YELLOW_BLINK:
		if (timer2_flag ==1){
			HAL_GPIO_TogglePin(GPIOA, YELLOW0_Pin);

			lightState0 =YELLOW_BLINK;
			setTimer2(25);
		}

		if (mode ==MOD4){
			setTimer2(3);
			lightState0 = GREEN_BLINK;
			clearLED0();
		}

		if (mode == MOD1){
			setTimer2(redTime*10);
			lightState0 = LIGHT_RED;
		}
		break;
	case GREEN_BLINK:
		if (timer2_flag ==1){
			HAL_GPIO_TogglePin(GPIOA, GREEN0_Pin);

			lightState0 =GREEN_BLINK;
			setTimer2(25);
		}

		if (mode == MOD1){
			lightState0 =LIGHT_RED;
			setTimer2(redTime*10);
		}
		break;
	default:
		break;
	}
}

void trafficLightRun_Way2(){
	//way 2
	switch(lightState1){
	case LIGHT_INIT:
		lightState1 =LIGHT_GREEN;
		setTimer3(greenTime*10 +5);
		break;
	case LIGHT_GREEN:
		HAL_GPIO_WritePin(GPIOA, RED1_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, GREEN1_Pin, 0);
		HAL_GPIO_WritePin(GPIOA, YELLOW1_Pin, 1);

		if (timer3_flag ==1){
			lightState1 = LIGHT_YELLOW;
			setTimer3(yellowTime*10);
		}

		if (mode == MOD2){
			setTimer3(3);
			lightState1 = RED_BLINK;
			clearLED1();
		}
		break;
	case LIGHT_YELLOW:
		HAL_GPIO_WritePin(GPIOA, RED1_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, GREEN1_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, YELLOW1_Pin, 0);

		if (timer3_flag ==1){
			lightState1 = LIGHT_RED;
			setTimer3(redTime*10);
		}

		if (mode == MOD2){
			setTimer3(3);
			lightState1 = RED_BLINK;
			clearLED1();
		}
		break;
	case LIGHT_RED:
		HAL_GPIO_WritePin(GPIOA, RED1_Pin, 0);
		HAL_GPIO_WritePin(GPIOA, GREEN1_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, YELLOW1_Pin, 1);

		if (timer3_flag ==1){
			lightState1 = LIGHT_GREEN;
			setTimer3(greenTime*10);
		}

		if (mode == MOD2){
			setTimer3(3);
			lightState1 = RED_BLINK;
			clearLED1();
		}
		break;

	case RED_BLINK:
		if (timer3_flag ==1){
			HAL_GPIO_TogglePin(GPIOA, RED1_Pin);

			lightState1 =RED_BLINK;
			setTimer3(25);
		}

		if (mode == MOD3){
			setTimer3(25);
			lightState1 = YELLOW_BLINK;
			clearLED1();
		}

		if (mode == MOD1){
			setTimer3(greenTime*10);
			lightState1 = LIGHT_GREEN;
		}
		break;
	case YELLOW_BLINK:
		if (timer3_flag ==1){
			HAL_GPIO_TogglePin(GPIOA, YELLOW1_Pin);

			lightState1 =YELLOW_BLINK;
			setTimer3(25);
		}

		if (mode == MOD4){
			setTimer3(25);
			lightState1 = GREEN_BLINK;
			clearLED1();
		}

		if (mode == MOD1){
			setTimer3(greenTime*10);
			lightState1 = LIGHT_GREEN;
		}
		break;
	case GREEN_BLINK:
		if (timer3_flag ==1){
			HAL_GPIO_TogglePin(GPIOA, GREEN1_Pin);

			lightState1 = GREEN_BLINK;
			setTimer3(25);
		}

		if (mode == MOD1){
			setTimer3(greenTime*10);
			lightState1 = LIGHT_GREEN;
			clearLED1();
		}
		break;
	default:
		break;
	}
}

