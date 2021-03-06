/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file App.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/09/28 2018
 * @brief the cpp for the App FSM class | Method definition
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/

#include "App.h"

using std::static_pointer_cast;

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
  
  m_screen.m_defaultFont = 
    static_pointer_cast<Font>(m_resourceManager.loadFromFile(RESOURCETYPE::FONT,
                                                "resources/fonts/Aurebesh.otf"));

  //static_pointer_cast<Font>(m_resourceManager.loadFromFile(RESOURCETYPE::FONT,
  //                          "resources/fonts/Aurebesh.otf"));
  m_screen.m_testText.setString("TEST STRING");
  m_screen.m_testText.setFont(m_screen.m_defaultFont->m_font);
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
        sf::FloatRect visibleArea(0, 
                                  0, 
                                  static_cast<float>(event.size.width), 
                                  static_cast<float>(event.size.height));
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