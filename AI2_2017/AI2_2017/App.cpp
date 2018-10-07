/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file App.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/09/28 2018
 * @brief the cpp for the App FSM class | Method definition
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#include "stdafx.h"
#include "App.h"

bool
App::onEntry() {
  
  m_logoS = new Logo_State();
  m_playS = new Play_State();
  m_helpS = new Help_State();
  m_menuS = new Menu_State();
  m_sounS = new Sound_State();
  m_pausS = new Pause_State();
  m_optnS = new Options_State();
  m_grapS = new Graphics_State();
  m_gameS = new GamePlay_State();
  m_overS = new GameOver_State();
  
  m_currentState = nullptr;
  m_screen.createWindow();
  m_stateStack.push(m_logoS);
  m_currentState = m_stateStack.top();
  m_currentState->m_fsm = this;

  if (!m_defaultFont.loadFromFile("Aurebesh.otf")) {
    std::cout<<"Failed to create default font from file...\n";
    return false;
  }
  m_screen.m_text.setFont(m_defaultFont);
  m_screen.m_text.setPosition(sf::Vector2f(0.0f,0.0f));
  m_screen.m_text.setFillColor(sf::Color::White);
  return true;
}

void 
App::onUpdate() {
  sf::Event event;
  event.type = sf::Event::Count;
  while (m_screen.m_mainWindow.isOpen()) {
    while (m_screen.m_mainWindow.pollEvent(event))
    {
      if (event.type == sf::Event::Closed) {
      m_screen.m_mainWindow.close();
      return;
      }
      if (!m_currentState->onUpdate(event)) {
        setState(nullptr);
      }
      //else {
      //  m_currentState = m_stateStack.top();
      //}
        //el estado tiene un puntero a su maquina de estados, con el cual activa el set state

    }
    if (m_currentState == nullptr) {m_screen.m_mainWindow.close();}
    m_screen.CheckState(m_currentState);
    m_screen.m_mainWindow.clear();
    m_screen.onRender();
    m_screen.m_mainWindow.display();
  }
}


void 
App::setState(State* state) {
/**
 * if(state is null)
    if(stack is with something)
      state = topofStack
 */
  if (state == nullptr) {
    if (!m_stateStack.empty()) {
      m_stateStack.pop();
      //delete (m_currentState);
      m_currentState = m_stateStack.top();
      m_currentState->onEntry();
    }
    else {
      m_currentState = nullptr;
    }
  }
  else {
    //m_stateStack.pop();
    state->m_fsm = this;
    m_stateStack.push(state);
    m_currentState->onExit();
    m_currentState = m_stateStack.top();
    m_currentState->onEntry();
  }

}

void
App::onExit() {
  m_screen.m_mainWindow.close();
}