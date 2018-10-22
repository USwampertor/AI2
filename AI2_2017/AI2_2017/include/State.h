/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file State.h
 * @author Marco "Swampy" Millan
 * @date 2018/09/27 2018
 * @brief the state class which all states are sons of
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#pragma once

#include "Utilities.h"

//forward declaration
class App;


/**
* State
* Description:
*   The states of the App FSM
* Sample usage:
* 	state menu brings the menu to the player
*/
class State 
{
 public:

  /**
   * Default constructor
   */
  State() {m_fsm = nullptr; };

  /**
   * Virtual Destructor for inheritance
   */
  virtual ~State() {};

  
  /**
   * @brief Overriden operator ==
   * @param the state of the fsm
   * @return true if both ids are the same
   * 
   */
  bool operator == (State* s);

  /**
   * @brief checks the input and processes it depending of the event
   * @param the event polled
   * @return true if the state should keep working | false if it finished
   * 
   */
  virtual bool handleInput(sf::Event event) = 0;
  
  /**
   * @brief Updates the state of the object if needed
   * @param the event polled
   * @return true if the state should keep working | false if it finished
   * 
   */
  virtual bool onUpdate(sf::Event event) = 0;
  
  /**
   * State initialization
   */
  virtual void onEntry() = 0;
  
  /**
   * State finishing
   */
  virtual void onExit() = 0;
 

  /**
   * Member declaration
   */
 public:

  /**
   * The pointer to the FSM it was called from
   */
  App* m_fsm;

  /**
   * the ID of the state to recognize it among the others
   */
  unsigned short m_ID;
  
};

class Pause_State : public State 
{
 public:

  /**
   * @brief checks the input and processes it depending of the event
   * @param the event polled
   * @return true if the state should keep working | false if it finished
   *
   */
  bool handleInput(sf::Event event);

  /**
   * @brief Updates the state of the object if needed
   * @param the event polled
   * @return true if the state should keep working | false if it finished
   *
   */
  bool onUpdate(sf::Event event);

  /**
   * State initialization
   */
  void onEntry();

  /**
   * State finishing
   */
  void onExit();
};

class Logo_State : public State 
{
 public:

  /**
   * @brief checks the input and processes it depending of the event
   * @param the event polled
   * @return true if the state should keep working | false if it finished
   *
   */
  bool handleInput(sf::Event event);
  
  /**
   * @brief Updates the state of the object if needed
   * @param the event polled
   * @return true if the state should keep working | false if it finished
   *
   */
  bool onUpdate(sf::Event event);

  /**
   * State initialization
   */
  void onEntry();

  /**
   * State finishing
   */
  void onExit();
  

  /**
   * Member declaration
   */
 public:

  /**
   * poll ticks counter for testing
   */
  int counter;
};

class Help_State : public State 
{
 public:

  /**
   * @brief checks the input and processes it depending of the event
   * @param the event polled
   * @return true if the state should keep working | false if it finished
   *
   */
  bool handleInput(sf::Event event);

  /**
   * @brief Updates the state of the object if needed
   * @param the event polled
   * @return true if the state should keep working | false if it finished
   *
   */
  bool onUpdate(sf::Event event);

  /**
   * State initialization
   */
  void onEntry();

  /**
   * State finishing
   */
  void onExit();
  
};

class Menu_State : public State 
{
 public:

  /**
   * @brief checks the input and processes it depending of the event
   * @param the event polled
   * @return true if the state should keep working | false if it finished
   *
   */
  bool handleInput(sf::Event event);

  /**
   * @brief Updates the state of the object if needed
   * @param the event polled
   * @return true if the state should keep working | false if it finished
   *
   */
  bool onUpdate(sf::Event event);

  /**
   * State initialization
   */
  void onEntry();

  /**
   * State finishing
   */
  void onExit();
  
};

class GameOver_State : public State 
{
 public:

  /**
   * @brief checks the input and processes it depending of the event
   * @param the event polled
   * @return true if the state should keep working | false if it finished
   *
   */
  bool handleInput(sf::Event event);
  
  /**
   * @brief Updates the state of the object if needed
   * @param the event polled
   * @return true if the state should keep working | false if it finished
   *
   */
  bool onUpdate(sf::Event event);

  /**
   * State initialization
   */
  void onEntry();

  /**
   * State finishing
   */
  void onExit();
  
};

class Play_State : public State 
{
 public:
  
  /**
   * @brief checks the input and processes it depending of the event
   * @param the event polled
   * @return true if the state should keep working | false if it finished
   *
   */
  bool handleInput(sf::Event event);
  
  /**
   * @brief Updates the state of the object if needed
   * @param the event polled
   * @return true if the state should keep working | false if it finished
   *
   */
  bool onUpdate(sf::Event event);

  /**
   * State initialization
   */
  void onEntry();

  /**
   * State finishing
   */
  void onExit();
  

  /**
   * The normal camera for isometric projection
   */
  sf::View m_mainCamera;

  /**
   * The minimap camera in the left bottom screen position
   */
  sf::View m_miniMapCamera;

};

class Options_State : public State 
{
 public:

  /**
   * @brief checks the input and processes it depending of the event
   * @param the event polled
   * @return true if the state should keep working | false if it finished
   *
   */
  bool handleInput(sf::Event event);

  /**
   * @brief Updates the state of the object if needed
   * @param the event polled
   * @return true if the state should keep working | false if it finished
   *
   */
  bool onUpdate(sf::Event event);

  /**
   * State initialization
   */
  void onEntry();

  /**
   * State finishing
   */
  void onExit();
  
};

class GamePlay_State : public State 
{
 public:

  /**
   * @brief checks the input and processes it depending of the event
   * @param the event polled
   * @return true if the state should keep working | false if it finished
   *
   */
  bool handleInput(sf::Event event);

  /**
   * @brief Updates the state of the object if needed
   * @param the event polled
   * @return true if the state should keep working | false if it finished
   *
   */
  bool onUpdate(sf::Event event);

  /**
   * State initialization
   */
  void onEntry();

  /**
   * State finishing
   */
  void onExit();
  
};

class Graphics_State : public State 
{
 public:

  /**
   * @brief checks the input and processes it depending of the event
   * @param the event polled
   * @return true if the state should keep working | false if it finished
   *
   */
  bool handleInput(sf::Event event);

  /**
   * @brief Updates the state of the object if needed
   * @param the event polled
   * @return true if the state should keep working | false if it finished
   *
   */
  bool onUpdate(sf::Event event);

  /**
   * State initialization
   */
  void onEntry();

  /**
   * State finishing
   */
  void onExit();
  
};

class Sound_State : public State 
{
 public:

  /**
   * @brief checks the input and processes it depending of the event
   * @param the event polled
   * @return true if the state should keep working | false if it finished
   *
   */
  bool handleInput(sf::Event event);

  /**
   * @brief Updates the state of the object if needed
   * @param the event polled
   * @return true if the state should keep working | false if it finished
   *
   */
  bool onUpdate(sf::Event event);

  /**
   * State initialization
   */
  void onEntry();

  /**
   * State finishing
   */
  void onExit();
  
};