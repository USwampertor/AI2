/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file GameObject.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/11/02 2018
 * @brief Gameobject member definition
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#include "GameObject.h"

int
GameObject::getID() {
  return m_ID;
}

void
GameObject::setID(int id) {
  m_ID = id;
}


void
GameObject::setPosition(float x, float y) {
  m_position.x = x;
  m_position.y = y;
}

void
GameObject::setPosition(sf::Vector2f position) {
  m_position.x = position.x;
  m_position.y = position.y;
}

void
GameObject::setPosition(Vector2 position) {
  m_position.x = position.x;
  m_position.y = position.y;
}