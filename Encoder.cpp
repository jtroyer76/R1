#include "encoder.h"

#include <Arduino.h>

volatile int LeftEncoder = 0;
volatile int RightEncoder = 0;

volatile unsigned long lastLeft = 0;
volatile unsigned long lastRight = 0;

void UpdateLeftEncoder()
{
  unsigned long now = millis();
  if(lastLeft != 0)
  {        
    LeftEncoder = now - lastLeft;
  }
  lastLeft = now;
}

void UpdateRightEncoder()
{
  // Get now 
  unsigned long now = millis();

  // Have to wait till next tick to calculate time diff
  if(lastRight != 0)
  {    
    RightEncoder = now - lastRight;  
  }
  lastRight = now;
}

