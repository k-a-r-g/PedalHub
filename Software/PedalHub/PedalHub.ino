// PedalHub by Karg (Timm Schlegelmilch)
// A Hub fpr multiple momentary and continueous expression Pedals
//
// Licenced under Creative Commons Attribution-ShareAlike 4.0
// http://creativecommons.org/licenses/by-sa/4.0/


#include <MIDI.h>

using namespace midi;
MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, MIDI);

// Preferences
#define      NUM_MOMENTARY_PEDALS     5          // how many momentary pedals are connected?
#define      NUM_CONTINOUS_PEDALS     5          // how many continous pedals are connected?


// pin definitions
#define      MOM_PEDAL_ONE            2          // the digital pin for the 1. momentary pedal
#define      MOM_PEDAL_TWO            3          // the digital pin for the 2. momentary pedal
#define      MOM_PEDAL_THREE          4          // the digital pin for the 3. momentary pedal
#define      MOM_PEDAL_FOUR           5          // the digital pin for the 4. momentary pedal
#define      MOM_PEDAL_FIVE           6          // the digital pin for the 5. momentary pedal

#define      CON_PEDAL_ONE            A0          // analog pin for the 1. continous pedal
#define      CON_PEDAL_TWO            A1          // analog pin for the 2. continous pedal
#define      CON_PEDAL_THREE          A2          // analog pin for the 3. continous pedal
#define      CON_PEDAL_FOUR           A3          // analog pin for the 4. continous pedal
#define      CON_PEDAL_FIVE           A4          // analog pin for the 5. continous pedal



//variable declarations and definitions
boolean      momentary[5]           = {false, false, false, false, false};
byte         momentaryPin[5]        = {MOM_PEDAL_ONE, MOM_PEDAL_TWO, MOM_PEDAL_THREE, MOM_PEDAL_FOUR, MOM_PEDAL_FIVE};

int          continous[5]           = {0, 0, 0, 0, 0};
byte         continousPin[5]        = {CON_PEDAL_ONE, CON_PEDAL_TWO, CON_PEDAL_THREE, CON_PEDAL_FOUR, CON_PEDAL_FIVE};


// initialize everything
void setup() {
  Serial.begin(115200);
  
  pinMode(MOM_PEDAL_ONE, INPUT_PULLUP);  
  pinMode(MOM_PEDAL_TWO, INPUT_PULLUP);  
  pinMode(MOM_PEDAL_THREE, INPUT_PULLUP);  
  pinMode(MOM_PEDAL_FOUR, INPUT_PULLUP);  
  pinMode(MOM_PEDAL_FIVE, INPUT_PULLUP);  
}


// the loop
void loop() {
  Serial.print("momentary: ");
  for (byte i=0; i<5; i++) {
    momentary[i] = digitalRead(momentaryPin[i]);  
    Serial.print(momentary[i]);
    Serial.print(" ");
  }

  Serial.print("   -   continous: ");
  for (byte i=0; i<5; i++) {
    continous[i] = analogRead(continousPin[i]);
    Serial.print(continous[i]);
    Serial.print(" ");
  }
  Serial.println();
  delay(50);
}
