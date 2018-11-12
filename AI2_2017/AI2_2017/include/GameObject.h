/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file GameObject.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/19 2018
 * @brief virtual class to manage all objects inside game
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#pragma once
#include "Vector2.h"
#include "Vector3.h"
#include "Utilities.h"
#include "Animation.h"

 /**
  * GameObject
  * Description:
  * 	The objects inside the game are children of this object
  * Sample usage:
  * 	
  */
class GameObject
{
 public:
  
  /**
   * Default constructor
   */
  GameObject() = default;

  /**
   * virtual destructor
   */
  virtual ~GameObject() {};

  /**
   * @brief returns the ID of the object
   * @param 
   * @return the ID
   *
   */
  int
  getID();

  /**
   * @brief sets the unique ID of the Object
   * @param the ID to set to the game Object
   * @return 
   *
   */
  void
  setID(const int id);

  /**
   * @brief sets the position of the object in world space
   * @param coordinates of the object in world space
   * @return 
   *
   */
  void 
  setPosition(float x, float y);

  /**
   * @brief sets the position of the object in world space
   * @param coordinates of the object in world space
   * @return
   *
   */
  void
  setPosition(sf::Vector2f position);

  /**
   * @brief sets the position of the object in world space
   * @param coordinates of the object in world space
   * @return
   *
   */
  void
  setPosition(Vector2 position);

 private:
  
  /**
   * position X of gameObject in world 
   */
  Vector2 m_position;

  /**
   * ID of the game object
   */
  int m_ID;

};


/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * GameObject.h Lua registration
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
