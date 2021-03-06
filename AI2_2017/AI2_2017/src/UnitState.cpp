/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file UnitState.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/11/06 2018
 * @brief member declaration for UnitType
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
#include "UnitState.h"

//Forward declaration
#include "Unit.h"

/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * UnitState.cpp IDLE STATE
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
void
Idle_State::onEntry() {
}

void
Idle_State::onExit() {
}

bool
Idle_State::onUpdate(sf::Event event) {
  return true;
}

void
Idle_State::update(float deltaTime) {
}

bool
Idle_State::handleInput(sf::Event event) {
  return true;
}

ANIM
Idle_State::getANIM() {
  return ANIM::IDLE;
}

/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * UnitState.cpp ATTACK STATE
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/

void
Attack_State::onEntry() {
}

void
Attack_State::onExit() {
}

bool
Attack_State::onUpdate(sf::Event event) {
  return true;
}

void
Attack_State::update(float deltaTime) {
}

bool
Attack_State::handleInput(sf::Event event) {
  return true;
}

ANIM
Attack_State::getANIM() {
  return ANIM::ATTACK;
}

/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * UnitState.cpp RUN STATE
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/

void
Run_State::onEntry() {
}

void
Run_State::onExit() {
}

bool
Run_State::onUpdate(sf::Event event) {

  if ((m_owner->getPosition() - m_owner->m_objective).magnitude() <= 5.0f) {
    m_owner->setState(m_owner->m_idleS);
  }
  return true;
}

void
Run_State::update(float deltaTime) {
  if ((m_owner->getPosition() - m_owner->m_objective).magnitude() > 5.0f) {

    Vector2 finalForce(0, 0);
    finalForce += seek(m_owner->m_objective);
    m_owner->setPosition(m_owner->getPosition()+finalForce);
    Vector2 rot = finalForce + m_owner->getPosition();
    rot.normalize();
    float angle = std::abs(((float)std::atan(rot.y / rot.x) * 180.0f / 3.14159f) - 
                           ((float)std::atan(m_owner->m_orientation.y / 
                                             m_owner->m_orientation.x) * 
                                              180.0f / 3.14159f));
    m_owner->m_orientation.rotate(angle);
  }
}

bool
Run_State::handleInput(sf::Event event) {
  return true;
}

Vector2
Run_State::seek(Vector2 objective) {
  Vector2 temp(0, 0);
  temp = objective - m_owner->getPosition();
  temp.normalize();
  temp *= MAGNITUDE;
  return temp;
}

ANIM
Run_State::getANIM() {
  return ANIM::RUN;
}
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * UnitState.cpp DEAD STATE
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/

void
Dead_State::onEntry() {
}

void
Dead_State::onExit() {
}

bool
Dead_State::onUpdate(sf::Event event) {
  return true;
}

void
Dead_State::update(float deltaTime) {
}

bool
Dead_State::handleInput(sf::Event event) {
  return true;
}

ANIM
Dead_State::getANIM() {
  return ANIM::DEAD;
}