/*
Autonomous movement file for robot snake with 12 servos
*/

#include <Servo.h> 

// Define servo objects for the snake segments
Servo s1; 
Servo s2;
Servo s3;
Servo s4; 
Servo s5;
Servo s6;
Servo s7;
Servo s8;
Servo s9; 
Servo s10;
Servo s11;
Servo s12;
Servo panServo;
  
// Define variables
int IRpin = 15;
int distanceReading;
int wallDistance;
int wallDistanceTolerance = 30;
int distanceReadingLeft;
int distanceReadingRight;
int wallDistanceLeft;
int wallDistanceRight;
int panDelay = 1000;

int forwardVal = 0;  // Remote control variables
int reverseVal = 0;
int rightVal = 0;
int leftVal = 0;

int counter = 0; // Loop counter variable
float lag = .5712; // Phase lag between segments
int frequency = 1; // Oscillation frequency of segments.
int amplitude = 40; // Amplitude of the serpentine motion of the snake
int rightOffset = 5; // Right turn offset
int leftOffset = -5; // Left turn offset
int offset = 6; // Variable to correct servos that are not exactly centered
int delayTime = 3; // Delay between limb movements
int startPause = 5000;  // Delay time to position robot
int test = -3; // Test varialble takes values from -6 to +5
  
void setup() 
{ 

  
// Attach segments to pins  
   s1.attach(2);
   s2.attach(3);
   s3.attach(4);
   s4.attach(5);
   s5.attach(6);
   s6.attach(7);
   s7.attach(8);
   s8.attach(9);
   s9.attach(10);
   s10.attach(11);
   s11.attach(12);
   s12.attach(13);
   panServo.attach(14);
 
// Put snake in starting position
   s1.write(90+offset+amplitude*cos(5*lag));
   s2.write(90+offset+amplitude*cos(4*lag)); 
   s3.write(90+offset+amplitude*cos(3*lag));
   s4.write(90+amplitude*cos(2*lag));
   s5.write(90+amplitude*cos(1*lag));
   s6.write(90+amplitude*cos(0*lag));
   s7.write(90+amplitude*cos(-1*lag));
   s8.write(90+amplitude*cos(-2*lag));
   s9.write(90+amplitude*cos(-3*lag));
   s10.write(90+amplitude*cos(-4*lag));
   s11.write(90+amplitude*cos(-5*lag));
   s12.write(90+amplitude*cos(-6*lag));
 
   
  delay(startPause);  // Pause to position robot
} 
  
