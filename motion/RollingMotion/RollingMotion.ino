/*
Rectilinear motion file for snake robot with 12 segments
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

  
// Define variables
int flex = 45; // Angle to flex a joint
int delayTime = 5; // Delay between limb movements
int startPause = 5000; // Delay to allow robot placement before movement
int pos = 0;  // Loop counter
int smoothnessDelay = 15; 
int rollState = 0;

  
void setup() 
{ 
  
// Attach segments to PWM pins  
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

    
// Put snake in straight starting position
   s1.write(90);
   s2.write(90); 
   s3.write(90);
   s4.write(90);
   s5.write(90);
   s6.write(90);
   s7.write(90);
   s8.write(90);
   s9.write(90);
   s10.write(90);
   s11.write(90);
   s12.write(90);


// Delay to give time to position robot  
   delay(startPause);
} 
  
  
void loop() 
{ 
// If snake is straight, put it into rolling position
  if (rollState == 0)
  {
    for(pos = 0; pos < flex; pos +=  1)
    {
      s1.write(90);
      s2.write(90); 
      s3.write(90-pos);
      s4.write(90-2*pos);
      s5.write(90-pos);
      s6.write(90);
      s7.write(90);
      s8.write(90);
      s9.write(90-pos);
      s10.write(90-2*pos);
      s11.write(90-pos);
      s12.write(90);
      delay(smoothnessDelay);
    }
    rollState = 1-rollState;
    delay(1000);
  }    
  
  
// Step 1  
    delay(delayTime);
    for(pos = 0; pos < flex; pos +=  1)
    { 
      s12.write(90-pos); 
      s11.write(90-flex-pos);
      s10.write(90-2*flex+pos);
      s9.write(90-flex+pos);
      s6.write(90-pos);
      s5.write(90-flex-pos);
      s4.write(90-2*flex+pos);
      s3.write(90-flex+pos);
      delay(smoothnessDelay);
    }    
// Step 2    
    delay(delayTime);
    for(pos = 0; pos < flex; pos +=  1)
    { 
      s1.write(90-pos); 
      s12.write(90-flex-pos);
      s11.write(90-2*flex+pos);
      s10.write(90-flex+pos);
      s7.write(90-pos);
      s6.write(90-flex-pos);
      s5.write(90-2*flex+pos);
      s4.write(90-flex+pos);
      delay(smoothnessDelay);
    }    
// Step 3
    delay(delayTime);
    for(pos = 0; pos < flex; pos +=  1)
    { 
      s2.write(90-pos); 
      s1.write(90-flex-pos);
      s12.write(90-2*flex+pos);
      s11.write(90-flex+pos);
      s8.write(90-pos);
      s7.write(90-flex-pos);
      s6.write(90-2*flex+pos);
      s5.write(90-flex+pos);
      delay(smoothnessDelay);
    }    
// Step 4
    delay(delayTime);
    for(pos = 0; pos < flex; pos +=  1)
    { 
      s3.write(90-pos); 
      s2.write(90-flex-pos);
      s1.write(90-2*flex+pos);
      s12.write(90-flex+pos);
      s9.write(90-pos);
      s8.write(90-flex-pos);
      s7.write(90-2*flex+pos);
      s6.write(90-flex+pos);
      delay(smoothnessDelay);
    }    
// Step 5
    delay(delayTime);
    for(pos = 0; pos < flex; pos +=  1)
    { 
      s4.write(90-pos); 
      s3.write(90-flex-pos);
      s2.write(90-2*flex+pos);
      s1.write(90-flex+pos);
      s10.write(90-pos);
      s9.write(90-flex-pos);
      s8.write(90-2*flex+pos);
      s7.write(90-flex+pos);
      delay(smoothnessDelay);
    }    
// Step 6
    delay(delayTime);
    for(pos = 0; pos < flex; pos +=  1)
    { 
      s5.write(90-pos); 
      s4.write(90-flex-pos);
      s3.write(90-2*flex+pos);
      s2.write(90-flex+pos);
      s11.write(90-pos);
      s10.write(90-flex-pos);
      s9.write(90-2*flex+pos);
      s8.write(90-flex+pos);
      delay(smoothnessDelay);
    }   
// Step 7
    delay(delayTime);
    for(pos = 0; pos < flex; pos +=  1)
    { 
      s6.write(90-pos); 
      s5.write(90-flex-pos);
      s4.write(90-2*flex+pos);
      s3.write(90-flex+pos);
      s12.write(90-pos);
      s11.write(90-flex-pos);
      s10.write(90-2*flex+pos);
      s9.write(90-flex+pos);
      delay(smoothnessDelay);
    }     
// Step 8
    delay(delayTime);
    for(pos = 0; pos < flex; pos +=  1)
    { 
      s7.write(90-pos); 
      s6.write(90-flex-pos);
      s5.write(90-2*flex+pos);
      s4.write(90-flex+pos);
      s1.write(90-pos);
      s12.write(90-flex-pos);
      s11.write(90-2*flex+pos);
      s10.write(90-flex+pos);
      delay(smoothnessDelay);
    }    
 // Step 9
    delay(delayTime);
    for(pos = 0; pos < flex; pos +=  1)
    { 
      s8.write(90-pos); 
      s7.write(90-flex-pos);
      s6.write(90-2*flex+pos);
      s5.write(90-flex+pos);
      s2.write(90-pos);
      s1.write(90-flex-pos);
      s12.write(90-2*flex+pos);
      s11.write(90-flex+pos);
      delay(smoothnessDelay);
    }   
 // Step 10
    delay(delayTime);
    for(pos = 0; pos < flex; pos +=  1)
    { 
      s9.write(90-pos); 
      s8.write(90-flex-pos);
      s7.write(90-2*flex+pos);
      s6.write(90-flex+pos);
      s3.write(90-pos);
      s2.write(90-flex-pos);
      s1.write(90-2*flex+pos);
      s12.write(90-flex+pos);
      delay(smoothnessDelay);
    }   
 // Step 11
    delay(delayTime);
    for(pos = 0; pos < flex; pos +=  1)
    { 
      s10.write(90-pos); 
      s9.write(90-flex-pos);
      s8.write(90-2*flex+pos);
      s7.write(90-flex+pos);
      s4.write(90-pos);
      s3.write(90-flex-pos);
      s2.write(90-2*flex+pos);
      s1.write(90-flex+pos);
      delay(smoothnessDelay);
    }   
 // Step 12
    delay(delayTime);
    for(pos = 0; pos < flex; pos +=  1)
    { 
      s11.write(90-pos); 
      s10.write(90-flex-pos);
      s9.write(90-2*flex+pos);
      s8.write(90-flex+pos);
      s5.write(90-pos);
      s4.write(90-flex-pos);
      s3.write(90-2*flex+pos);
      s2.write(90-flex+pos);
      delay(smoothnessDelay);
    }     
}
