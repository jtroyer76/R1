#include "SpeedController.h"
#include "Encoder.h"

#include <Arduino.h>

#define LEFT_PWM_PIN 6
#define LEFT_DIRECTION_PIN 7
#define RIGHT_PWM_PIN 5
#define RIGHT_DIRECTION_PIN 4

#define MINIMUM_SPEED_PWM 100
#define MAXIMUM_SPEED_PWM 255

#define FORWARD 1
#define REVERSE -1

#define MAX_TICK_RATE 100

SpeedController::SpeedController() :
  _LeftPID(&_LeftSpeed, &_LeftMotor, &_ReqLeftSpeed, 5, 0, 0, DIRECT),
  _RightPID(&_RightSpeed, &_RightMotor, &_ReqRightSpeed, 5, 0, 0, DIRECT)
{
  _LeftPID.SetSampleTime(50);
  _LeftPID.SetMode(AUTOMATIC);
  _LeftPID.SetOutputLimits(0, 100);

  _RightPID.SetSampleTime(50);
  _RightPID.SetMode(AUTOMATIC);
  _RightPID.SetOutputLimits(0, 100);
}

void SpeedController::SetSpeed(char Speed, char TurnRate)
{
  char leftSpeed = Speed + TurnRate;
  char rightSpeed = Speed - TurnRate;

  leftSpeed > 0 ? _LeftDirection = FORWARD : _LeftDirection = REVERSE;
  _ReqLeftSpeed = abs(leftSpeed);

  rightSpeed > 0 ? _RightDirection = FORWARD : _RightDirection = REVERSE;
  _ReqRightSpeed = abs(rightSpeed);
}

void SpeedController::CalculateSpeed()
{
  _LeftSpeed =  MAX_PULSE_WIDTH - LeftEncoder;
  _LeftSpeed = _LeftSpeed * _LeftDirection;

  Serial.print("MeasuredLeft: ");
  Serial.println(_LeftSpeed);

  _RightSpeed = MAX_PULSE_WIDTH - RightEncoder;
  _RightSpeed = _RightSpeed * _RightDirection;

  Serial.print("MeasuredRight: ");
  Serial.println(_RightSpeed);
}

void SpeedController::Execute()
{
  Serial.println("-------------------------------------------");
  CalculateSpeed();

  Serial.print("ReqLeft: ");
  Serial.println(_ReqLeftSpeed);

  Serial.print("ReqRight: ");
  Serial.println(_ReqRightSpeed);

  _LeftPID.Compute();
  _RightPID.Compute();

  pwmL(_LeftMotor);
  pwmR(_RightMotor);
}

void SpeedController::pwmR(double pwm)
{
  // Set Direction
  _RightDirection == FORWARD ? digitalWrite(RIGHT_DIRECTION_PIN, HIGH) : digitalWrite(RIGHT_DIRECTION_PIN, LOW);

  // Set Speed
  byte pwmVal = map(abs(pwm), 0, 100, MINIMUM_SPEED_PWM, MAXIMUM_SPEED_PWM);
  analogWrite(RIGHT_PWM_PIN, pwmVal);
}

void SpeedController::pwmL(double pwm)
{
  // Set Direction
  _LeftDirection == FORWARD ? digitalWrite(LEFT_DIRECTION_PIN, HIGH) : digitalWrite(LEFT_DIRECTION_PIN, LOW);

  // Set Speed
  byte pwmVal = map(abs(pwm), 0, 100, MINIMUM_SPEED_PWM, MAXIMUM_SPEED_PWM);
  analogWrite(LEFT_PWM_PIN, pwmVal);
}


