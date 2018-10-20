/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file UnitType.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/19 2018
 * @brief Unit type serves as a template to implement objects from the database
 * to the game
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#pragma once

#include "Utilities.h"

 /**
  * UnitType
  * Description:
  * 	A database filled object, functions as a template for creating units
  * Sample usage:
  * 	
  */
class UnitType
{
 public:
  /**
   * Default constructor
   */
  UnitType() = default;

  /**
   * Copy constructor
   */
  UnitType(const UnitType& other)
    : m_typeID(other.m_typeID),
      m_hp(other.m_hp),
      m_speed(other.m_speed),
      m_strength(other.m_strength),
      m_defense(other.m_defense),
      m_name(other.m_name){}

  /**
   * Destructor
   */
  ~UnitType() {};

  /**
   * @brief 
   * @param 
   * @return 
   *
   */
  void loadFromDb();

 public:
  
  /**
   * UnitType Name
   */
  std::string m_name;

  /**
   * unique ID from the database
   */
  int m_typeID;
  
  /**
   * standard health
   */
  int m_hp;
  
  /**
   * standard speed
   */
  int m_speed;
  
  /**
   * standard strength
   */
  int m_strength;
  
  /**
   * standard defense
   */
  int m_defense;

};

