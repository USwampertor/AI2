/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file Vector3.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/09/27 2018
 * @brief the Vector3 member definition
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#include "stdafx.h"
#include "Vector3.h"

/**
 * Method Implementation
 */

Vector3::Vector3(float nx, float ny, float nz) : x(nx), y(ny), z(nz) {}

float&
Vector3::operator[](int index) {
  return (&x)[index];
}

float
Vector3::operator[](int index) const {
  return (&x)[index];
}

Vector3
 Vector3::operator+(const Vector3& v) const {
  return Vector3(x + v.x, y + v.y, z + v.z);
}

Vector3
Vector3::operator-(const Vector3& v) const {
  return Vector3(x - v.x, y - v.y, z - v.z);
}

Vector3
Vector3::operator*(const Vector3& v) const {
  return Vector3(x * v.x, y * v.y, z * v.z);
}

Vector3
Vector3::operator/(const Vector3& v) const {
  return Vector3(x / v.x, y / v.y, z / v.z);
}

Vector3
Vector3::operator+(float plus) const {
  return Vector3(x + plus, y + plus, z + plus);
}

Vector3
Vector3::operator-(float minus) const {
  return Vector3(x - minus, y - minus, y - minus);
}

Vector3
Vector3::operator*(float times) const {
  return Vector3(x * times, y * times, z * times);
}

Vector3
Vector3::operator/(float under) const {
  return Vector3(x / under, y / under, z / under);
}

float
Vector3::operator|(const Vector3 v) const {
  return x * v.x + y * v.y + z * v.z;
}

float
Vector3::operator^(const Vector3 v) const {
  return x * v.x - y * v.y - z * v.z;
}

bool
Vector3::operator==(const Vector3& v) const {
  return x == v.x && y == v.y && z == v.z;
}

bool
Vector3::operator!=(const Vector3& v) const {
  return x != v.x || y != v.y || z == v.z;
}

bool
Vector3::operator<(const Vector3& v) const {
  return x < v.x && y < v.y && z < v.z;
}

bool
Vector3::operator>(const Vector3& v) const {
  return x > v.x && y > v.y && z > v.z;
}

bool
Vector3::operator<=(const Vector3& v) const {
  return x <= v.x && y <= v.y && z <= v.z;
}

bool
Vector3::operator>=(const Vector3& v) const {
  return x >= v.x && y >= v.y && z >= v.z;
}

Vector3
Vector3::operator-() const {
  return Vector3(-x, -y, -z);
}

Vector3&
Vector3::operator+=(const Vector3& v) {
  x += v.x;
  y += v.y;
  z += v.z;
  return *this;
}

Vector3&
Vector3::operator-=(const Vector3& v) {
  x -= v.x;
  y -= v.y;
  z -= v.z;
  return *this;
}


Vector3&
Vector3::operator*=(const Vector3& v) {
  x *= v.x;
  y *= v.y;
  z *= v.z;
  return *this;
}

Vector3&
Vector3::operator/=(const Vector3& v) {
  x /= v.x;
  y /= v.y;
  z /= v.z;
  return *this;
}

Vector3&
Vector3::operator*=(float scale) {
  x *= scale;
  y *= scale;
  z *= scale;
  return *this;
}

Vector3&
Vector3::operator/=(float scale) {
  x /= scale;
  y /= scale;
  z /= scale;
  return *this;
}

float
Vector3::dot(const Vector3& a, const Vector3& b) {
  return a | b;
}

float
Vector3::cross(const Vector3& a, const Vector3& b) {
  return a ^ b;
}

float
Vector3::dotScale(const Vector3& a, const Vector3& b) {
  return (a | b) / (a.magnitude());
}

float
Vector3::sqrDistance(const Vector3& a, const Vector3& b) {
  return sqr(a.x - b.x) +
         sqr(a.y - b.y) +
         sqr(a.z - b.z);
}

float
Vector3::distance(const Vector3& a, const Vector3& b) {
  return 
    std::sqrt(sqr(a.x - b.x) +
              sqr(a.y - b.y) +
              sqr(a.z - b.z));
}

void
Vector3::setValues(float newX, float newY, float newZ) {
  x = newX;
  y = newY;
  z = newZ;
}

void
Vector3::min(const Vector3& v) {
  if (v.x < x) x = v.x;
  if (v.y < y) y = v.y;
  if (v.z < z) z = v.z;
}

void
Vector3::max(const Vector3& v) {
  if (v.x > x) x = v.x;
  if (v.y > y) y = v.y;
  if (v.z > z) z = v.z;
}

void
Vector3::floor() {
  x = std::floor(x);
  y = std::floor(y);
  z = std::floor(z);
}

void
Vector3::ceiling() {
  x = std::ceil(x);
  y = std::ceil(y);
  z = std::ceil(z);
}

void
Vector3::round() {
  x = std::round(x);
  y = std::round(y);
  z = std::round(z);
}

void
Vector3::roundHalf() {
  x = round2(x);
  y = round2(y);
  z = round2(z);
}

float
Vector3::magnitude() const {
  return sqrt(x * x + y * y + z * z);
}

float
Vector3::sqrMagnitude() const {
  return (x * x + y * y + z * z);
}

Vector3
Vector3::normalized() {
  float unit = 1.0f/sqrt(x*x + y * y + z * z);
  return Vector3((x * unit), (y * unit), (z * unit));
}

void
Vector3::normalize() const {

}

bool
Vector3::isZero() const {
  return 0.0f == x && 0.0f == y && 0.0f == z;
}

const Vector3 Vector3::ZERO = Vector3(0.0f, 0.0f, 0.0f);

const Vector3 Vector3::ONES = Vector3(1.0f, 1.0f, 1.0f);

const Vector3 Vector3::ONEX = Vector3(1.0f, 0.0f, 0.0f);

const Vector3 Vector3::ONEY = Vector3(0.0f, 1.0f, 0.0f);

const Vector3 Vector3::ONEZ = Vector3(0.0f, 0.0f, 1.0f);

