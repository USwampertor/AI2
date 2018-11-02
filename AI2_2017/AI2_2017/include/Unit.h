/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file Unit.h
 * @author Marco "Swampy" Millan
 * @date 2018/09/27 2018
 * @brief Unit class to be called from Lua
 *
 */
 /*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#pragma once
#include "GameObject.h"
#include "UnitType.h"

class Unit : public GameObject
{
 public:
  /**
   * Default Constructor
   */
  Unit() = default;

  /**
   * Copy Constructor
   */
  Unit(const Unit& other) {
    m_name = other.m_name;
    m_type = other.m_type;
    m_hp = other.m_hp;
    m_speed = other.m_speed;
    m_strength = other.m_strength;
    m_defense = other.m_defense;
    m_north = other.m_north;
    m_northWest = other.m_northWest;
    m_west = other.m_west;
    m_southWest = other.m_southWest;
    m_south = other.m_south;
    m_actualFrame = m_south;
  };

  /**
   * Constructor based of a UnitType
   */
  Unit(const UnitType& source) 
    : m_name(source.m_name),
      m_type(source.m_typeID),
      m_hp(source.m_hp),
      m_speed(source.m_speed),
      m_strength(source.m_strength),
      m_defense(source.m_defense),
      m_north(source.m_north),
      m_northWest(source.m_northWest),
      m_west(source.m_west),
      m_southWest(source.m_southWest),
      m_south(source.m_south) {
      m_actualFrame = m_south;
  };

  /**
   * Constructor that sets the unit type
   */
  Unit(int type) : m_type(type) {}

  /**
   * Default Destructor
   */
  ~Unit() {};

  /**
   * @brief sets the name of the unit
   * @param const char* name of unit
   * @return
   *
   */
  void
  setName(const char* name) {
    m_name = name;
  }

  /**
   * @brief gets the name of the unit
   * @param
   * @return const char* name of unit
   *
   */
  const char*
  getName() {
    return m_name.c_str();
  }

  /**
   * @brief sets the type of the unit
   * @param type the type of unit from the database
   * @return
   *
   */
  void
  setType(int type) {
    m_type = type;  
  }

  /**
   * @brief returns the type of this unit
   * @param 
   * @return the unit type
   *
   */
  const int
  getType() {
    return m_type;
  }

 private:

   /**
    * UnitType Name
    */
   std::string m_name;

   /**
    * unique ID from the database
    */
   int m_type;

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
   * Sprite resources
   */

   sf::Sprite m_north;

   sf::Sprite m_northWest;

   sf::Sprite m_west;

   sf::Sprite m_southWest;

   sf::Sprite m_south;
   
  public:
   sf::Sprite m_actualFrame;
};

/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * Unit.h Lua registration
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

/**
 * @brief creates a character set in Lua
 * @param the Lua state to receive the function
 * @return the character to Lua
 *
 */
int
createUnit(lua_State* L);

/**
 * @brief creates a unit based of another one
 * @param the Lua state to receive the function
 * @return a new Unit based in a copy from the top of the Lua stack
 *
 */
int
copyUnit(lua_State* L);

/**
 * @brief Lua unit destroyer
 * @param the Lua state to receive the function
 * @return 0
 *
 */
int
destroyUnit(lua_State* L);

/**
 * @brief returns a unit to Lua from the stack
 * @param the Lua state, n the position in the stack
 * @return a pointer to Unit
 *
 */
Unit*
getUnit(lua_State* L, int n);

/**
 * @brief Gets the name from a string and a unit from the stack
 * @param The Lua state to receive the function
 * @return the const char* name to the stack with a new name
 *
 */
int
unitGetName(lua_State* L);

/**
 * @brief Sets the name from a string and a unit from the stack
 * @param The Lua state to receive the function
 * @return the character to the stack with a new name
 *
 */
int
unitSetName(lua_State* L);

/**
 * @brief gets the unit type of the unit
 * @param the Lua state to receive the function
 * @return the type in the top of the stack
 *
 */
int
unitGetType(lua_State* L);

/**
 * @brief sets the unit type of the unit
 * @param the Lua state to receive the function
 * @return the unit with a new type in the top of the stack
 *
 */
int
unitSetType(lua_State* L);

/**
 * Lua character registration sets the basic functions to use from Lua
 */
void
registerUnit(lua_State* L);
