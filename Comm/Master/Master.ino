//Master Arduino 

#include<Wire.h>                             //Library for I2C Communication functions
#include <EnableInterrupt.h>

#define SERIAL_PORT_SPEED 57600
#define RC_NUM_CHANNELS  4

#define RC_CH1  0
#define RC_CH2  1
#define RC_CH3  2
#define RC_CH4  3

#define RC_CH1_INPUT  A0
#define RC_CH2_INPUT  A1
#define RC_CH3_INPUT  A2
#define RC_CH4_INPUT  A3

Void mian()
{
Serial.begin(9600);                        //Begins Serial Communication at 9600 baud rate
  Wire.begin();                              //Begins I2C communication at pin (A4,A5)
}


void loop()
{


Wire.requestFrom(8,1);                           // request 1 byte from slave arduino (8)
byte MasterReceive = Wire.read();                // receive a byte from the slave                                                                                                 .                                                                  arduino and store in MasterReceive

Wire.beginTransmission(8);                       // start transmit to slave arduino (8)
 

Wire.write(MasterSend);                          // sends one byte converted POT value to    .                                                                 slave

    Wire.endTransmission();                          // stop transmitting


}
