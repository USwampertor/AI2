/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file App.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/09/28 2018
 * @brief the cpp for the App FSM class | Method definition
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#include "App.h"

bool
App::onEntry() {
  
  sf::Font font;
  if (!font.loadFromFile("resources/fonts/arial.ttf")) {
    std::cout << "Failed to create default font from file...\n";
    return false;
  }
  m_fontMap.insert(std::make_pair("default", font));

  if (!font.loadFromFile("resources/fonts/Aurebesh.otf")) {
    std::cout << "Failed to create default font from file...\n";
    return false;
  }
  m_fontMap.insert(std::make_pair("aurebesh", font));

  if (!font.loadFromFile("resources/fonts/PGB.ttf")) {
    std::cout << "Failed to create default font from file...\n";
    return false;
  }
  m_fontMap.insert(std::make_pair("pokemon", font));

  if (!font.loadFromFile("resources/fonts/HaraldRunic.ttf")) {
    std::cout << "Failed to create default font from file...\n";
    return false;
  }
  m_fontMap.insert(std::make_pair("runic", font));

  if (!font.loadFromFile("resources/fonts/BCastle.ttf")) {
    std::cout << "Failed to create default font from file...\n";
    return false;
  }
  m_fontMap.insert(std::make_pair("old", font));

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
  m_screen.m_testText.setString("TEST STRING");
  m_screen.m_testText.setFont(m_fontMap["aurebesh"]);
  m_screen.m_testText.setPosition(0.0f, 0.0f);
  m_screen.m_testText.setCharacterSize(10);
  m_screen.m_testText.setFillColor(sf::Color::White);
  setState(m_logoS);

  return true;
}

void 
App::onUpdate() {
  sf::Event event;
  event.type = sf::Event::Count;
  while (m_screen.m_mainWindow.isOpen()) {

    if (m_screen.m_mainWindow.pollEvent(event))
    {
      if (event.type == sf::Event::Closed) {
      m_screen.m_mainWindow.close();
      return;
      }
      if (event.type == sf::Event::Resized) {
        sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
        m_screen.m_mainWindow.setView(sf::View(visibleArea));
      }
      if (!m_currentState->onInputUpdate(event)) {
        setState(nullptr);
      }
      
      //m_currentState->onUpdate();
      //m_screen.m_mainWindow.clear();
      //m_currentState->onRender(&m_screen.m_mainWindow);
      //m_screen.m_mainWindow.draw(m_screen.m_testText);
      //m_screen.m_mainWindow.display();
    }
    
    if (m_currentState == nullptr) {m_screen.m_mainWindow.close();}
    
    m_currentState->onUpdate();
    m_screen.m_mainWindow.clear();
    m_currentState->onRender(&m_screen.m_mainWindow);
    m_screen.m_mainWindow.draw(m_screen.m_testText);
    m_screen.m_mainWindow.display();
  }
}


void 
App::setState(State* state) {

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

  else if(m_currentState != nullptr) {
    //m_stateStack.pop();
    state->m_fsm = this;
    m_stateStack.push(state);
    m_currentState->onExit();
    m_currentState = m_stateStack.top();
    m_currentState->onEntry();
  }

  else {
    state->m_fsm = this;
    m_stateStack.push(state);
    m_currentState = m_stateStack.top();
    m_currentState->onEntry();
  }

}

void
App::onExit() {
  m_screen.m_mainWindow.close();
}