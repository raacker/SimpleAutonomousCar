#include"common.h"
#include"ultrasonic.h"

int getData(void)
{
	int distance = 0;
	long startTime;
	long travelTime;

	digitalWrite(TRIGGER,LOW);
	usleep(2);
	digitalWrite(TRIGGER,HIGH);
	usleep(20);
	digitalWrite(TRIGGER,LOW);

	while(digitalRead(ECHO) == LOW);

	startTime = micros();
	while(digitalRead(ECHO) == HIGH);
	travelTime = micros() - startTime;

	distance = travelTime / 58;

	return distance;
}
