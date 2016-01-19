#include "robot.h"

// Initalize the instance pointer... static initialization
Robot* Robot::_Instance = NULL;

Robot* Robot::Instance()
{
  if(!Robot::_Instance)
    Robot::_Instance = new Robot();

  return _Instance;
}

Robot::Robot()
{
  _ActiveBehavior = NULL;

  for (int i = 0; i < MAX_BEHAVIORS; i++)
    _Behaviors[i] = NULL;

  for (int i = 0; i < MAX_CONTROLLERS; i++)
    _Controllers[i] = NULL;

  _Controllers[SPEED_CONTROLLER_INDEX] = new SpeedController();
  _Controllers[POSITION_CONTROLLER_INDEX] = new PositionController();
}

Robot::~Robot()
{
  int i = 0;
  while (_Controllers[i])
    delete _Controllers[i++];

  i = 0;
  while (_Behaviors[i])
    delete _Behaviors[i++];
}

SpeedController* Robot::GetSpeedController()
{
  return (SpeedController*)(_Controllers[SPEED_CONTROLLER_INDEX]);
}

PositionController* Robot::GetPositionController()
{
  return (PositionController*)(_Controllers[POSITION_CONTROLLER_INDEX]);
}

void Robot::AddController(IController* controller)
{
  // Move to first empty element
  int i = 0;
  while (_Controllers[i++])

    // Add the controller to the list
    _Controllers[i] = controller;
}

void Robot::AddBehavior(IBehavior* behavior)
{
  // Move to the first empty element
  int i = 0;
  while (_Behaviors[i++])

    // Add the behavior to the list
    _Behaviors[i] = behavior;
}

void Robot::Run()
{
  // Run all behaviors
  int i = 0;
  while (_Behaviors[i])
  {
    if (_Behaviors[i]->Assert())
    {
      if(_ActiveBehavior)
        _ActiveBehavior->Suppress();
        
      _ActiveBehavior = _Behaviors[i];
      _Behaviors[i]->Execute();
      break;
    }

    i++;
  }

  // Run all controllers
  i = 0;
  while (_Controllers[i])
    _Controllers[i++]->Execute();
}

