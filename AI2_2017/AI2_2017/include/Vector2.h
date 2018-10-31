/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file nauVector2.h
 * @author Marco "Swampy" Millan
 * @date 2018/09/20 2018
 * @brief Vector2 object
 *
 */
 /*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#pragma once

#include "Utilities.h"

class Vector3;
  /**
  * Description:
  *   This is our simple vector2f, nothing to special about it. Its a nice point
  * Sample usage:
  * 	Vector2 foo (2.0f, 3.0f);
  */
class Vector2
{
public:
  /**
   * Constructors
   */

   /**
    * Default constructor
    */
  Vector2() = default;

  /**
   * @brief Constructor 0.0f
   */
  Vector2(float nx, float ny);

  /**
   * @brief Constructor based on a Vector3
   */
  Vector2(const Vector3& v);


  /**
   * @brief [] operator overload
   * @param index of the object we wanna get
   * @return value at index
   *
   */
  float&
  operator[](int index);

  /**
   * @brief [] operator overload
   * @param index of the object we wanna get
   * @return value at index
   *
   */
  float
  operator[](int index) const;

  /**
   * @brief + operator overload
   * @param b the other matrix to add
   * @return a vector sum of *this and v
   *
   */
  Vector2
  operator+(const Vector2& v) const;

  /**
   * @brief - operator overload
   * @param b the other matrix to substract
   * @return a vector difference of *this and v
   *
   */
  Vector2
  operator-(const Vector2& v) const;

  /**
   * @brief * operator overload
   * @param b the other matrix to multiply
   * @return a vector multiplication of *this times v
   *
   */
  Vector2
  operator*(const Vector2& v) const;


  /**
   * @brief / operator overload
   * @param b the other matrix to divide
   * @return a vector division of *this divided by v
   *
   */
  Vector2
  operator/(const Vector2& v) const;

  /**
   * @brief + operator overload
   * @param plus the float to add to all vector
   * @return a vector sum of *this + plus
   *
   */
  Vector2
  operator+(float plus) const;

  /**
   * @brief - operator overload
   * @param minus the float to subtract to all vector
   * @return a vector difference of *this - minus
   *
   */
  Vector2
  operator-(float minus) const;

  /**
   * @brief * operator overload
   * @param times the float to multiply all vector
   * @return a vector multiplication of *this times times
   *
   */
  Vector2
  operator*(float times) const;

  /**
   * @brief / operator overload
   * @param under the float to divide all vector
   * @return a vector divided of *this divided by times
   *
   */
  Vector2
  operator/(float under) const;


  /**
   * @brief | operator overload for dot product
   * @param the other vector
   * @return dot product
   *
   */
  float
  operator|(const Vector2 v) const;

  /**
   * @brief ^ operator overload for cross product
   * @param the other vector
   * @return cross product
   *
   */
  float
  operator^(const Vector2 v) const;


  /**
   * @brief == operator overload
   * @param the other vector to compare
   * @return true if this components are == to v components
   *
   */
  bool
  operator==(const Vector2& v) const;

  /**
   * @brief != operator overload
   * @param the other vector to compare
   * @return true if this components are != to v components
   *
   */
  bool
  operator!=(const Vector2& v) const;

  /**
   * @brief < operator overload
   * @param the other vector to compare
   * @return true if this components are < to v components
   *
   */
  bool
  operator<(const Vector2& v) const;

  /**
   * @brief > operator overload
   * @param the other vector to compare
   * @return true if this components are > to v components
   *
   */
  bool
  operator>(const Vector2& v) const;

  /**
   * @brief <= operator overload
   * @param the other vector to compare
   * @return true if this components are <= to v components
   *
   */
  bool
  operator<=(const Vector2& v) const;

  /**
   * @brief >= operator overload
   * @param the other vector to compare
   * @return true if this components are >= to v components
   *
   */
  bool
  operator>=(const Vector2& v) const;

  /**
   * @brief - operator overload
   * @param
   * @return the negative of the vector
   *
   */
  Vector2
  operator-() const;

  /**
   * @brief += operator overload
   * @param the other vector to add
   * @return *this + v components
   *
   */
  Vector2&
  operator+=(const Vector2& v);

  /**
   * @brief -= operator overload
   * @param the other vector to subtract
   * @return *this - v components
   *
   */
  Vector2&
  operator-=(const Vector2& v);

