// KML
// 2012-12-30
// Based on example code at http://www.ladyada.net/make/mshield/use.html

#include <AFMotor.h>

AF_DCMotor motor(2, MOTOR12_64KHZ); // create motor #2, 64KHz pwm

void wiggle();

void setup() {
  Serial.begin(9600);
  Serial.println("Motor test!");
  
  motor.setSpeed(150); // max 255
}

void loop() {
  Serial.print("tick");
  
  motor.run(FORWARD);      // turn it on going forward
  delay(1000);

  Serial.print("tock");
  motor.run(BACKWARD);     // the other way
  delay(1000);
  
  Serial.print("tack");
  motor.run(RELEASE);      // stopped
  delay(1000);
}

// 
void wiggle() {
  motor.run(FORWARD);
  delay(50)
  motor.run(BACKWARD);
  delay(30)
  motor.run(FORWARD);
  delay(50)
  motor.run(BACKWARD);
  delay(30)
  motor.run(RELEASE);
  delay(1500)
}
