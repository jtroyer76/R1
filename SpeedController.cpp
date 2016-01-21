
#include "SpeedController.h"
#include "encoder.h"

#include <PID_v1.h>

#include <Arduino.h>

#define LEFT_PWM_PIN 6
#define LEFT_DIRECTION_PIN 7
#define RIGHT_PWM_PIN 5
#define RIGHT_DIRECTION_PIN 4

#define MINIMUM_SPEED_PWM 100
#define MAXIMUM_SPEED_PWM 255

#define MAX_TICK_RATE 100
#define MAX_PULSE_WIDTH 160

#define K_PRO 3
#define K_DRV 4

void SpeedController::SetSpeed(char Speed, char TurnRate)
{
  char leftSpeed = Speed + TurnRate;
  char rightSpeed = Speed - TurnRate;

  _LeftDirection = 1;
  if (leftSpeed < 0) _LeftDirection = -1;
  _ReqLeftSpeed = abs(leftSpeed);

  _RightDirection = 1;
  if (rightSpeed < 0 ) _RightDirection = -1;
  _ReqRightSpeed = abs(rightSpeed);
}

void SpeedController::CalculateSpeed()
{
  _LeftSpeed = 0;
  if (millis() - lastLeft < MAX_PULSE_WIDTH)
  {
    _LeftSpeed =  MAX_PULSE_WIDTH - LeftEncoder;
    _LeftSpeed = _LeftSpeed * _LeftDirection;
  }

  Serial.print("MeasuredLeft: ");
  Serial.println(_LeftSpeed);

  _RightSpeed = 0;
  if (millis() - lastRight < MAX_PULSE_WIDTH)
  {
    _RightSpeed = MAX_PULSE_WIDTH - RightEncoder;
    _RightSpeed = _RightSpeed * _RightDirection;
  }

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

//  int lf_error  = K_PRO * (_ReqLeftSpeed - _LeftSpeed);
//  _leftacc +=  ((lf_error / K_PRO) + ((lf_error - _leftlast) / K_DRV));
//  _leftlast = lf_error;
//  _leftacc += lf_error;
//
//  if (_leftacc > (MAX_TICK_RATE)) _leftacc = MAX_TICK_RATE;
//  else if (_leftacc < (-MAX_TICK_RATE * 256)) _leftacc = -MAX_TICK_RATE * 256;
//  
//  Serial.print("LPID: ");
//  Serial.print(lf_error);
//  Serial.print(" ");
//  Serial.println(_leftacc);   
//
//  pwmL(_leftacc); 
  
  // PID
  int lf_error, rt_error;

  lf_error = (_ReqLeftSpeed - _LeftSpeed) * 256;
  _leftacc +=  ((lf_error / K_PRO) + ((lf_error - _leftlast) / K_DRV));
  _leftlast = lf_error;
  if (_leftacc > (MAX_TICK_RATE * 256)) _leftacc = MAX_TICK_RATE * 256;
  else if (_leftacc < (-MAX_TICK_RATE * 256)) _leftacc = -MAX_TICK_RATE * 256;
  
  Serial.print("LPID: ");
  Serial.print(lf_error);
  Serial.print(" ");
  Serial.print(_leftacc);
  Serial.print(" ");
  Serial.println(_leftlast);  

  rt_error = (_ReqRightSpeed - _RightSpeed) * 256;
  _rightacc += ((rt_error / K_PRO) + ((rt_error - _rightlast) / K_DRV));
  _rightlast = rt_error;

  if (_rightacc > (MAX_TICK_RATE * 256)) _rightacc = MAX_TICK_RATE * 256;
  else if (_rightacc < (-MAX_TICK_RATE * 256)) _rightacc = -MAX_TICK_RATE * 256;

  pwmL(_leftacc/256);
  pwmR(_rightacc/256);

}



void SpeedController::pwmR(char pwm)
{
  if(pwm < 0)
    analogWrite(RIGHT_DIRECTION_PIN, 1);
  else
    analogWrite(RIGHT_DIRECTION_PIN, 0);

  byte pwmVal = map(abs(pwm), 0, 100, MINIMUM_SPEED_PWM, MAXIMUM_SPEED_PWM);
  analogWrite(RIGHT_PWM_PIN, pwmVal);
}

void SpeedController::pwmL(char pwm)
{
  if(pwm < 0)
    analogWrite(LEFT_DIRECTION_PIN, 1);
  else
    analogWrite(LEFT_DIRECTION_PIN, 0);

  byte pwmVal = map(abs(pwm), 0, 100, MINIMUM_SPEED_PWM, MAXIMUM_SPEED_PWM);
  analogWrite(LEFT_PWM_PIN, pwmVal);
}


