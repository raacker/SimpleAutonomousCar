#include"common.h"
#include"move.h"
#include"ultrasonic.h"

int main(void)
{
	int status = 0;
	if(wiringPiSetup() == -1)
		return -1;

	pinMode(L_in1, OUTPUT);
	pinMode(L_in2, OUTPUT);
	pinMode(L_PWM, OUTPUT);
	pinMode(L_en, OUTPUT);
	pinMode(R_in1, OUTPUT);
	pinMode(R_in2, OUTPUT);
	pinMode(R_PWM, OUTPUT);
	pinMode(R_en, OUTPUT);
	pinMode(TRIGGER,OUTPUT);
	pinMode(ECHO,INPUT);

	digitalWrite(TRIGGER,LOW);
	delay(30);

	movement();
}
