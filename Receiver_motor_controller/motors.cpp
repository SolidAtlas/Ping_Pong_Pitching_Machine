/*
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/
//-------------------- INCLUDES ---------------------//
#include "Arduino.h"
#include "motors.h"
#include <Servo.h>

//-------------------- VARIABLES ---------------------//
extern int Launch_received; // set values you need to zero
Servo firstESC, secondESC;  //Create as much as Servoobject you want. You can controll 2 or more Servos at the same time


//-------------------- CLASS ---------------------//
motorclass::motorclass()   // You will see the same call out in every tab to the right of this. It is essential
{
}


//-------------------- SETUP ---------------------//
void motorclass::SETUP() // all fuctions written in a certain tab need the class identifier before the function name.
{
    firstESC.attach(2);    
    secondESC.attach(5);    
}

//-------------------- OTHER FUNCTIONS ---------------------//

void motorclass::SHOOT ()
{
//First connect your ESC WITHOUT Arming. Then Open Serial and follow Instructions
  firstESC.writeMicroseconds(Launch_received);
  secondESC.writeMicroseconds(Launch_received);
//  Serial.print("Launch is currently");
//  Serial.println(Launch_received);
}

//-------------------- AKA ---------------------//
motorclass launcher = motorclass();


