// KML
// 2012-12-30
// Based on example code at http://www.ladyada.net/make/mshield/use.html

#include <AFMotor.h>

#define MINUTE_OF_MILLISECONDS 60000
#define HOUR_OF_MILLISECONDS (MINUTE_OF_MILLISECONDS * 60)

AF_DCMotor motor(2, MOTOR12_64KHZ); // create motor #2, 64KHz pwm

void setup() {
  motor.setSpeed(50); // max 255
}

void loop() {
  play();
  rest();
}

void rest() {
  delay(2 * MINUTE_OF_MILLISECONDS);
}

void play() {
  unsigned long elapsed = 0;
  while (elapsed < (1 * MINUTE_OF_MILLISECONDS)) {
    boolean wiggleThisTime = (random(0,10) == 0); // wiggle occasionally
    
    elapsed += wiggleThisTime ? wiggle() : randomAction();
  }

  motor.run(RELEASE);
}

int randomAction() { // returns how long it ran for
  /* from AFMotor.h:
  #define FORWARD 1
  #define BACKWARD 2
  #define BRAKE 3
  #define RELEASE 4
  */
  int action = random(1,4);  
  if (action == 3) { // BRAKE is not used
    action = 4; // but RELEASE is.
  }
  
  motor.run(action);
  int duration = random(50, 1000);
  delay(duration);
  return duration;
}

int wiggle() {
  const int stepDuration = 250;
  int steps = random(3,7);
  
  for (int i = 0; i < steps; i++) {
    int action = (i % 2) ? FORWARD : BACKWARD;
    motor.run(action);
    delay(stepDuration);
  }
  
  return stepDuration * steps;
}
