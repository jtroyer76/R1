#include "SpeedController.h"

#include "encoder.h"

#include <Arduino.h>

#define LEFT_PWM_PIN 5
#define LEFT_DIRECTION_PIN 4
#define RIGHT_PWM_PIN 6
#define RIGHT_DIRECTION_PIN 7

#define MINIMUM_SPEED_PWM 50
#define MAXIMUM_SPEED_PWM 255

#define K_PRO 3
#define K_DRV 3

void SpeedController::Go(Movement move)
{
  switch (move)
  {
    case SLOW_SPEED:
      SetSpeed(25, 25);
      break;
    case HALF_SPEED:
      SetSpeed(25, 25);
      break;
    case FULL_SPEED:
      SetSpeed(25, 25);
      break;
    case TURN_RIGHT:
      SetSpeed(25, 25);
      break;
    case TURN_LEFT:
      SetSpeed(25, 25);
      break;
    case BACKUP_SLOW:
      SetSpeed(25, 25);
      break;
    case STOP:
    default:
      SetSpeed(0, 0);
      break;
  }
}

void SpeedController::SetSpeed(char Left, char Right)
{
  _LeftSpeed = Left;
  _RightSpeed = Right;
//  // Stop
//  if (Left == 0)
//    analogWrite (LEFT_PWM_PIN, 0);
//
//  else
//  {
//    // Rotational Direction
//    if (Left > 0)
//      digitalWrite(LEFT_DIRECTION_PIN, HIGH);
//    else
//      digitalWrite(LEFT_DIRECTION_PIN, LOW);
//
//    // Speed
//    byte Lpwm = map(Left, 0, 100, MINIMUM_SPEED_PWM, MAXIMUM_SPEED_PWM);
//    analogWrite (LEFT_PWM_PIN, Lpwm);
//  }
//
//  // Stop
//  if (Right == 0)
//    analogWrite (LEFT_PWM_PIN, 0);
//
//  else
//  {
//    // Rotational Direction
//    if (Right > 0)
//      digitalWrite(RIGHT_DIRECTION_PIN, HIGH);
//    else
//      digitalWrite(RIGHT_DIRECTION_PIN, LOW);
//
//    // Speed
//    byte Rpwm = map(Right, 0, 100, MINIMUM_SPEED_PWM, MAXIMUM_SPEED_PWM);
//    analogWrite (RIGHT_PWM_PIN, Rpwm);
//  }
}

void SpeedController::Execute()
{
  _LeftSpeed = LeftEncoder * _LeftDirection;
  LeftEncoder = 0;
  _RightSpeed = RightEncoder * _RightDirection;  
  RightEncoder = 0;
}

void SpeedController::CalculateSpeed()
{

  
}

void SpeedController::pwmR(char pwm)
{
  analogWrite (RIGHT_PWM_PIN, pwm);
}

void SpeedController::pwmL(char pwm)
{
  analogWrite (LEFT_PWM_PIN, pwm);
}