void loop() {
// Point distance sensor straight ahead
  panServo.write(90);
// Take reading from distance sensor
  delay(1000);
  distanceReading = analogRead(IRpin);
  wallDistance = 40-distanceReading/10;
  
// If wallDistance > wallDistanceTolerance, move forward
  if (wallDistance > wallDistanceTolerance) {  
    for(counter = 0; counter < 360; counter += 1)  {
      delay(delayTime);
      s1.write(90+offset+amplitude*cos(frequency*counter*3.14159/180+5*lag));
      s2.write(90+offset+amplitude*cos(frequency*counter*3.14159/180+4*lag));
      s3.write(90+offset+amplitude*cos(frequency*counter*3.14159/180+3*lag));
      s4.write(90+amplitude*cos(frequency*counter*3.14159/180+2*lag));
      s5.write(90+amplitude*cos(frequency*counter*3.14159/180+1*lag));
      s6.write(90+amplitude*cos(frequency*counter*3.14159/180+0*lag));    
      s7.write(90+amplitude*cos(frequency*counter*3.14159/180-1*lag));
      s8.write(90+amplitude*cos(frequency*counter*3.14159/180-2*lag));    
      s9.write(90+amplitude*cos(frequency*counter*3.14159/180-3*lag));
      s10.write(90+amplitude*cos(frequency*counter*3.14159/180-4*lag));
      s11.write(90+amplitude*cos(frequency*counter*3.14159/180-5*lag));    
      s12.write(90+amplitude*cos(frequency*counter*3.14159/180-6*lag));     
    }
  }

// If wallDistance , wallDistanceTolerance, stop and take
// distance measurements to the left and right
  if (wallDistance < wallDistanceTolerance) {
    panServo.write(170);
    delay(panDelay);
    distanceReadingLeft = analogRead(IRpin);
    delay(panDelay);
    wallDistanceLeft = 40-distanceReadingLeft/10;

    panServo.write(20);
    delay(panDelay);
    distanceReadingRight = analogRead(IRpin);
    delay(panDelay);
    wallDistanceRight = 40-distanceReadingRight/10;
    panServo.write(90);
    delay(panDelay);



    if (wallDistanceLeft > wallDistanceRight) {
// Reverse and then turn left
// Reverse
    for(counter = 360; counter > 0; counter -= 1)  {
      delay(delayTime);
      s1.write(90+offset+amplitude*cos(frequency*counter*3.14159/180+5*lag));
      s2.write(90+offset+amplitude*cos(frequency*counter*3.14159/180+4*lag));
      s3.write(90+offset+amplitude*cos(frequency*counter*3.14159/180+3*lag));
      s4.write(90+amplitude*cos(frequency*counter*3.14159/180+2*lag));
      s5.write(90+amplitude*cos(frequency*counter*3.14159/180+1*lag));
      s6.write(90+amplitude*cos(frequency*counter*3.14159/180+0*lag));    
      s7.write(90+amplitude*cos(frequency*counter*3.14159/180-1*lag));
      s8.write(90+amplitude*cos(frequency*counter*3.14159/180-2*lag));    
      s9.write(90+amplitude*cos(frequency*counter*3.14159/180-3*lag));
      s10.write(90+amplitude*cos(frequency*counter*3.14159/180-4*lag));
      s11.write(90+amplitude*cos(frequency*counter*3.14159/180-5*lag));    
      s12.write(90+amplitude*cos(frequency*counter*3.14159/180-6*lag));     
    }    
  
// Left turn
// Ramp up turn offset
    for(counter = 0; counter < 10; counter += 1)  {
      delay(delayTime);
      s1.write(90+offset+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180+5*lag));
      s2.write(90+offset+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180+4*lag));
      s3.write(90+offset+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180+3*lag));
      s4.write(90+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180+2*lag));
      s5.write(90+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180+1*lag));
      s6.write(90+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180+0*lag));    
      s7.write(90+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180-1*lag));
      s8.write(90+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180-2*lag));    
      s9.write(90+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180-3*lag));
      s10.write(90+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180-4*lag));
      s11.write(90+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180-5*lag));    
      s12.write(90+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180-6*lag));     
    }  
// Continue left turn
    for(counter = 11; counter < 350; counter += 1)  {
      delay(delayTime);
      s1.write(90+offset+leftOffset+amplitude*cos(frequency*counter*3.14159/180+5*lag));
      s2.write(90+offset+leftOffset+amplitude*cos(frequency*counter*3.14159/180+4*lag));
      s3.write(90+offset+leftOffset+amplitude*cos(frequency*counter*3.14159/180+3*lag));
      s4.write(90+leftOffset+amplitude*cos(frequency*counter*3.14159/180+2*lag));
      s5.write(90+leftOffset+amplitude*cos(frequency*counter*3.14159/180+1*lag));
      s6.write(90+leftOffset+amplitude*cos(frequency*counter*3.14159/180+0*lag));    
      s7.write(90+leftOffset+amplitude*cos(frequency*counter*3.14159/180-1*lag));
      s8.write(90+leftOffset+amplitude*cos(frequency*counter*3.14159/180-2*lag));    
      s9.write(90+leftOffset+amplitude*cos(frequency*counter*3.14159/180-3*lag));
      s10.write(90+leftOffset+amplitude*cos(frequency*counter*3.14159/180-4*lag));
      s11.write(90+leftOffset+amplitude*cos(frequency*counter*3.14159/180-5*lag));    
      s12.write(90+leftOffset+amplitude*cos(frequency*counter*3.14159/180-6*lag));     
    }    
