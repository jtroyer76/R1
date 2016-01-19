#ifndef POSITION_CONTROLLER_H
#define POSITION_CONTROLLER_H

#include "IController.h"

struct Position
{
  long X;
  long Y;
  short Theta;    
};

class PositionController : public IController
{
  public:
    Position GetPosition();
    void Execute();
};

#endif
