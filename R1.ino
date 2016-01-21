
#include "encoder.h"
#include "robot.h"

#include "FirstBehavior.h"

SpeedController spd;
unsigned long lastLoopTime = 0;

void setup(void)
{
  attachInterrupt(LEFT_ENCODER_PIN, UpdateLeftEncoder, RISING);
  attachInterrupt(RIGHT_ENCODER_PIN, UpdateRightEncoder, RISING);
  
  //Robot::Instance()->AddBehavior(new FirstBehavior());

   Serial.begin(115200); 
   spd.SetSpeed(FULL_SPEED, FORWARD);    
}

void loop(void)
{
  if(millis() - lastLoopTime > 50)
  {
    spd.Execute();      
    lastLoopTime = millis();
  }   
}
