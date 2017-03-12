#ifndef __COMMON_H__
#define __COMMON_H__


#include<stdio.h>
#include<wiringPi.h>

#define TRUE 1
#define FALSE 0

#define HIGH 1
#define LOW 0

#define L_in1 22
#define L_PWM 23
#define L_en 24
#define L_in2 25

#define R_in1 26
#define R_PWM 27
#define R_en 28
#define R_in2 29

#define TRIGGER 2
#define ECHO 3

#define LIMIT_DISTANCE 40  //40cm
#define LIMIT_IMPIDENCE 15	//15cm
#define LIMIT_AVERAGE 15 	//limit 15cm for stucked state
#define MAX_ARRAY 7
#endif
