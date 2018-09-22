#include "stdafx.h"
#include "App.h"

App::App() {
  m_currentState = nullptr;
  m_screen.createWindow();
  m_stateStack.push(new Logo_State());
  m_currentState = m_stateStack.top();
  m_currentState->m_fsm = this;
}
void App::onUpdate() {
  while (m_screen.m_mainWindow.isOpen()) {
    sf::Event event;
    while (m_screen.m_mainWindow.pollEvent(event))
    {
      if (event.type == sf::Event::Closed) {
      m_screen.m_mainWindow.close();
      }
      if (!m_currentState->onUpdate(event)) {
        setState(nullptr);
      }
      else {
        m_currentState = m_stateStack.top();
      }
        //el estado tiene un puntero a su maquina de estados, con el cual activa el set state

    }
    if (m_currentState == nullptr) {m_screen.m_mainWindow.close();}
    m_screen.CheckState(m_currentState);
    m_screen.m_mainWindow.clear();
    m_screen.onRender();
    m_screen.m_mainWindow.display();
  }
}
/**
 * Set State sets the m_currentState to the new state and gets it in the stack
 *
 *
 * @param state
 *
 *
 */
void App::setState(State* state) {
/**
 * if(state is null)
    if(stack is with something)
      state = topofStack
 */
  if (state == nullptr) {
    if (!m_stateStack.empty()) {
      //m_stateStack.pop();
      m_currentState->onExit();
      delete (m_currentState);
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
   // m_currentState = m_stateStack.top();
  }

}