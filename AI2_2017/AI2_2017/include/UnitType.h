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

#include "Animation.h"
#include "Resource.h"
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
      m_source(other.m_source),
      m_hp(other.m_hp),
      m_speed(other.m_speed),
      m_strength(other.m_strength),
      m_defense(other.m_defense),
      m_name(other.m_name),
      m_anim(other.m_anim) {}

  /**
   * Destructor
   */
  ~UnitType() {
  };

  /**
   * @brief gets the information of a unit Type from the database and loads it 
   * into this unit
   * @param the id of the unit
   * @return 
   *
   */
  void 
  loadFromDb(const int id);

  /**
   * @brief loads the sprites of the object (if it has any)
   * @param string sprite names
   * @return 
   *
   */
  void
  loadSprites(std::string spriteName);

 public:
  
  /**
   * UnitType Name
   */
  std::string m_name;

  /**
   * Source Atlas
   */
  std::string m_source;

  /**
   * unique ID from the database
   */
  unsigned int m_typeID;
  
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

  /**
   * Set of all animations, which means frames, direction and action
   */
  Animation m_anim;
};

