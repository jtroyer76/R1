#include "encoder.h"

#include <Arduino.h>

volatile int LeftEncoder = MAX_PULSE_WIDTH;
volatile int RightEncoder = MAX_PULSE_WIDTH;

volatile unsigned long lastLeft = 0;
volatile unsigned long lastRight = 0;

void UpdateLeftEncoder()
{
  unsigned long now = millis();
  (now - lastLeft) < MAX_PULSE_WIDTH ? 
  LeftEncoder = now - lastLeft :  LeftEncoder = MAX_PULSE_WIDTH;

  lastLeft = now;
}

void UpdateRightEncoder()
{
  unsigned long now = millis();
  (now - lastRight) < MAX_PULSE_WIDTH ?
  RightEncoder = now - lastRight : RightEncoder = MAX_PULSE_WIDTH;

  lastRight = now;
}

