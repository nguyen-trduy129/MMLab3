/*
 * led7seg.c
 *
 *  Created on: Nov 24, 2022
 *      Author: duyvt
 */

#include "led7seg.h"

int led7buffer[4] = {0, 0, 0, 0};
int index_led =0;

void dis7SEG(int number){
	switch(number){
	case 0:
		HAL_GPIO_WritePin(GPIOB, (uint16_t)(0x3f), 0);
		HAL_GPIO_WritePin(GPIOB, (uint16_t)(~0x3f), 1);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOB, (uint16_t)(0x06), 0);
		HAL_GPIO_WritePin(GPIOB, (uint16_t)(~0x06), 1);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOB, (uint16_t)(0x5b), 0);
		HAL_GPIO_WritePin(GPIOB, (uint16_t)(~0x5b), 1);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOB, (uint16_t)(0x4f), 0);
		HAL_GPIO_WritePin(GPIOB, (uint16_t)(~0x4f), 1);
		break;
	case 4:
		HAL_GPIO_WritePin(GPIOB, (uint16_t)(0x66), 0);
		HAL_GPIO_WritePin(GPIOB, (uint16_t)(~0x66), 1);
		break;
	case 5:
		HAL_GPIO_WritePin(GPIOB, (uint16_t)(0x6d), 0);
		HAL_GPIO_WritePin(GPIOB, (uint16_t)(~0x6d), 1);
		break;
	case 6:
		HAL_GPIO_WritePin(GPIOB, (uint16_t)(0x7d), 0);
		HAL_GPIO_WritePin(GPIOB, (uint16_t)(~0x7d), 1);
		break;
	case 7:
		HAL_GPIO_WritePin(GPIOB, (uint16_t)(0x07), 0);
		HAL_GPIO_WritePin(GPIOB, (uint16_t)(~0x07), 1);
		break;
	case 8:
		HAL_GPIO_WritePin(GPIOB, (uint16_t)(0x7f), 0);
		HAL_GPIO_WritePin(GPIOB, (uint16_t)(~0x7f), 1);
		break;
	case 9:
		HAL_GPIO_WritePin(GPIOB, (uint16_t)(0x6f), 0);
		HAL_GPIO_WritePin(GPIOB, (uint16_t)(~0x6f), 1);
		break;
	default:
		HAL_GPIO_WritePin(GPIOB, (uint16_t)(0xff), 1);
		break;
	}
}

void update7SEG(int index, int* led7buffer){
	switch (index){
	case 0:
		HAL_GPIO_WritePin(GPIOA, EN3_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, EN0_Pin, 0);
		dis7SEG(led7buffer[0]);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOA, EN0_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, EN1_Pin, 0);
		dis7SEG(led7buffer[1]);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOA, EN1_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, EN2_Pin, 0);
		dis7SEG(led7buffer[2]);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOA, EN2_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, EN3_Pin, 0);
		dis7SEG(led7buffer[3]);
		break;
	default:
		break;
	}
}

void led7SEGRun(){
	if (timer4_flag ==1){
		setTimer4(20);

		switch(index_led){
		case 0:
			update7SEG(index_led, led7buffer);
			index_led++;
			break;
		case 1:
			update7SEG(index_led, led7buffer);
			index_led++;
			break;
		case 2:
			update7SEG(index_led, led7buffer);
			index_led++;
			break;
		case 3:
			update7SEG(index_led, led7buffer);
			index_led=0;
			break;
		default:
			break;
		}
	}
}
