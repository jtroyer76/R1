
#include "Encoder.h"
#include "robot.h"

#include "FirstBehavior.h"

void setup(void)
{
  attachInterrupt(LEFT_ENCODER_PIN, UpdateLeftEncoder, CHANGE);
  attachInterrupt(RIGHT_ENCODER_PIN, UpdateRightEncoder, CHANGE);
  
  Robot::Instance()->AddBehavior(new FirstBehavior());
}

void loop(void)
{
  Robot* r1 = Robot::Instance();
  
  while(1)
    r1->Run();
}
