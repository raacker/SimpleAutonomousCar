#include"common.h"
#include"move.h"
#include"ultrasonic.h"

int movement(void)
{
	int distance = 0;
	int array[MAX_ARRAY] = {0,};
	int i;
	int count = 0, firstData = 0;
	int average = 0;
	digitalWrite(L_en,LOW);
	digitalWrite(R_en,LOW);
	digitalWrite(L_PWM,HIGH);
	digitalWrite(R_PWM,HIGH);
	digitalWrite(L_in1,LOW);
	digitalWrite(L_in2,LOW);
	digitalWrite(R_in1,LOW);
	digitalWrite(R_in2,LOW);
		//initialize motor

	while(TRUE)
	{
		distance = getData();	//get data from ultrasonic
		printf("Current Distance : %d\n",distance);

		delay(250);		//ultrasonic sensor sleep for 0.18 sec
		if(count == MAX_ARRAY)	//count 7 times
		{
			average = averageData(array);	//get average data
			if(average + LIMIT_AVERAGE >= firstData && average - LIMIT_AVERAGE <= firstData) 
				//if data is in maximum and minimun range
			{
				printf("Stucked!\n");
				digitalWrite(L_in1,HIGH);
				digitalWrite(L_in2,LOW);
				digitalWrite(R_in1,HIGH);
				digitalWrite(R_in2,LOW);	//move backward
				delay(500);

				digitalWrite(L_in1,LOW);
				digitalWrite(L_in2,HIGH);
				digitalWrite(R_in1,HIGH);
				digitalWrite(R_in2,LOW);
				
				count = 0;
				for(i=0;i<MAX_ARRAY;i++)
					array[i] = 0;
				firstData = distance;
				continue;
			}
			count = 0;
			for(i=0;i<MAX_ARRAY;i++)
				array[i]  = 0;
			firstData = distance;		//initialize
		}
		array[count++] = distance;

		digitalWrite(L_in1,LOW);	//go forward
		digitalWrite(L_in2,HIGH);
		digitalWrite(R_in1,LOW);
		digitalWrite(R_in2,HIGH);

		if(distance <= LIMIT_IMPIDENCE)	//if distance from the wall is less than 15cm
		{
			printf("ERROR OCCURED : Too close. stop\n");
			
			digitalWrite(L_in1,HIGH);
			digitalWrite(L_in2,LOW);
			digitalWrite(R_in1,HIGH);
			digitalWrite(R_in2,LOW);
			delay(500);	//stop for 0.5 sec

			digitalWrite(L_in1,LOW);
			digitalWrite(L_in2,HIGH);
			digitalWrite(R_in1,HIGH);
			digitalWrite(R_in2,LOW);  //turn Right
			continue;
		}
		if(distance <= LIMIT_DISTANCE)	//if distance from the wall is less than 40cm
		{
			printf("Detected Wall. Turn Left\n");
			digitalWrite(L_in1,HIGH);
			digitalWrite(L_in2,LOW);
			digitalWrite(R_in1,LOW);
			digitalWrite(R_in2,HIGH);  //turn left
			continue;
		}
	}
}

int stop(void)
{
	digitalWrite(L_en,HIGH);
	digitalWrite(R_en,HIGH);
}

int averageData(int arr[])
{
	int result = 0;
	int i;
	for(i=0;i<MAX_ARRAY;i++)
	{
		result += arr[i];
	}
	return result/MAX_ARRAY;
}
