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

/**
* Description:
*   App state machine thatis in charge of running the game app etc
* Sample usage:
* 	App.onUpdate() checks for inputs or changes in states
*/
class App
{
 public:
  /**
   * Default constructor
   */
  App() = default;

  /**
   * Default destructor
   */
  ~App() {};
  
  /**
   * Sets up variables, initializes data ,etc
   */
  void
  onEntry();

  /**
   * Checks for inputs or changes in states
   */
  void 
  onUpdate();
  
  /**
   * Sets the state the m_current pointer is pointing to
   */
  void 
  setState(State* state);
  

  /**
   * Closes the program
   */
  void
  onExit();

  /**
   * Member declarations
   */

 public:

  /**
   * State stack that checkes the order of objects
   */
  std::stack<State*> m_stateStack;

  /**
   * the pointer to the current state de machin is
   */
  State* m_currentState;
  
  /**
   * The graphics API wrapped in this thing
   */
  Screen m_screen;
  

  /**
   * all states possibles for this FSM
   */
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
