/*
 * global.h
 *
 *  Created on: Nov 24, 2022
 *      Author: duyvt
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "software_timer.h"
#include "mode.h"
#include "button.h"
#include "led7seg.h"
#include "trafficlight.h"

extern int mode;
extern int lightState0;
extern int lightState1;

void ledBlink();

#define INIT		0
#define MOD1		1
#define MOD2		2
#define MOD3		3
#define MOD4		4

#define LIGHT_INIT	 	0
#define LIGHT_RED	 	1
#define LIGHT_GREEN	 	2
#define LIGHT_YELLOW 	3
#define RED_BLINK	 	4
#define YELLOW_BLINK 	5
#define GREEN_BLINK	 	6

#define SEG7_INIT		0
#define	SEG7_EN1		1
#define	SEG7_EN2		2
#define	SEG7_EN3		3
#define	SEG7_EN4		4

#endif /* INC_GLOBAL_H_ */
