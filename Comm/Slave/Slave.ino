//Slave Arduino

#include<Wire.h>                          //Library for I2C Communication functions

byte SlaveReceived = 0;
void setup() 
{

Serial.begin(9600);                     //Begins Serial Communication at 9600 baud rate
  Wire.begin(8);                          //Begins I2C communication with Slave Address as  .                                                      8 at pin (A4,A5)
  Wire.onReceive(receiveEvent);           //Function call when Slave receives value .           .                                                               from master
  Wire.onRequest(requestEvent);           //Function call when Master request value .       .                                                               from Slave
} 



void loop(void) 
{


}

void receiveEvent (int howMany)                    //This Function is called when .             .                                                                             Slave .receives value from master
{
   SlaveReceived = Wire.read();                    //Used to read value received from master and store in variable SlaveReceived
}
