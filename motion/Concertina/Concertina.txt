/*
Remote control file for concertina motion
of a snake robot with 12 servos
In this configuration the servos attached to the
head and tail rotate in the vertical plane, all
other servos rotate in the horizontal plane.
*/

#include <Servo.h>

const unsigned short NUM_SERVOS = 12;
Servo robotServos[NUM_SERVOS];
  
// Define variables
int forwardPin = 14;  // Remote control movement pins
int reversePin = 15;
int rightPin = 17;
int leftPin = 16;

int forwardVal = 0;  // Remote control variables
int reverseVal = 0;
int rightVal = 0;
int leftVal = 0;

float lag = 1.0; // Phase lag between segments
float frequency = 1.0; // Oscillation frequency of segments.
int amplitude = 30; // Amplitude of the rectilinear motion of the snake
int startPause = 5000;  // Delay time to position robot
float centerAngle = 93.0; // Center servo angle
int counter = 0; // Loop counter variable
int delayTime = 3; // Pause between servo movements
int turnDelay = 25; 
int tiltAngle=15; // Angle to tilt head and tail up and down

void setup() 
{ 
  
  // Set movement pins as inputs
  pinMode(forwardPin, INPUT);
  pinMode(reversePin, INPUT);
  pinMode(rightPin, INPUT);
  pinMode(leftPin, INPUT);
  
  // Set movement pins to low
  digitalWrite(forwardPin, LOW);
  digitalWrite(reversePin, LOW);
  digitalWrite(rightPin, LOW);
  digitalWrite(leftPin, LOW);
  
  // Attach segment servos to pins and initialize them to their
  // starting positions
  delay(startPause);
  
  for(int i = 0; i < NUM_SERVOS; i++)
  {
    robotServos[i].attach(13 - i);
    robotServos[i].write(centerAngle);
    delay(500);
  }

} 
  

