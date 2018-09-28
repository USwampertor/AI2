/*||���||���||���||���||���||���||���||���||���||���||���||���||���||���||���||*/
/**
 * @file State.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/09/28 2018
 * @brief the cpp for the state class | Method definition
 * 
 */
/*||���||���||���||���||���||���||���||���||���||���||���||���||���||���||���||*/

#include "stdafx.h"
#include "State.h"
#include "App.h"

bool State::operator == (State* s) {
  return this->m_ID == s->m_ID;
}
bool Pause_State::handleInput(sf::Event event) {
  if (event.key.code == sf::Keyboard::P) {
    return false;
  }
  if (event.key.code == sf::Keyboard::O) {
    m_fsm->setState(m_fsm->m_optnS);
  }
  return true;
}

bool Pause_State::onUpdate(sf::Event event) {
  if (event.type == sf::Event::KeyPressed) {
    return handleInput(event);
  }
  return true;
}

void Pause_State::onEntry() {
  std::cout << "Pause" << std::endl;
  m_ID = 0;
}

void Pause_State::onExit() {
  ////delete m_fsm;
}
bool Logo_State::onUpdate(sf::Event event) {
  ++counter;
  if (counter <= 5) { return true; }
  else {
    m_fsm->setState(m_fsm->m_menuS);
  }
  return true;
}

bool Logo_State::handleInput(sf::Event event) {
  //if (event.key.code == sf::Keyboard::Space) {
  //std::cout<<"you pressed Space";
  //SetState()
  //}
  return true;
}

void Logo_State::onEntry() {
  std::cout << "Logo" << std::endl;
  m_ID = 1;
}

void Logo_State::onExit() {
  //delete m_fsm;
}

bool Help_State::handleInput(sf::Event event) {
  if (event.key.code == sf::Keyboard::Escape) {
    return false;
  }
  return true;
}
bool Help_State::onUpdate(sf::Event event) {
  if (event.type == sf::Event::KeyPressed) {
    return handleInput(event);
  }
  return true;
}
void Help_State::onEntry() {
  std::cout << "Help" << std::endl;
  m_ID = 2;
}
void Help_State::onExit() {
  //delete m_fsm;
}

bool Menu_State::onUpdate(sf::Event event) {
  if (event.type == sf::Event::KeyPressed) {
    return handleInput(event);
  }
  return true;
}
bool Menu_State::handleInput(sf::Event event) {
  if (event.key.code == sf::Keyboard::O) {
    m_fsm->setState(m_fsm->m_optnS);
  }
  else if (event.key.code == sf::Keyboard::Space) {
   // m_fsm->setState(m_fsm->m_playS);
    m_fsm->setState(m_fsm->m_playS = new Play_State());
  }
  else if (event.key.code == sf::Keyboard::Escape) {
    // m_fsm->setState(m_fsm->m_playS);
    m_fsm->setState(nullptr);
    m_fsm->onExit();
  }
  return true;
}
void Menu_State::onEntry() {
  std::cout << "Menu" << std::endl;
  m_ID = 3;
}
void Menu_State::onExit() {
}

bool GameOver_State::handleInput(sf::Event event) {
  if (event.key.code == sf::Keyboard::Space) {
    m_fsm->setState(m_fsm->m_playS);
  }
  if (event.key.code == sf::Keyboard::Escape) {
    m_fsm->setState(m_fsm->m_menuS);
  }
  return true;
}
bool GameOver_State::onUpdate(sf::Event event) {
  if (event.type == sf::Event::KeyPressed) {
    return handleInput(event);
  }
  return true;
}
void GameOver_State::onEntry() {
  std::cout << "Game Over" << std::endl;
  m_ID = 4;
}
void GameOver_State::onExit() {
  //delete m_fsm;
}

bool Play_State::handleInput(sf::Event event) {
  if (event.key.code == sf::Keyboard::H) {
    m_fsm->setState(m_fsm->m_helpS);
  }
  if (event.key.code == sf::Keyboard::Escape) {
    m_fsm->setState(m_fsm->m_overS);
  }
  return true;
}
bool Play_State::onUpdate(sf::Event event) {
  if (event.type == sf::Event::KeyPressed) {
    return handleInput(event);
  }
  return true;
}
void Play_State::onEntry() {
  std::cout << "Playing..." << std::endl;
  m_ID = 5;
}
void Play_State::onExit() {
  //delete m_fsm;
}

bool Options_State::handleInput(sf::Event event) {
  if (event.key.code == sf::Keyboard::P) {
    m_fsm->setState(m_fsm->m_gameS);
  }
  if (event.key.code == sf::Keyboard::G) {
    m_fsm->setState(m_fsm->m_grapS);
  }
  if (event.key.code == sf::Keyboard::S) {
    m_fsm->setState(m_fsm->m_sounS);
  }
  if (event.key.code == sf::Keyboard::Escape) {
    return false;
  }
  return true;
}
bool Options_State::onUpdate(sf::Event event) {
  if (event.type == sf::Event::KeyPressed) {
    return handleInput(event);
  }
  return true;
}
void Options_State::onEntry() {
  std::cout << "Options" << std::endl;
  m_ID = 6;
}
void Options_State::onExit() {
  //delete m_fsm;
}

bool GamePlay_State::handleInput(sf::Event event) {
  if (event.key.code == sf::Keyboard::Escape) {
    return false;
  }
  return true;
}
bool GamePlay_State::onUpdate(sf::Event event) {
  if (event.type == sf::Event::KeyPressed) {
    return handleInput(event);
  }
  return true;
}
void GamePlay_State::onEntry() {
  std::cout << "Gameplay" << std::endl;
  m_ID = 7;
}
void GamePlay_State::onExit() {
  //delete m_fsm;
}

bool Graphics_State::handleInput(sf::Event event) {
  if (event.key.code == sf::Keyboard::Escape) {
    return false;
  }
  return true;
}
bool Graphics_State::onUpdate(sf::Event event) {
  if (event.type == sf::Event::KeyPressed) {
    return handleInput(event);
  }
  return true;
}
void Graphics_State::onEntry() {
  std::cout << "Graphics" << std::endl;
  m_ID = 8;
}
void Graphics_State::onExit() {
  //delete m_fsm;
}

bool Sound_State::handleInput(sf::Event event) {
  if (event.key.code == sf::Keyboard::Escape) {
    return false;
  }
  return true;
}
bool Sound_State::onUpdate(sf::Event event) {
  if (event.type == sf::Event::KeyPressed) {
    return handleInput(event);
  }
  return true;
}
void Sound_State::onEntry() {
  std::cout << "Sound" << std::endl;
  m_ID = 9;
}
void Sound_State::onExit() {
  //delete m_fsm;
}