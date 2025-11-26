#include <Servo.h>

int receivedID = -1;
bool taskRunning = false;

Servo m2;
Servo g1;
Servo b1;

void setup() {
  Serial.begin(9600);

  m2.attach(4);
  g1.attach(8);
  b1.attach(5);


  b1.write(0);
  m2.write(90);    // arm up
  delay(1000);
  g1.write(180);   // gripper close
  delay(200);
  g1.write(90);
}

void loop() {

  // ------------------------------------
  // Check if Python sent a new ID
  // ------------------------------------
  if (!taskRunning && Serial.available() > 0) {
    receivedID = Serial.parseInt();
    if (receivedID > 0) {
      taskRunning = true;
      if (receivedID == 1 || receivedID == 2 ) {
        runTask(receivedID);
      }
      else {
          Serial.println("DONE");
          taskRunning = false;

      }
    }
  }
}


// -----------------------------------------
// FUNCTION: RUN THE ACTION BASED ON ID
// -----------------------------------------
void runTask(int ID) {
  Serial.print("Starting task for ID ");
  Serial.println(ID);

  // Pick sequence
  g1.write(0); delay(200); g1.write(90);
  m2.write(30); delay(2000);
  g1.write(180); delay(200); g1.write(90);
  m2.write(70); delay(1000);

  // ROTATION DELAY BASED ON ID
  int rotate = 500; // default  b1.write(90);

  if (ID == 1)       rotate = 60;
  else if (ID == 2)  rotate = 90;
  else if (ID == 3)  rotate = 120;

  Serial.print("Applying delay: ");
  Serial.println(rotate);

  b1.write(rotate);
  delay(1000);
  

  // Place sequence
  m2.write(30); delay(1000);
  g1.write(0); delay(200); g1.write(90);
  m2.write(90); delay(2000);
  g1.write(180); delay(200); g1.write(90);

  // Reset rotation
  b1.write(-rotate); 
  delay(1000);


  Serial.println("DONE");
  taskRunning = false;
}
