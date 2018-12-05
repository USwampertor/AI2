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