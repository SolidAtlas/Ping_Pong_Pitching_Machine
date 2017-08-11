/*
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/
//-------------------- INCLUDES ---------------------//
#include "Arduino.h"
#include "radio.h"
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
//-------------------- VARIABLES ---------------------//
RF24 radio(10, 9); // CE, CSN
const byte addresses[][6] = {"00001", "00002"};
const int button = 6;
int Launch = 1050;
//extern int pitch_speed;
//extern int pich_location;
//extern int pitch_curve;
//extern int machine_rotation;

//-------------------- CLASS ---------------------//
radioclass::radioclass()   // You will see the same call out in every tab to the right of this. It is essential
{
}


//-------------------- SETUP ---------------------//
void radioclass::SETUP() // all fuctions written in a certain tab need the class identifier before the function name.
{
  Serial.begin(9600);  
  pinMode(button, INPUT_PULLUP);
  radio.begin();
  radio.openWritingPipe(addresses[1]); // 00001
  radio.openReadingPipe(1, addresses[0]); // 00002
  radio.setPALevel(RF24_PA_MIN);
}

//-------------------- OTHER FUNCTIONS ---------------------//

void radioclass::COMMS ()
{
  
  
if (digitalRead(button) == LOW)
 {
  Serial.println(digitalRead(button));
  radio.stopListening();
  radio.write(&Launch, sizeof(Launch));
  Serial.println(Launch);
 }
 else
 {
  radio.startListening();
   while (radio.available()) 
    {
  char text[32] = "";
  radio.read(&text, sizeof(text));
  Serial.println(text);
    }
 }
}

//-------------------- AKA ---------------------//
radioclass wireless = radioclass();

