/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file Unit.h
 * @author Marco "Swampy" Millan
 * @date 2018/09/27 2018
 * @brief Unit class to be called from Lua
 *
 */
 /*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/

#pragma once
#include "GameObject.h"
#include "Resource.h"
#include "UnitState.h"
#include "UnitType.h"
 /**
  * Unit
  * Description:
  * 	A child of gameObject, is a simple being that lives inside our world
  * Sample usage:
  * 	Unit Update checks the state it should have right now
  */
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
    m_anim = other.m_anim;
    m_actualFrame = m_anim.m_frame[IDLE][NORTH][0];
    m_SpriteResource = other.m_SpriteResource;
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
    m_anim(source.m_anim) {
    m_actualFrame = m_anim.m_frame[IDLE][NORTH][0];
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
   * @brief Initializes the objects inside of it
   * @param 
   * @return if able to generate
   *
   */
  bool
  initialize();

  /**
   * @brief checks for inputs ir if it has to update something inside of it
   * @param 
   * @return 
   *
   */
  void
  update(float deltaTime);


  /**
   * Updates the orientation of the unit
   */
  DIR
  orientation();

  /**
   * @brief sets the current state of the machine
   * @param 
   * @return 
   *
   */
  void
  setState(UnitState* state);

  /**
   * Deletes and sends the garbage disposal
   */
  void
  finish();

  /**
   * @brief sets the name of the unit
   * @param const char* name of unit
   * @return
   *
   */
  void
  setName(const char* name);

  /**
   * @brief gets the name of the unit
   * @param
   * @return const char* name of unit
   *
   */
  const char*
  getName();

  /**
   * @brief sets the type of the unit
   * @param type the type of unit from the database
   * @return
   *
   */
  void
  setType(int type);

  /**
   * @brief returns the type of this unit
   * @param
   * @return the unit type
   *
   */
  const int
  getType();

public:

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
   * How much time has it passed in the current state
   */
  float m_timeInState;

  /**
   * The direction the object is facing
   */
  Vector2 m_orientation;

  /**
   * resource where the sprite is getting the frames
   */
  std::shared_ptr<Texture> m_SpriteResource;

  /**
   * The delta time receiver
   */
  sf::Time m_deltaTime;

  /**
   * Vector of the objective (given by the mouse in this moment)
   */
  Vector2 m_objective;

  /**
   * Static states for the FSM
   */

  /*****************************************************************************/
  /*
   * Animations are saved in a vector that saves them in sets by COORDINATES
   * All vector of animations will have a size of 5 (north n-west west s-west south)
   * or at least thats the intention, anyway, its a vector, you can expand it
   */
  /*****************************************************************************/

  /*
   * Set of all animations, which means frames, direction and action
   */
  Animation m_anim;

  /**
   * Specific frame running
   */
  Frame m_actualFrame;

  /**
   * current state
   */
  UnitState* m_currentState;

  /**
   * State stack
   */
  std::stack<UnitState*> m_stateStack;

  /**
   * Idle state
   */
  Idle_State*   m_idleS;

  /**
   * Attack state
   */
  Attack_State* m_attackS;

  /**
   * Run state
   */
  Run_State*    m_runS;

  /**
   * Dead state
   */
  Dead_State*   m_deadS;
};

/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * Unit.h Lua registration
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/

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
