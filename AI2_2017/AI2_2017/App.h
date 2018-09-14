/************************************************************************/
/**
 * 
 */                                                                      
/************************************************************************/

#pragma once
#include "State.h"
#include <stack>
class App
{
public:

  App() = default;
  ~App() {};
  void Update();
  void SetState(State* state);
  State* m_currentState;
  
};

