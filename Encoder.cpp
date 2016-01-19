#include "Encoder.h"

volatile int LeftEncoder = 0;
volatile int RightEncoder = 0;

void UpdateLeftEncoder()
{
  LeftEncoder++;
}

void UpdateRightEncoder()
{
  RightEncoder++;
}


