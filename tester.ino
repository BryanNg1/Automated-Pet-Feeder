#include <Stepper.h>
#include <arduino-timer.h>
#define TWELVE_HRS 43200000UL
#define TWENTYFOUR_HRS 86400000UL
unsigned long startTime;
int stepsperrev=2048;
int motorspeed=5;
//long double deltime=60000UL;
Stepper myStepper(stepsperrev, 9,11,10,12);
void setup(){
  startTime=millis();
  Serial.begin(9600);
  myStepper.setSpeed(motorspeed);
}

void loop(){
  if(millis()-startTime>TWENTYFOUR_HRS)
  {
  myStepper.step(stepsperrev/5);
  //delay(deltime);
  //auto timer = timer_create_default();
  startTime=millis();
  }
}
