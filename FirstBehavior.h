#ifndef SIMPLE_BEHAVIOR_H
#define SIMPLE_BEHAVIOR_H

#include "IBehavior.h"

class FirstBehavior : public IBehavior 
{
  public:
    virtual bool Assert();
    virtual void Execute();
    virtual void Suppress();
};

#endif
