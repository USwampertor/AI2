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

  

 private:
  
  /**
   * position of gameObject in world 
   */
};

