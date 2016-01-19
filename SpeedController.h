#ifndef SPEED_CONTROLLER_H
#define SPEED_CONTROLLER_H

#include "IController.h"

#include <Arduino.h>

enum Movement {
  SLOW_SPEED,
  HALF_SPEED,
  FULL_SPEED,
  TURN_RIGHT,
  TURN_LEFT,
  BACKUP_SLOW,
  STOP
};

class SpeedController : public IController
{
  public:
    void Go(Movement move);
    void SetSpeed(char Left, char Right);
    void Execute();

  private:
    void CalculateSpeed();
    void pwmR(char pwm);
    void pwmL(char pwm);

    char _LeftSpeed;
    char _RightSpeed;

    char _LeftDirection;
    char _RightDirection;
};

#endif
