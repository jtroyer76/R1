#ifndef IBEHAVIOR_H
#define IBEHAVIOR_H

class IBehavior
{
  public:
    virtual bool Assert() = 0;
    virtual void Execute() = 0;
    virtual void Suppress() = 0;
};

#endif
