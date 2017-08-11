// Last updated 07/13/17 --Justin Garcia
// Update was a clean up of all tabs for readability and the addition of the notes tab.
// PLEASE SEE NOTES in notes tab

//-------------------- INCLUDES ---------------------//
#include "Arduino.h"           // all of these statements make sure that the code written in each tab are pulled into this tab. The Arduino IDE only will compile what is in the main tab of the sketch.
#include <EEPROM.h>
#include "radio.h"


//-------------------- MAIN SETUP ---------------------//
void setup() {
  wireless.SETUP();            // Only the working SETUP functions are included


}

//-------------------- MAIN FUNCTIONS ---------------------//
void loop()
{
  wireless.COMMS();      // Only working loops are in included.
  
}
