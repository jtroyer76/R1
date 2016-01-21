#ifndef SPEED_CONTROLLER_H
#define SPEED_CONTROLLER_H

#include "IController.h"

#include <PID_v1.h>
#include <Arduino.h>

#define SLOW_SPEED 25
#define HALF_SPEED 50
#define FULL_SPEED 80

#define BACKUP_SLOW -25

#define FORWARD 0
#define TURN_RIGHT 25
#define TURN_LEFT -25

#define STOP 0

class SpeedController : public IController
{
  public:
    SpeedController();
    void SetSpeed(char Speed, char TurnRate);    
    void Execute();

  private:
    void CalculateSpeed();
    void pwmR(double pwm);
    void pwmL(double pwm);

    char _LeftDirection;
    char _RightDirection;

    double _LeftSpeed;
    double _RightSpeed;

    double _ReqLeftSpeed;
    double _ReqRightSpeed;

    double _LeftMotor;

    PID _LeftPID;    
};

#endif
