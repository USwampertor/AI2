/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file Textbox.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/15 2018
 * @brief Text box for user inputs
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#pragma once
#include "Utilities.h"

/**
* TextBox
* Description:
*   A simple textBox for user string input
* Sample usage:
* 	TextBox.insert() gives the textbox the text the user inserted
*/
class TextBox
{
 public:
  
  /**
   * Default constructor
   */
  TextBox() = default;

  /**
   * Default destructor
   */
  ~TextBox() = default;
  
  /**
   * = sign overload
   */
  TextBox 
  operator = (const TextBox& other) const;

  /**
   * @brief Inserts the user input into the text box
   * @param user data: the string to insert
   * @return --
   * 
   */
  void 
  setData(std::string userData);

  /**
   * @brief sets the position of the whole textbox
   * @param x position y position of the textbox
   * @return 
   *
   */
  void
  setPosition(float x, float y);

  /**
   * @brief sets the position of the whole textbox
   * @param x position y position of the textbox
   * @return
   *
   */
  void
  setPosition(sf::Vector2f position);


  /**
   * @brief sets the size of the while textbox
   * @param x width y height of the textbox
   * @return 
   *
   */
  void
  setSize(float x, float y);

  /**
   * @brief sets the color of the textBox
   * @param 
   * @return 
   *
   */
  void
  setBoxColor(sf::Color color);


  /**
   * @brief sets the box with a sprite
   * @param the resource name
   * @return
   *
   */
  void
  setSprite(std::string resourceName);

  /**
   * @brief checks if the click was inside the button box
   * @param the mouse position
   * @return true if clicked
   * 
   */
  bool
  CheckClick(sf::Vector2i mousePos);

  /**
   * @brief draws the objects attached to the textbox
   * @param renderwindow sfml
   * @return 
   *
   */
  void
  draw(sf::RenderWindow* window);

  /**
   * Member declaration
   */
 public:

  /**
   * SFML text output to show user input
   */
   sf::Text m_text;

  /**
   * SFML text box as boundary for the text
   */
   sf::RectangleShape m_box;
};
