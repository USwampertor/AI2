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
   * Text Object
   */
  sf::Text m_text;

  /**
   * Simple sfml rectangle to test the flow
   */
  sf::RectangleShape 
  m_shape;
  
  /**
   * Standard sf texture
   */
  sf::Texture
  m_texture;

  /**
   * Standard sf image
   */
  sf::Sprite
  m_logo;

  /**
   * SFML window to render stuff
   */
  sf::RenderWindow m_mainWindow;
  
  /**
   * Vector of all drawable objects
   */
  std::vector<sf::Drawable*> m_objects;
};

