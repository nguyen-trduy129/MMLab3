/*
 * mode.c
 *
 *  Created on: Nov 24, 2022
 *      Author: duyvt
 */

#include "mode.h"

void modeRun(){
	switch(mode){
	case INIT:
		mode =MOD1;
		break;
	case MOD1:
		led7buffer[0] =1;
		led7buffer[1] =1;
		led7buffer[2] =-1;
		led7buffer[3] =-1;
		led7SEGRun();

		if (isButton1Pressed()){
			mode =MOD2;
		}
		break;
	case MOD2:
		led7buffer[0] =2;
		led7buffer[1] =2;
		led7buffer[2] =redTime/10;
		led7buffer[3] =redTime%10;
		led7SEGRun();

		if (isButton1Pressed()){
			mode =MOD3;
		}

		if (isButton2Pressed()){
			if (redTime <99) redTime++;
			else redTime =0;
		}

		if (isButton3Pressed()){
			mode =MOD1;
		}
		break;
	case MOD3:
		led7buffer[0] =3;
		led7buffer[1] =3;
		led7buffer[2] =yellowTime/10;
		led7buffer[3] =yellowTime%10;
		led7SEGRun();

		if (isButton1Pressed()){
			mode =MOD4;
		}

		if (isButton2Pressed()){
			if (yellowTime <99) yellowTime++;
			else yellowTime =0;
		}

		if (isButton3Pressed()){
			mode =MOD1;
		}
		break;
	case MOD4:
		led7buffer[0] =4;
		led7buffer[1] =4;
		led7buffer[2] =greenTime/10;
		led7buffer[3] =greenTime%10;
		led7SEGRun();

		if (isButton1Pressed()){
			mode =MOD1;
		}

		if (isButton2Pressed()){
			if (greenTime <99) greenTime++;
			else greenTime=0;
		}

		if (isButton3Pressed()){
			mode =MOD1;
		}
		break;
	default:
		break;
	}
}


