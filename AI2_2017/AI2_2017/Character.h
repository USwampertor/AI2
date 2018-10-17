/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file Character.h
 * @author Marco "Swampy" Millan
 * @date 2018/09/27 2018
 * @brief Character class to be called from Lua
 *
 */
 /*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#pragma once
#include "Utilities.h"

class Character
{
public:
  /**
   * Default Constructor
   */
  Character() = default;

  /**
   * Copy Constructor
   */
  Character(const Character& other) : m_name(other.m_name) {};

  /**
   * Constructor that sets m_name with name parameter
   */
  Character(const char* name) : m_name(name) {}

  /**
   * Default Destructor
   */
  ~Character() = default;

  /**
   * @brief sets the name of the character
   * @param const char* name of character
   * @return
   *
   */
  void
  setName(const char* name) {
    m_name = name;
  }

  /**
   * @brief gets the name of the character
   * @param
   * @return const char* name of character
   *
   */
  const char*
  getName() {
    return m_name.c_str();
  }


private:
  /**
   * const char* name component
   */
  std::string m_name;
};
