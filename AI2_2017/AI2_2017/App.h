#pragma once
#include "State.h"
#include "Screen.h"
class App
{
public:
  Screen m_screen;
  App();
  ~App() {};
  void onUpdate();
  void setState(State* state);
  std::stack<State*> m_stateStack;
  State* m_currentState;
  
};

