/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file UnitState.h
 * @author Marco "Swampy" Millan
 * @date 2018/11/06 2018
 * @brief the state of the unit and all its children that derivate from it
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/

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
  UnitState() { m_owner = nullptr; }

  /**
   * virtual destructor
   */
  virtual ~UnitState() {}

  /**
   * @brief sets the unit to the actual state and updates specific info for this
   * @param 
   * @return 
   *
   */
  virtual void
  onEntry() = 0;

  /**
   * @brief ends and or flushes data specific to this state
   * @param 
   * @return 
   *
   */
  virtual void 
  onExit() = 0;

  /**
   * @brief checks if something has to be updated
   * @param the event to check if it needs to change anything
   * @return bool if its still inside our state or changes
   *
   */
  virtual bool 
  onUpdate(sf::Event event) = 0;

  /**
   * @brief checks if theres an update and therefore, changes the state
   * @param 
   * @return 
   *
   */
  virtual void
  update() = 0;

  /**
   * Handles the input given
   */
  virtual bool 
  handleInput(sf::Event event) = 0;


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
   sf::Clock m_clock;

   /**
    * The delta time receiver
    */
   sf::Time m_deltaTime;

   /**
    * Controls the actual frame that has to render
    */
   int m_actualFrame;

   /**
    * Controls the amount of time during 1 second
    */
   int m_storedTime;
};

class Idle_State : public UnitState
{
 public:

  void
  onEntry();

   void
  onExit();

   bool
  onUpdate(sf::Event event);

   void
  update();

   bool
  handleInput(sf::Event event);

};

class Attack_State : public UnitState
{
public:

  void
  onEntry();

  void
  onExit();

  bool
  onUpdate(sf::Event event);

  void
  update();

  bool
  handleInput(sf::Event event);

};

class Run_State : public UnitState
{
public:

  void
  onEntry();

  void
  onExit();

  bool
  onUpdate(sf::Event event);

  void
  update();

  bool
  handleInput(sf::Event event);

};

class Dead_State : public UnitState
{
public:

  void
  onEntry();

  void
  onExit();

  bool
  onUpdate(sf::Event event);

  void
  update();

  bool
  handleInput(sf::Event event);

};