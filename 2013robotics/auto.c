#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     kGyroSensor,    sensorI2CHiTechnicGyro)
#pragma config(Sensor, S3,     HTIRS2,              sensorI2CCustom)
#pragma config(Motor,  mtr_S1_C1_1,     DriveFL,       tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     DriveBR,       tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     DriveFR,       tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     DriveBL,       tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C3_1,     Plifter,       tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C3_2,     motorI,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C4_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"
#include "getJoyValues.c"
#include "MovesAuto.c"
#include "constants.c"

void initializeRobot()
{
	gyroFlasher();
}


task main()
{
  bool gonext; //used to gate input/output
  bool rightSide=false;

  //BEGINNING OF NXT BUTTON INPUT
  gonext=false;
  nNxtButtonTask=0;
  hogCPU();

  //SIDE SELECTION
  while(!gonext){

    ClearTimer(T1);
      nxtDisplayCenteredBigTextLine(1, "SIDE");
      if(rightSide) nxtDisplayCenteredBigTextLine(3, "RIGHT");
      else          nxtDisplayCenteredBigTextLine(3, "LEFT");

    while(time10[T1]<20);
    if(nNxtButtonPressed == 1) rightSide=true;
    if(nNxtButtonPressed == 2) rightSide=false;
    if(nNxtButtonPressed == 3) gonext=true;
  }

  if(rightSide) {
    ClearTimer(T1);
    while(time10[T1]<50);  //wait for 1/2 second to make sure button released
  }
  else {
    ClearTimer(T1);
    while(time10[T1]<50);  //wait for 1/2 second to make sure button released
  }

  //QUERY GET BOWLING BALL
  gonext=false;
  while(!gonext){
    if(rightSide) {
      nxtDisplayCenteredBigTextLine(1, "RIGHT");
    }
    else {
      nxtDisplayCenteredBigTextLine(1, "LEFT");
    }
  }

  nNxtButtonTask=-1;
  releaseCPU();

	InitializeRobot();
	waitForStart();
	if(rightSide)
	{
		//do all those things
	/*
	distLeft();
	distForward();
	IRsense();
	switch (e)
	{
		case 1:
		break;
		case 2:
		break;
		case 3:
		break;
	}
	*/
	}
	else
	{
		//do other things
		/*
		distRight();
	distForward();
	IRsense();
	switch (e)
	{
		case 1:
		align with left
		break;
		case 2:
		break;
		case 3:
		break;
	}
		*/
	}




}