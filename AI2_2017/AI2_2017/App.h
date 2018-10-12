/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file App.h
 * @author Marco "Swampy" Millan
 * @date 2018/09/27 2018
 * @brief the App FSM which we use to activate the app and run around it
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "State.h"
#include "Screen.h"

/**
* Description:
*   App state machine that is in charge of running the game app etc
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
  bool
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
   * Default Font for testing
   */
  sf::Font m_defaultFont;

  /**
   * State stack that checks the order of objects
   */
  std::stack<State*> m_stateStack;

  /**
   * the pointer to the current state the machine is
   */
  State* m_currentState;
  
  /**
   * The graphics API wrapped in this thing
   */
  Screen m_screen;

  /**
   * all states possibles for this FSM
   */

  /**
   * pointer member to Logo State
   */
  Logo_State*      m_logoS;

  /**
   * pointer member to Play State
   */
  Play_State*      m_playS;

  /**
   * pointer member to Help State
   */
  Help_State*      m_helpS;

  /**
   * pointer member to Menu State
   */
  Menu_State*      m_menuS;

  /**
   * pointer member to Sound State
   */
  Sound_State*     m_sounS;

  /**
   * pointer member to Pause State
   */
  Pause_State*     m_pausS;

  /**
   * pointer member to Options State
   */
  Options_State*   m_optnS;

  /**
   * pointer member to Graphics State
   */
  Graphics_State*  m_grapS;

  /**
   * pointer member to GamePlay State
   */
  GamePlay_State*  m_gameS;

  /**
   * pointer member to GameOver State
   */
  GameOver_State*  m_overS;

};
