/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file Text.h
 * @author Marco "Swampy" Millan
 * @date 2018/11/30 2018
 * @brief 
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#pragma once

#include "Utilities.h"
#include "Resource.h"

 /**
  * Text
  * Description:
  * 	SFML text encapsulation
  * Sample usage:
  * 	Hello World
  */
class Text
{
public:
  
  /**
   * Default constructor
   */
  Text() = default;

  /**
   * Default destructor
   */
  ~Text() {};

  /**
   * Member declaration
   */
public:

  /**
   * Text encapsulation
   */
  sf::Text m_text;

  /**
   * shared font pointer
   */
  std::shared_ptr<Font> m_font;
};

/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * Text.h notes
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/