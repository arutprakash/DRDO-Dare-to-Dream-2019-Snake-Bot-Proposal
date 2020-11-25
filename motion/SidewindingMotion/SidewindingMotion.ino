/*
Sidewind motion for a snake robot with 12 segments
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
int counter = 0; // Loop counter variable
float lag = 1.05; // Phase lag between segments
int frequency = 1; // Oscillation frequency of segments.
int ampHor = 40; // Horizontal amplitude of the sidewind motion of the snake
int ampVert = 40; // Vertical amplitude of sidewind motion of the snake
int offset = 0;
int delayTime = 7; // Delay between limb movements
int startPause = 5000;  // Delay time to position robot
  
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
 
//Put snake in starting position
   s1.write(90+ampHor*cos(0*lag));
   s3.write(90+ampHor*cos(1*lag)); 
   s5.write(90+ampHor*cos(2*lag));
   s7.write(90+ampHor*cos(3*lag));
   s9.write(90+ampHor*cos(4*lag));
   s11.write(90+ampHor*cos(5*lag));
   
   s2.write(90+ampVert*cos(0*lag));
   s4.write(90+ampVert*cos(1*lag));
   s6.write(90+ampVert*cos(2*lag));
   s8.write(90+ampVert*cos(3*lag));
   s10.write(90+ampVert*cos(4*lag));
   s12.write(90+ampVert*cos(5*lag));
 
   delay(startPause);  // Pause to position robot
} 

  
void loop() 
{
// Serpentine motion
  for(counter = 0; counter < 360; counter += 1)  {
    delay(delayTime);
    s1.write(90+offset+ampHor*cos(frequency*counter*3.14159/180-0*lag));
    s3.write(90+offset+ampHor*cos(frequency*counter*3.14159/180-1*lag));
    s5.write(90+offset+ampHor*cos(frequency*counter*3.14159/180-2*lag));
    s7.write(90+offset+ampHor*cos(frequency*counter*3.14159/180-3*lag));
    s9.write(90+offset+ampHor*cos(frequency*counter*3.14159/180-4*lag));
    s11.write(90+offset+ampHor*cos(frequency*counter*3.14159/180-5*lag)); 
    
    s2.write(90+offset+ampVert*cos(frequency*counter*3.14159/180-0*lag));
    s4.write(90+offset+ampVert*cos(frequency*counter*3.14159/180-1*lag));    
    s6.write(90+offset+ampVert*cos(frequency*counter*3.14159/180-2*lag));
    s8.write(90+offset+ampVert*cos(frequency*counter*3.14159/180-3*lag));
    s10.write(90+offset+ampVert*cos(frequency*counter*3.14159/180-4*lag));    
    s12.write(90+offset+ampVert*cos(frequency*counter*3.14159/180-5*lag));     
  }  
}
