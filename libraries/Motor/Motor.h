/*
Program:			Motor Library

File:				Motor.h

Author:				John Tatum

Notes:				None
*/
#ifndef Motor_h
#define Motor_h

#include <Arduino.h>

class Motor {
	private:
	int intSpeed;
	int pin1;
	int pin2;
	int pwmChannel1;
	int pwmChannel2;
	int pwmFrequency;
	int pwmResolution;
	bool isRunning;

	public:
	Motor();
	Motor(int intIn1, int intIn2, int channel, int frequency, int resolution);
	void setMotorSpeed(int intIn);
	int getMotorSpeed();
	bool isMotorRunning();
	void stopMotor();
	void startMotor();
};
#endif