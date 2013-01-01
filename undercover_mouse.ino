// KML
// 2012-12-30
// Based on example code at http://www.ladyada.net/make/mshield/use.html

#include <AFMotor.h>

AF_DCMotor motor(2, MOTOR12_64KHZ); // create motor #2, 64KHz pwm

void play();
void randomAction(boolean brief); // true for a quick action, false for a longer one
void wiggle();

void setup() {
  Serial.begin(9600);
  Serial.println("Motor test!");
  
  motor.setSpeed(150); // max 255
}

void loop() {
  motor.run(RELEASE);
  wiggle(); 
  motor.run(RELEASE);
  delay(5000);
  
  /*
  Serial.print("tick");
  
  motor.run(FORWARD);      // turn it on going forward
  delay(1000);

  Serial.print("tock");
  motor.run(BACKWARD);     // the other way
  delay(1000);
  
  Serial.print("tack");
  motor.run(RELEASE);      // stopped
  delay(1000);
  */
}

// 
void play() {
  for (int i = 0; i < 10; i++) {
    randomAction(true);
  }  
}

void randomAction(boolean brief) {
  int duration = random(50, 1000);
  if (!brief) {
    duration *= 10;
  }
  
  int action = random(1,3);  
  if (action == 3) { // BRAKE is not used
    action = 4; // but RELEASE is.
  }
  /* from AFMotor.h:
  #define FORWARD 1
  #define BACKWARD 2
  #define BRAKE 3
  #define RELEASE 4
  */
  
  motor.run(action);
  delay(duration);
}

void wiggle() {
  ; // todo
}
