/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file UnitState.h
 * @author Marco "Swampy" Millan
 * @date 2018/11/06 2018
 * @brief the state of the unit and all its children that derivate from it
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once
#include "Utilities.h"
#include "Vector2.h"

//Forward declaration
class Unit;

 /**
  * UnitState
  * Description:
  * 	Base UnitState for the unit, it checks and updates the data and behaviors
  * Sample usage:
  * 	unit idle justs... stands right there
  */
class UnitState
{
public:
  /**
   * Default constructor
   */
  UnitState() = default;

  /**
   * virtual destructor
   */
  virtual ~UnitState() {};

  /**
   * @brief sets the unit to the actual state and updates specific info for this
   * @param 
   * @return 
   *
   */
  void onEntry();

  /**
   * @brief ends and or flushes data specific to this state
   * @param 
   * @return 
   *
   */
  void onExit();

  /**
   * @brief checks if something has to be updated
   * @param the event to check if it needs to change anything
   * @return bool if its still inside our state or changes
   *
   */
  bool onUpdate(sf::Event event);

  /**
   * @brief 
   * @param 
   * @return 
   *
   */
  void update();

  void handleInput(sf::Event event);


  /**
   * Member declaration
   */
 public:

   /**
    * The owner of the unit
    */
   Unit* m_owner;

   /**
    * the clock for getting delta times
    */
   sf::Clock m_time;

};

