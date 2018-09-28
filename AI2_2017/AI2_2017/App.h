/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file App.h
 * @author Marco "Swampy" Millan
 * @date 2018/09/27 2018
 * @brief 
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "State.h"
#include "Screen.h"

class App
{
 public:
  
  App() = default;
  ~App() {};
  

  void
  onEntry();

  void 
  onUpdate();
  
  void 
  setState(State* state);
  
  void
  onExit();

 public:
  std::stack<State*> m_stateStack;
  State* m_currentState;
  Screen m_screen;
  
  Logo_State*      m_logoS;
  Play_State*      m_playS;
  Help_State*      m_helpS;
  Menu_State*      m_menuS;
  Sound_State*     m_sounS;
  Pause_State*     m_pausS;
  Options_State*   m_optnS;
  Graphics_State*  m_grapS;
  GamePlay_State*  m_gameS;
  GameOver_State*  m_overS;


};

