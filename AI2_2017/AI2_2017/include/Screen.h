/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file Screen.h
 * @author Marco "Swampy" Millan
 * @date 2018/09/28 2018
 * @brief the screen class wich holds the graphic interface for persons during that time
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once


#include <iostream>
#include "Resource.h"
#include "Utilities.h"

//forward declaration
class State;

/**
* Description:
*   Screen wrapper for the sfml library of renderer window
* Sample usage:
* 	State angry = new State;
*/
class Screen
{
 public:

  /**
   * Default Constructor
   */
  Screen() = default;

  /**
   * Default Destructor
   */
  ~Screen();
  
  /**
   * @brief Renders objects by state
   * @param 
   * @return 
   * 
   */
  void 
  onRender();
  
  /**
   * @brief initiates the window object
   * @param 
   * @return 
   * 
   */
  bool 
  createWindow();
  
  /**
   * @brief Checks the actual state of the FSM
   * @param the pointer to the actual state
   * @return 
   * 
   */
  void 
  CheckState(State* s);

  /**
   * Member declaration
   */

 public:
  
  /**
   * SFML window to render stuff
   */
  sf::RenderWindow m_mainWindow;
  
  /**
   * test text for testing purposes
   */
  sf::Text m_testText;

  /**
   * Default shared resource font
   */
  std::shared_ptr<Font> m_defaultFont;
};

