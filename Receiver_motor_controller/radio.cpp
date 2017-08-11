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
int Launch_received = 0;
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
  radio.begin();
  radio.openWritingPipe(addresses[0]); // 00002
  radio.openReadingPipe(1, addresses[1]); // 00001
  radio.setPALevel(RF24_PA_MIN);
}

//-------------------- OTHER FUNCTIONS ---------------------//
void radioclass::COMMS ()
{
  radio.startListening();
  if ( radio.available()) 
  {
    Serial.println("Listening");
    while (radio.available()) 
    {
      int Launch = 0;
      radio.read(&Launch, sizeof(Launch));
      Launch_received = Launch;
      Serial.print("recieved value is");
      Serial.println(Launch_received);
    }
  Serial.println("Saying Hi");
  Launch_received = 0;
  radio.stopListening();
  const char text[] = "Hello World";
  radio.write(&text, sizeof(text));
  }
//  }
//    if (!radio.available())
//    {
//    Serial.println("Saying Hi");
//    Launch_received = 0;
//    radio.stopListening();
//    const char text[] = "Hello World";
//    radio.write(&text, sizeof(text));
//    radio.startListening();
//    }

  }

//-------------------- AKA ---------------------//
radioclass wireless = radioclass();
