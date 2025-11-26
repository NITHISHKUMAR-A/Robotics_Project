/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/

#include <Servo.h>

int i = 0 ;

 
Servo m2;
Servo g1;
Servo b1;// create servo object to control a servo
// twelve servo objects can be created on most boards

    // variable to store the servo position

void setup() {
  
  m2.attach(4);
  g1.attach(8);
  b1.attach(5);
 // m1.write(10); 
    m2.write(90); /// arm up  
    delay(1000);
    g1.write(180);
    delay(200); // gripper close
    g1.write(90);
    
  
  // attaches the servo on pin 9 to the servo object
}

void loop() {

//  m2.write(20);
//  delay(500);
////  m1.write(90);
////  delay(2000);
 
//  
if (i == 0){
//
    g1.write(0);
    delay(200); // open
    g1.write(90);
    delay(200);
    m2.write(30); /// arm down 
    delay(2000);
//   
//
////    //////////
////     
//
//    /////////
    g1.write(180);
    delay(200); // gripper close
    g1.write(90);
    delay(200);
//    ///////// 
    m2.write(70); /// arm up  
    delay(1000);
//    /////////
    b1.write(0);
    delay(500);  /// arm rotate
    b1.write(90);
//    /////////
//     
    m2.write(30); /// arm down 
    delay(1000);
//    /////////
    g1.write(0);
    delay(200); //  gripper open
    g1.write(90);
    delay(1000);
//    //////////
//     
    m2.write(90); /// arm up  
    delay(2000);
//    /////////
    g1.write(180);
    delay(200); // gripper close
    g1.write(90);
//    
//    /////////
    b1.write(180);
    delay(500);  /// arm rotate
    b1.write(90);
    i+=1;
//    ///////// 
}


    
  }