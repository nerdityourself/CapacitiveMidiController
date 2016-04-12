/*
@author NerdItYourself
@version 1.0, 2/4/2016
*/

// Include library needed for capacitive sensor reading
#include <CapacitiveSensor.h>

// MIDI channel from 0 to 15
#define  midichannel 1;                             

// Note: we use the same trasmitter pin for all the sensor in order to use less digital pin. 

CapacitiveSensor   cs_9_8 = CapacitiveSensor(8,9);          // cs_9_8 is the first cap. sensor. 8 is the transmitter pin, 9 is the receiver pin
CapacitiveSensor   cs_10_8 = CapacitiveSensor(8,10);        // cs_10_8 is the first cap. sensor. 8 is the transmitter pin, 10 is the receiver pin
CapacitiveSensor   cs_11_8 = CapacitiveSensor(8,11);        // cs_11_8 is the first cap. sensor. 8 is the transmitter pin, 11 is the receiver pin
CapacitiveSensor   cs_12_8 = CapacitiveSensor(8,12);        // cs_12_8 is the first cap. sensor. 8 is the transmitter pin, 12 is the receiver pin

// Note: change array size according to the number of capacitive sensor that you want to manage.

byte Notes[4] = {67, 71 , 64, 66};                // MIDI notes associated with each sensor. Change these values to send other notes.
int Threshold[4] = {8000, 8000, 8000, 8000};      // Value that each sensor has to overcome to send a note                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
boolean VelocityFlag  = false;                    // Velocity ON (true) or OFF (false)

boolean activePad[4] = {0,0,0,0};                   // Array of flags indicating wich sensor is currently playing
int PinPlayTime[4] = {0,0,0,0};                     // Counter since a note started to play
int MaxTime[4] = {0,0,0,0};                      // Cycles before a 2nd hit is allowed

byte status1;                                     // byte that we will use to compose a part of the MIDI message

int pin = 0;     
int velocity = 0;

bool debug = false; // Set this flag to true if you want to read cap sense values in Serila Monitor to check if everything is working properly


void setup() 
{
  // Initialize serial port (we will use serial to debug our code and then to send midi commands)
  Serial.begin(115200);  
}

void loop() 
{
  if(debug)
  {
    Serial.println("");
  }
    
  for(int pin=0; pin < 4; pin++)                          
  {
     float capValue = readValue(pin); // Read value of the capacitive sensor
     if(debug)
     {
      Serial.print(" pin: "); 
      Serial.print(pin);
      Serial.print(" - "); 
      Serial.print(capValue); 
     }

    // Check if cap. sensor value is above the threshold
    if((capValue > Threshold[pin]))
    {
      if((activePad[pin] == false))
      {
        if(VelocityFlag == true)
        {
          velocity = (capValue / 8) -1 ;                                              
        }
        else
        {
          velocity = 127;     
        }
     
        MIDI_TX(144, Notes[pin], velocity); //note on (144 is signal for note on)
 
        PinPlayTime[pin] = 0;
        activePad[pin] = true;
      }
      else
      {
        PinPlayTime[pin] = PinPlayTime[pin] + 1;
      }
    }
    else if(activePad[pin] == true)
    {
      PinPlayTime[pin] = PinPlayTime[pin] + 1;
      if(PinPlayTime[pin] > MaxTime[pin])
      {
        activePad[pin] = false;
        MIDI_TX(128, Notes[pin],0); //note off (128 is signal for note on)
      }
    }
  } 
 }

// This function read the value of the capacitive sensor we want to read
// pin input variable is the index of the sensor
// With the switch/case we select the correct sensor to read.
float readValue(int pin)
{
  float value = 0;
  switch(pin)
  {
  case 0:
     value =  cs_9_8.capacitiveSensor(50);
      return value;
      break;
  case 1:
      value =  cs_10_8.capacitiveSensor(50);
      return value;
      break;
  case 2:
      value =  cs_11_8.capacitiveSensor(50);
      return value;
      break;
  case 3:
      value =  cs_12_8.capacitiveSensor(50);
      return value;
      break;
   default:
        break;
  }
}

//*******************************************************************************************************************
// Transmit MIDI Message
//*******************************************************************************************************************
void MIDI_TX(byte MESSAGE, byte PITCH, byte VELOCITY) 
{
  if(!debug)
  {
    status1 = MESSAGE + midichannel;    // The first byte we have to send contains information about the command (note on ,note off, etc..) and the channel were we want to send the message
    Serial.write(status1);
    Serial.write(PITCH);                // The second byte of the message contains the pitch
    Serial.write(VELOCITY);             // The last byte of the message contatins the velocity of the note
  }

}


