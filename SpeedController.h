#ifndef SPEED_CONTROLLER_H
#define SPEED_CONTROLLER_H

#include "IController.h"

#include <Arduino.h>

#define SLOW_SPEED 25
#define HALF_SPEED 50
#define FULL_SPEED 80

#define BACKUP_SLOW -10

#define FORWARD 0
#define TURN_RIGHT 25
#define TURN_LEFT -25

#define STOP 0

class SpeedController : public IController
{
  public:    
    void SetSpeed(char Speed, char TurnRate);    
    void Execute();

  private:
    void CalculateSpeed();
    void pwmR(char pwm);
    void pwmL(char pwm);

    char _LeftDirection;
    char _RightDirection;

    byte _LeftSpeed;
    byte _RightSpeed;

    byte _ReqLeftSpeed;
    byte _ReqRightSpeed;

    int _leftacc, _rightacc;  /* accumulators for motor output values */
    int _leftlast, _rightlast; /* history values for calculating derivative */
};

#endif
