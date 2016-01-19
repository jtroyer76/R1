#ifndef ROBOT_H
#define ROBOT_H

#include "IController.h"
#include "IBehavior.h"

#include "SpeedController.h"
#include "PositionController.h"

#define SPEED_CONTROLLER_INDEX 0
#define POSITION_CONTROLLER_INDEX 1

#define MAX_CONTROLLERS 5
#define MAX_BEHAVIORS 16

class Robot
{
  public:
    static Robot* Instance();
    ~Robot();

    SpeedController* GetSpeedController();
    PositionController* GetPositionController();
        
    void AddController(IController* controller);
    void AddBehavior(IBehavior* behavior);
    
    void Run();

  private:
    static Robot* _Instance;
    Robot();
    IBehavior* _ActiveBehavior;
    IController* _Controllers[MAX_CONTROLLERS];
    IBehavior* _Behaviors[MAX_BEHAVIORS];      
};

#endif
