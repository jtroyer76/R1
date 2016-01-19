#ifndef ICONTROLLER_H
#define ICONTROLLER_H

#include <Arduino.h>

class IController
{
  public:
    virtual void Execute() = 0;
};

#endif
