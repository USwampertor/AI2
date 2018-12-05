/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file UnitState.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/11/06 2018
 * @brief member declaration for UnitType
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#include "UnitState.h"

//Forward declaration
#include "Unit.h"

/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * UnitState.cpp IDLE STATE
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
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
Idle_State::update() {
}

bool
Idle_State::handleInput(sf::Event event) {
  return true;

}

ANIM
Idle_State::getANIM() {
  return ANIM::IDLE;
}

/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * UnitState.cpp ATTACK STATE
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

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
Attack_State::update() {

}

bool
Attack_State::handleInput(sf::Event event) {
  return true;

}

ANIM
Attack_State::getANIM() {
  return ANIM::ATTACK;
}

/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * UnitState.cpp RUN STATE
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

void
Run_State::onEntry() {

}

void
Run_State::onExit() {

}

bool
Run_State::onUpdate(sf::Event event) {
  return true;

}

void
Run_State::update() {

}

bool
Run_State::handleInput(sf::Event event) {
  return true;

}

ANIM
Run_State::getANIM() {
  return ANIM::RUN;
}
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * UnitState.cpp DEAD STATE
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

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
Dead_State::update() {

}

bool
Dead_State::handleInput(sf::Event event) {
  return true;
}

ANIM
Dead_State::getANIM() {
  return ANIM::DEAD;
}