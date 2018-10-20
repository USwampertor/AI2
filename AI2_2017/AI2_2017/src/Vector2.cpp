/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file Vector2.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/09/23 2018
 * @brief vector2 member declaration
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#include "stdafx.h"
#include "Vector2.h"
#include "Vector3.h"


  /**
   * Method implementation
   */

  Vector2::Vector2(float nx, float ny) : x(nx), y(ny) {}

  Vector2::Vector2(const Vector3& v): x(v.x),y(v.y) {}
  
  float&
  Vector2::operator[](int index) {
    return (&x)[index];
  }

  float
  Vector2::operator[](int index) const {
    return (&x)[index];
  }

  Vector2
  Vector2::operator+(const Vector2& v) const {
    return Vector2(x + v.x, y + v.y);
  }

  Vector2
  Vector2::operator-(const Vector2& v) const {
    return Vector2(x - v.x, y - v.y);
  }

  Vector2
  Vector2::operator*(const Vector2& v) const {
    return Vector2(x * v.x, y * v.y);
  }

  Vector2
  Vector2::operator/(const Vector2& v) const {
    return Vector2(x / v.x, y / v.y);
  }

  Vector2
  Vector2::operator+(float plus) const {
    return Vector2(x + plus, y + plus);
  }

  Vector2
  Vector2::operator-(float minus) const {
    return Vector2(x - minus, y - minus);
  }

  Vector2
  Vector2::operator*(float times) const {
    return Vector2(x * times, y * times);
  }

  Vector2
  Vector2::operator/(float under) const {
    return Vector2(x / under, y / under);
  }

   float
  Vector2::operator|(const Vector2 v) const {
    return x * v.x + y * v.y;
  }

   float
  Vector2::operator^(const Vector2 v) const {
    return x * v.x - y * v.y;
  }

  bool
  Vector2::operator==(const Vector2& v) const {
    return x == v.x && y == v.y;
  }

  bool
  Vector2::operator!=(const Vector2& v) const {
    return x != v.x || y != v.y;
  }

  bool
  Vector2::operator<(const Vector2& v) const {
    return x < v.x && y < v.y;
  }

  bool
  Vector2::operator>(const Vector2& v) const {
    return x > v.x && y > v.y;
  }

  bool
  Vector2::operator<=(const Vector2& v) const {
    return x <= v.x && y <= v.y;
  }

  bool
  Vector2::operator>=(const Vector2& v) const {
    return x >= v.x && y >= v.y;
  }

  Vector2
  Vector2::operator-() const {
    return Vector2(-x, -y);
  }

  Vector2&
  Vector2::operator+=(const Vector2& v) {
    x += v.x;
    y += v.y;
    return *this;
  }

  Vector2&
  Vector2::operator-=(const Vector2& v) {
    x -= v.x;
    y -= v.y;
    return *this;
  }

  Vector2&
  Vector2::operator*=(const Vector2& v) {
    x *= v.x;
    y *= v.y;
    return *this;
  }

  Vector2&
  Vector2::operator/=(const Vector2& v) {
    x /= v.x;
    y /= v.y;
    return *this;
  }

  Vector2&
  Vector2::operator*=(float scale) {
    x *= scale;
    y *= scale;
    return *this;
  }

  Vector2&
  Vector2::operator/=(float scale) {
    x /= scale;
    y /= scale;
    return *this;
  }

   float
  Vector2::dot(const Vector2& a, const Vector2& b) {
    return a | b;
  }

   float
  Vector2::cross(const Vector2& a, const Vector2& b) {
    return a ^ b;
  }

   float
  Vector2::dotScale(const Vector2& a, const Vector2& b) {
    return (a | b) / a.magnitude();
  }

   float
  Vector2::sqrDistance(const Vector2& a, const Vector2& b) {
    return std::pow(a.x - b.x, 2.0f) + std::pow(a.y - b.y, 2.0f);
  }

   float
  Vector2::distance(const Vector2& a, const Vector2& b) {
    return std::sqrt(sqr(a.x + b.x) + sqr(a.y + b.y));
  }

  void
  Vector2::setValues(float newX, float newY) {
    x = newX;
    y = newY;
  }

  void
  Vector2::min(const Vector2& v) {
    if (v.x < x) x = v.x;
    if (v.y < y) y = v.y;
  }

  void
  Vector2::max(const Vector2& v) {
    if (v.x > x) x = v.x;
    if (v.y > y) y = v.y;
  }

  void
  Vector2::floor() {
    x = std::floor(x);
    y = std::floor(y);
  }

  void
  Vector2::ceiling() {
    x = std::ceil(x);
    y = std::ceil(y);
  }

  void
  Vector2::round() {
    x = std::round(x);
    y = std::round(y);
  }

  void
  Vector2::roundHalf() {
    x = round2(x);
    y = round2(y);
  }

  float
  Vector2::getHighest() const {
    return std::max(x, y);
  }

  float
  Vector2::getLowest() const {
    return std::min(x, y);
  }

  float
  Vector2::magnitude() const {
    return std::sqrt(x * x + y * y);
  }

  float
  Vector2::sqrMagnitude() const {
    return (x * x + y * y);
  }

  Vector2
  Vector2::normalized() {
    float sqr = std::pow(x, 2.0f) + std::pow(y, 2.0f);
    //ASSERT(sqr != 0.0f && "The square of the elements is 0!!!");
    //NAU_DEBUG_ONLY(sqrMagnitude());

    float unit = 1.0f/std::sqrt(sqr);
    return Vector2((x * unit), (y * unit));
  }

  void
  Vector2::normalize() const {
  
  }

  bool
  Vector2::isZero() const {
    return 0.0f == x && 0.0f == y;
  }

  const Vector2 Vector2::ZERO = Vector2(0.0f, 0.0f);
  
  const Vector2 Vector2::ONES = Vector2(1.0f, 1.0f);
  
  const Vector2 Vector2::ONEX = Vector2(1.0f, 0.0f);

  const Vector2 Vector2::ONEY = Vector2(0.0f, 1.0f);
  