// Ramp down turn offset
    for(counter = 350; counter < 360; counter += 1)  {
      delay(delayTime);
      s1.write(90+offset+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180+5*lag));
      s2.write(90+offset+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180+4*lag));
      s3.write(90+offset+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180+3*lag));
      s4.write(90+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180+2*lag));
      s5.write(90+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180+1*lag));
      s6.write(90+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180+0*lag));    
      s7.write(90+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180-1*lag));
      s8.write(90+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180-2*lag));    
      s9.write(90+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180-3*lag));
      s10.write(90+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180-4*lag));
      s11.write(90+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180-5*lag));    
      s12.write(90+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180-6*lag));     
    } 
    }


    if (wallDistanceLeft <= wallDistanceRight) {
  
// Reverse and turn right
// Reverse
    for(counter = 360; counter > 0; counter -= 1)  {
      delay(delayTime);
      s1.write(90+offset+amplitude*cos(frequency*counter*3.14159/180+5*lag));
      s2.write(90+offset+amplitude*cos(frequency*counter*3.14159/180+4*lag));
      s3.write(90+offset+amplitude*cos(frequency*counter*3.14159/180+3*lag));
      s4.write(90+amplitude*cos(frequency*counter*3.14159/180+2*lag));
      s5.write(90+amplitude*cos(frequency*counter*3.14159/180+1*lag));
      s6.write(90+amplitude*cos(frequency*counter*3.14159/180+0*lag));    
      s7.write(90+amplitude*cos(frequency*counter*3.14159/180-1*lag));
      s8.write(90+amplitude*cos(frequency*counter*3.14159/180-2*lag));    
      s9.write(90+amplitude*cos(frequency*counter*3.14159/180-3*lag));
      s10.write(90+amplitude*cos(frequency*counter*3.14159/180-4*lag));
      s11.write(90+amplitude*cos(frequency*counter*3.14159/180-5*lag));    
      s12.write(90+amplitude*cos(frequency*counter*3.14159/180-6*lag));     
    }    
// Turn right
// Ramp up turn offset
    for(counter = 0; counter < 10; counter += 1)  {
      delay(delayTime);
      s1.write(90+offset+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180+5*lag));
      s2.write(90+offset+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180+4*lag));
      s3.write(90+offset+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180+3*lag));
      s4.write(90+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180+2*lag));
      s5.write(90+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180+1*lag));
      s6.write(90+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180+0*lag));    
      s7.write(90+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180-1*lag));
      s8.write(90+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180-2*lag));    
      s9.write(90+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180-3*lag));
      s10.write(90+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180-4*lag));
      s11.write(90+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180-5*lag));    
      s12.write(90+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180-6*lag));     
    }  
// Continue right turn
    for(counter = 11; counter < 350; counter += 1)  {
      delay(delayTime);
      s1.write(90+offset+rightOffset+amplitude*cos(frequency*counter*3.14159/180+5*lag));
      s2.write(90+offset+rightOffset+amplitude*cos(frequency*counter*3.14159/180+4*lag));
      s3.write(90+offset+rightOffset+amplitude*cos(frequency*counter*3.14159/180+3*lag));
      s4.write(90+rightOffset+amplitude*cos(frequency*counter*3.14159/180+2*lag));
      s5.write(90+rightOffset+amplitude*cos(frequency*counter*3.14159/180+1*lag));
      s6.write(90+rightOffset+amplitude*cos(frequency*counter*3.14159/180+0*lag));    
      s7.write(90+rightOffset+amplitude*cos(frequency*counter*3.14159/180-1*lag));
      s8.write(90+rightOffset+amplitude*cos(frequency*counter*3.14159/180-2*lag));    
      s9.write(90+rightOffset+amplitude*cos(frequency*counter*3.14159/180-3*lag));
      s10.write(90+rightOffset+amplitude*cos(frequency*counter*3.14159/180-4*lag));
      s11.write(90+rightOffset+amplitude*cos(frequency*counter*3.14159/180-5*lag));    
      s12.write(90+rightOffset+amplitude*cos(frequency*counter*3.14159/180-6*lag));     
    }    
// Ramp down turn offset
    for(counter = 350; counter < 360; counter += 1)  {
      delay(delayTime);
      s1.write(90+offset+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180+5*lag));
      s2.write(90+offset+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180+4*lag));
      s3.write(90+offset+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180+3*lag));
      s4.write(90+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180+2*lag));
      s5.write(90+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180+1*lag));
      s6.write(90+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180+0*lag));    
      s7.write(90+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180-1*lag));
      s8.write(90+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180-2*lag));    
      s9.write(90+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180-3*lag));
      s10.write(90+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180-4*lag));
      s11.write(90+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180-5*lag));    
      s12.write(90+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180-6*lag));     
    } 
    }   
  
  }
   
}
