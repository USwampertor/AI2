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

#include "Utilities.h"

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
  Screen() = default;
  ~Screen();
  
  sf::RenderWindow 
  m_mainWindow;
  
  std::vector<sf::Drawable*> 
  m_objects;
  
  void 
  onRender();
  
  bool 
  createWindow();
  
  void 
  CheckState(State* s);
  
  sf::RectangleShape 
  m_shape;
};