  /**
   * @brief *= operator overload
   * @param the other vector to multiply
   * @return *this * v components
   *
   */
  Vector2&
  operator*=(const Vector2& v);

  /**
   * @brief /= operator overload
   * @param the other vector to divide
   * @return *this / v components
   *
   */
  Vector2&
  operator/=(const Vector2& v);

  /**
   * @brief *= operator overload
   * @param the float to multiply with
   * @return *this * float
   *
   */
  Vector2&
  operator*=(float scale);

  /**
   * @brief /= operator overload
   * @param the float to divide the vector
   * @return *this / float
   *
   */
  Vector2&
  operator/=(float scale);

  /**
   * @brief the dot product
   * @param a nauVector2 and b nauVector2
   * @return the dot product between a and b
   *
   */
  static float
  dot(const Vector2& a, const Vector2& b);

  /**
   * @brief the cross product
   * @param a nauVector2 and b nauVector2
   * @return the cross product between a and b
   *
   */
  static float
  cross(const Vector2& a, const Vector2& b);

  /**
   * @brief the scale of b over a
   * @param a nauVector2 that is the reflection and b nauVector2 that reflects over
   * @return scale of b in a
   *
   */
  static float
  dotScale(const Vector2& a, const Vector2& b);

  /**
   * @brief the square distance
   * @param a nauVector2 and b nauVector2
   * @return the square distance between the two points
   *
   */
  static float
  sqrDistance(const Vector2& a, const Vector2& b);


  /**
   * @brief the distance between two points in 2d space
   * @param a nauVector2 and b nauVector2
   * @return the distance between the two points
   *
   */
  static float
  distance(const Vector2& a, const Vector2& b);

  /**
   * @brief sets the value of a nauVector2
   * @param float x and y
   * @return
   *
   */
  void
  setValues(float newX, float newY);

  /**
   * @brief gets the min between two vectors
   * @param the other vector to compare
   * @return
   *
   */
  void
  min(const Vector2& v);

  /**
   * @brief gets the max between two vectors
   * @param the other vector to compare
   * @return
   *
   */
  void
  max(const Vector2& v);

  /**
   * @brief floors the components
   * @param
   * @return
   *
   */
  void
  floor();

  /**
   * @brief ceils the components
   * @param
   * @return
   *
   */
  void
  ceiling();

  /**
   * @brief rounds the components x.0 <- -> y.0
   * @param
   * @return
   *
   */
  void
  round();

  /**
   * @brief rounds components taking in account also x.0 - x.5 - y.0
   * @param
   * @return
   *
   */
  void
  roundHalf();

  /**
   * @brief gets the highest value of the vector
   * @param
   * @return
   *
   */
  float
  getHighest() const;

  /**
   * @brief gets the least value of the vector
   * @param
   * @return
   *
   */
  float
  getLowest() const;

  /**
   * @brief gets the magnitude value of the vector
   * @param
   * @return
   *
   */
  float
  magnitude() const;

  /**
   * @brief gets the squared magnitude value of the vector
   * @param
   * @return
   *
   */
  float
  sqrMagnitude() const;

  /**
   * @brief gets the normalized version of the vector
   * @param
   * @return the normalized vector
   *
   */
  Vector2
  normalized();

  /**
   * @brief normalizes the vector
   * @param
   * @return
   *
   */
  void
  normalize() const;

  /**
   * @brief Checks if the vector is empty (0s)
   * @param
   * @return true if it is empty
   *
   */
  bool
  isZero() const;

  /**
   * Changes cartesian to isometric coordinates
   */
  Vector2
  CartesianToIsometric(Vector2 cartesian);

  /**
   * 
   */
  Vector2
  IsometricToCartesian(Vector2 isometric);

  /**
   * static const
   */

public:

  /**
   * vauVector2 with all values 0
   */
  static const Vector2 ZERO;

  /**
   * vauVector2 with all values 1
   */
  static const Vector2 ONES;

  /**
   * vauVector2 with x value 1
   */
  static const Vector2 ONEX;

  /**
   * vauVector2 with y value 1
   */
  static const Vector2 ONEY;

  /**
   * Member declaration
   */

public:

  /**
   * x component of the vector
   */
  float x;

  /**
   * y component of the vector
   */
  float y;

};