void loop() 
{
  //  Read movement pins
    forwardVal = digitalRead(forwardPin);
    reverseVal = digitalRead(reversePin);
    rightVal = digitalRead(rightPin);
    leftVal = digitalRead(leftPin);

// Forward motion
  if (forwardVal == HIGH){
// Tilt head down slightly to anchor front of snake
// and lift tail off the ground
    for(counter = 0; counter < tiltAngle; counter += 1) {
      robotServos[0].write(centerAngle+counter);
      robotServos[11].write(centerAngle-counter);
      delay(turnDelay);
    }
// Contract snake
    for(counter = 0; counter < 80; counter += 1)  {
      robotServos[1].write(centerAngle+counter);
      robotServos[2].write(centerAngle);
      robotServos[3].write(centerAngle-counter);
      robotServos[4].write(centerAngle-counter);
      robotServos[5].write(centerAngle);    
      robotServos[6].write(centerAngle);
      robotServos[7].write(centerAngle+counter);    
      robotServos[8].write(centerAngle+counter);
      robotServos[9].write(centerAngle);
      robotServos[10].write(centerAngle-counter);
      delay(turnDelay);     
    }
//  Lift head off the ground and tilt tail down
//  slightly to anchor back of snake
    for(counter = 0; counter < 2*tiltAngle; counter += 1) {
      robotServos[0].write(centerAngle+tiltAngle-counter);
      robotServos[11].write(centerAngle-tiltAngle+counter);
      delay(turnDelay);
    }
// Straighten snake
    for(counter = 0; counter < 80; counter += 1)  {
      robotServos[1].write(centerAngle+80-counter);
      robotServos[2].write(centerAngle);
      robotServos[3].write(centerAngle-80+counter);
      robotServos[4].write(centerAngle-80+counter);
      robotServos[5].write(centerAngle);    
      robotServos[6].write(centerAngle);
      robotServos[7].write(centerAngle+80-counter);    
      robotServos[8].write(centerAngle+80-counter);
      robotServos[9].write(centerAngle);
      robotServos[10].write(centerAngle-80+counter);
      delay(turnDelay);     
    }
//  Return head and tail to horizontal position
    for(counter = 0; counter < tiltAngle; counter += 1) {
      robotServos[0].write(centerAngle-tiltAngle+counter);
      robotServos[11].write(centerAngle+tiltAngle-counter);
      delay(turnDelay);
    }
  }

// Reverse motion
  if (reverseVal == HIGH){
// Tilt tail down slightly to anchor back of snake
// and lift head off the ground
    for(counter = 0; counter < tiltAngle; counter += 1) {
      robotServos[0].write(centerAngle-counter);
      robotServos[11].write(centerAngle+counter);
      delay(turnDelay);
    }
// Contract snake
    for(counter = 0; counter < 80; counter += 1)  {
      robotServos[1].write(centerAngle+counter);
      robotServos[2].write(centerAngle);
      robotServos[3].write(centerAngle-counter);
      robotServos[4].write(centerAngle-counter);
      robotServos[5].write(centerAngle);    
      robotServos[6].write(centerAngle);
      robotServos[7].write(centerAngle+counter);    
      robotServos[8].write(centerAngle+counter);
      robotServos[9].write(centerAngle);
      robotServos[10].write(centerAngle-counter);
      delay(turnDelay);     
    }
//  Lift tail off the ground and tilt head dwon
//  slightly to anchor front of snake
    for(counter = 0; counter < 2*tiltAngle; counter += 1) {
      robotServos[0].write(centerAngle-tiltAngle+counter);
      robotServos[11].write(centerAngle+tiltAngle-counter);
      delay(turnDelay);
    }
// Straighten snake
    for(counter = 0; counter < 80; counter += 1)  {
      robotServos[1].write(centerAngle+80-counter);
      robotServos[2].write(centerAngle);
      robotServos[3].write(centerAngle-80+counter);
      robotServos[4].write(centerAngle-80+counter);
      robotServos[5].write(centerAngle);    
      robotServos[6].write(centerAngle);
      robotServos[7].write(centerAngle+80-counter);    
      robotServos[8].write(centerAngle+80-counter);
      robotServos[9].write(centerAngle);
      robotServos[10].write(centerAngle-80+counter);
      delay(turnDelay);     
    }
//  Return head and tail to horizontal position
    for(counter = 0; counter < tiltAngle; counter += 1) {
      robotServos[0].write(centerAngle+tiltAngle-counter);
      robotServos[11].write(centerAngle-tiltAngle+counter);
      delay(turnDelay);
    }
  }

//  Right turn
  if (rightVal == HIGH){
// Tilt head down slightly to anchor front of snake
// and lift tail off the ground
    for(counter = 0; counter < tiltAngle; counter += 1) {
      robotServos[0].write(centerAngle+counter);
      robotServos[11].write(centerAngle-counter);
      delay(turnDelay);
    }
// Contract snake swinging body to the left
    for(counter = 0; counter < 40; counter += 1)  {
      robotServos[1].write(centerAngle+counter);
      robotServos[2].write(centerAngle);
      robotServos[3].write(centerAngle-2*counter);
      robotServos[4].write(centerAngle-2*counter);
      robotServos[5].write(centerAngle);    
      robotServos[6].write(centerAngle);
      robotServos[7].write(centerAngle+2*counter);    
      robotServos[8].write(centerAngle+2*counter);
      robotServos[9].write(centerAngle);
      robotServos[10].write(centerAngle-2*counter);
      delay(2*turnDelay);     
    }
//  Lift head off the ground and tilt tail dwon
//  slightly to anchor back of snake
    for(counter = 0; counter < 2*tiltAngle; counter += 1) {
      robotServos[0].write(centerAngle+tiltAngle-counter);
      robotServos[11].write(centerAngle-tiltAngle+counter);
      delay(turnDelay);
    }
// Straighten snake
    for(counter = 0; counter < 40; counter += 1)  {
      robotServos[1].write(centerAngle+40-counter);
      robotServos[2].write(centerAngle);
      robotServos[3].write(centerAngle-80+2*counter);
      robotServos[4].write(centerAngle-80+2*counter);
      robotServos[5].write(centerAngle);    
      robotServos[6].write(centerAngle);
      robotServos[7].write(centerAngle+80-2*counter);    
      robotServos[8].write(centerAngle+80-2*counter);
      robotServos[9].write(centerAngle);
      robotServos[10].write(centerAngle-80+2*counter);
      delay(2*turnDelay);     
    }
//  Return head and tail to horizontal position
    for(counter = 0; counter < tiltAngle; counter += 1) {
      robotServos[0].write(centerAngle-tiltAngle+counter);
      robotServos[11].write(centerAngle+tiltAngle-counter);
      delay(turnDelay);
    }
  }
  
//  Left turn
  if (leftVal == HIGH){
// Tilt head down slightly to anchor front of snake
// and lift tail off the ground
    for(counter = 0; counter < tiltAngle; counter += 1) {
      robotServos[0].write(centerAngle+counter);
      robotServos[11].write(centerAngle-counter);
      delay(turnDelay);
    }
// Contract snake swinging body to the right
    for(counter = 0; counter < 40; counter += 1)  {
      robotServos[1].write(centerAngle+2*counter);
      robotServos[2].write(centerAngle);
      robotServos[3].write(centerAngle-2*counter);
      robotServos[4].write(centerAngle-2*counter);
      robotServos[5].write(centerAngle);    
      robotServos[6].write(centerAngle);
      robotServos[7].write(centerAngle+2*counter);    
      robotServos[8].write(centerAngle+2*counter);
      robotServos[9].write(centerAngle);
      robotServos[10].write(centerAngle-counter);
      delay(2*turnDelay);     
    }
//  Lift head off the ground and tilt tail dwon
//  slightly to anchor back of snake
    for(counter = 0; counter < 2*tiltAngle; counter += 1) {
      robotServos[0].write(centerAngle+tiltAngle-counter);
      robotServos[11].write(centerAngle-tiltAngle+counter);
      delay(turnDelay);
    }
// Straighten snake
    for(counter = 0; counter < 40; counter += 1)  {
      robotServos[1].write(centerAngle+80-2*counter);
      robotServos[2].write(centerAngle);
      robotServos[3].write(centerAngle-80+2*counter);
      robotServos[4].write(centerAngle-80+2*counter);
      robotServos[5].write(centerAngle);    
      robotServos[6].write(centerAngle);
      robotServos[7].write(centerAngle+80-2*counter);    
      robotServos[8].write(centerAngle+80-2*counter);
      robotServos[9].write(centerAngle);
      robotServos[10].write(centerAngle-40+counter);
      delay(2*turnDelay);     
    }
//  Return head and tail to horizontal position
    for(counter = 0; counter < tiltAngle; counter += 1) {
      robotServos[0].write(centerAngle-tiltAngle+counter);
      robotServos[11].write(centerAngle+tiltAngle-counter);
      delay(turnDelay);
    }
  }
   
}
