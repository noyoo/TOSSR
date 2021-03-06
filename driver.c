#pragma config(Motor,  motorA,          Left,          tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          Right,         tmotorNXT, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
#define deadzone 10
#define startsorting 1
#define sorted 2
#include "JoystickDriver.c"

int adaptive(int joyval){
	int motorval = -1*0.7874*joyval;
	return motorval;
}

task main(){
	while(true){
		getJoystickSettings(joystick);
		if(joystick.joy1_y1 < (-deadzone)){
			setMotor(Left, adaptive(joystick.joy1_y1));
			}else if(joystick.joy1_y1 > deadzone){
			setMotor(Left, adaptive(joystick.joy1_y1));
			}else{
			stopMotor(Left);
		}
		if(joystick.joy1_y2 < (-deadzone)){
			setMotor(Left, adaptive(joystick.joy1_y2));
			}else if(joystick.joy1_y2 > deadzone){
			setMotor(Right, adaptive(joystick.joy1_y2));
			}else{
			stopMotor(Right);
		}
		if(joystick.joy1_Buttons == 2){
			sendMessage(startsorting);
			while(message != sorted){
				wait1Msec(100);
			}
		}
	}
}
