// KML
// 2012-12-30
// Based on example code at http://www.ladyada.net/make/mshield/use.html

#include <AFMotor.h>

#define MINUTE_OF_MILLISECONDS 60000
#define HOUR_OF_MILLISECONDS (MINUTE_OF_MILLISECONDS * 60)

AF_DCMotor motor(2, MOTOR12_64KHZ); // create motor #2, 64KHz pwm

void rest();
void play();
void randomAction(boolean brief); // true for a quick action, false for a longer one
void wiggle();

void setup() {
  motor.setSpeed(150); // max 255
}

void loop() {
  play();
  rest();
}

void rest() {
  delay(2 * HOUR_OF_MILLISECONDS);
}

void play() {
  for (int i = 0; i < 10; i++) {
    randomAction(true);
  } 
  
  motor.run(RELEASE);
}

int randomAction(boolean brief) { // returns how long it ran for
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
  return duration;
}

void wiggle() {
  ; // todo
}
