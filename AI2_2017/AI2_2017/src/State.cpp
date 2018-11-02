/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file State.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/09/28 2018
 * @brief the cpp for the state class | Method definition
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#include "State.h"
#include "App.h"

/*******************************************************************************/
bool 
State::operator == (State* s) {
  return this->m_ID == s->m_ID;
}

bool 
Pause_State::handleInput(sf::Event event) {
  if (event.key.code == sf::Keyboard::P) {
    return false;
  }
  if (event.key.code == sf::Keyboard::O) {
    m_fsm->setState(m_fsm->m_optnS);
  }
  return true;
}

bool 
Pause_State::onInputUpdate(sf::Event event) {
  if (event.type == sf::Event::KeyPressed) {
    return handleInput(event);
  }
  return true;
}

void 
Pause_State::onEntry() {
  std::cout << "Pause" << std::endl;
  m_ID = 0;
}

void 
Pause_State::onExit() {
  ////delete m_fsm;
}

void
Pause_State::onRender(sf::RenderWindow* window) {

}

void
Pause_State::onUpdate() {

}

/*******************************************************************************/
bool 
Logo_State::onInputUpdate(sf::Event event) {
  
  
  if (counter <= 5.0f) { return true; }
  else {
    m_fsm->setState(m_fsm->m_menuS);
  }
  return true;
}

bool 
Logo_State::handleInput(sf::Event event) {
  return true;
}

void 
Logo_State::onEntry() {
  std::cout << "Logo" << std::endl;
  m_ID = 1;
  sf::Texture* t = new sf::Texture();
  t->loadFromFile("resources/sprites/darkdeep.png");
  m_logo.setTexture(*t);
  m_logo.setScale(0.5f, 0.5f);
  m_logo.setPosition(sf::Vector2f(m_fsm->m_screen.m_mainWindow.getSize().x / 2 -
                                  m_logo.getGlobalBounds().width/2,
                                  m_fsm->m_screen.m_mainWindow.getSize().y / 2 - 
                                  m_logo.getGlobalBounds().height / 2));
}

void 
Logo_State::onExit() {
  //delete m_fsm;
}

void
Logo_State::onRender(sf::RenderWindow* window) {
  window->draw(m_logo);
}

void
Logo_State::onUpdate() {
  counter += m_time.restart().asSeconds();
  if ( counter > 5.0f) {
    m_fsm->setState(m_fsm->m_menuS);
  }
}

/*******************************************************************************/
bool 
Help_State::handleInput(sf::Event event) {
  if (event.key.code == sf::Keyboard::Escape) {
    return false;
  }
  return true;
}

bool
Help_State::onInputUpdate(sf::Event event) {
  if (event.type == sf::Event::KeyPressed) {
    return handleInput(event);
  }
  return true;
}

void 
Help_State::onEntry() {
  std::cout << "Help" << std::endl;
  m_ID = 2;
}

void 
Help_State::onExit() {
  //delete m_fsm;
}

void
Help_State::onRender(sf::RenderWindow* window) {

}

void
Help_State::onUpdate() {

}

/*******************************************************************************/
bool 
Menu_State::onInputUpdate(sf::Event event) {
  if (event.type == sf::Event::KeyPressed) {
    return handleInput(event);
  }
  return true;
}

bool 
Menu_State::handleInput(sf::Event event) {
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

void 
Menu_State::onEntry() {
  std::cout << "Menu" << std::endl;
  m_ID = 3;
  sf::Texture* t = new sf::Texture();
  t->loadFromFile("resources/sprites/mainmap.jpg");
  m_map.setTexture(*t);
  m_map.setPosition(sf::Vector2f(m_fsm->m_screen.m_mainWindow.getSize().x / 2 -
                                 m_map.getGlobalBounds().width / 2,
                                 m_fsm->m_screen.m_mainWindow.getSize().y / 2 -
                                 m_map.getGlobalBounds().height / 2));
  
  m_title.setFont(m_fsm->m_fontMap["old"]);
  m_title.setString("RUNESTONE");
  m_title.setOutlineThickness(2.0f);
  m_title.setFillColor(sf::Color::Black);
  m_title.setOutlineColor(sf::Color::White);
  m_title.setCharacterSize(30);
  m_title.setPosition(sf::Vector2f(m_fsm->m_screen.m_mainWindow.getSize().x / 2 -
                                   m_title.getLocalBounds().width / 2,
                                   m_fsm->m_screen.m_mainWindow.getSize().y / 2 -
                                   m_title.getLocalBounds().height / 2 ));

  m_play.m_text.setFont(m_fsm->m_fontMap["old"]);
  m_play.m_text.setString("PLAY");
  m_play.m_text.setOutlineThickness(2.0f);
  m_play.m_text.setFillColor(sf::Color::Black);
  m_play.m_text.setOutlineColor(sf::Color::Red);
  m_play.m_text.setCharacterSize(30);
  m_play.setSize(100.0f, 100.0f);
  m_play.setSprite("resources/sprites/startButton.png");
  m_play.setPosition(sf::Vector2f(m_fsm->m_screen.m_mainWindow.getSize().x / 2 -
                                  m_play.m_box.getLocalBounds().width / 2,
                                  m_fsm->m_screen.m_mainWindow.getSize().y / 2));

}

void 
Menu_State::onExit() {
}

void
Menu_State::onRender(sf::RenderWindow* window) {
  window->draw(m_map);
  window->draw(m_title);
  m_play.draw(window);
}

void
Menu_State::onUpdate() {
  
}

/*******************************************************************************/
bool 
GameOver_State::handleInput(sf::Event event) {
  if (event.key.code == sf::Keyboard::Space) {
    m_fsm->setState(m_fsm->m_playS);
  }
  if (event.key.code == sf::Keyboard::Escape) {
    m_fsm->setState(m_fsm->m_menuS);
  }
  return true;
}

bool 
GameOver_State::onInputUpdate(sf::Event event) {
  if (event.type == sf::Event::KeyPressed) {
    return handleInput(event);
  }
  return true;
}

void 
GameOver_State::onEntry() {
  std::cout << "Game Over" << std::endl;
  m_ID = 4;
}

void 
GameOver_State::onExit() {
  //delete m_fsm;
}

void
GameOver_State::onRender(sf::RenderWindow* window) {

}

void
GameOver_State::onUpdate() {

}

/*******************************************************************************/
bool 
Play_State::handleInput(sf::Event event) {

  if (event.type == sf::Event::KeyPressed) {

    if (event.key.code == sf::Keyboard::H) {
      m_fsm->setState(m_fsm->m_helpS);
    }
    if (event.key.code == sf::Keyboard::Escape) {
      m_fsm->setState(m_fsm->m_overS);
    }
    if (event.key.code == sf::Keyboard::Left) {
      m_mainCamera.move(-100.0f, 0);
    }
    if (event.key.code == sf::Keyboard::Right) {
      m_mainCamera.move(100.0f, 0);
    }

    if (event.key.code == sf::Keyboard::H) {
      m_fsm->setState(m_fsm->m_helpS);
    }

    if (event.key.code == sf::Keyboard::D) {
      m_world.createUnit(1,Vector2(0,0));
    }

  }

  else if (event.type == sf::Event::MouseMoved) {
    
    if (sf::Mouse::getPosition(m_fsm->m_screen.m_mainWindow).x < 20 &&
        sf::Mouse::getPosition(m_fsm->m_screen.m_mainWindow).x > 0) {
      
      sf::Mouse::setPosition(sf::Vector2i(20, m_mousePosition.y), 
                             m_fsm->m_screen.m_mainWindow);
      
      m_mainCamera.move(-10.0f, 0);
    }

    if (sf::Mouse::getPosition(m_fsm->m_screen.m_mainWindow).x > 
        m_fsm->m_screen.m_mainWindow.getSize().x - 20 &&
        sf::Mouse::getPosition(m_fsm->m_screen.m_mainWindow).x <
        m_fsm->m_screen.m_mainWindow.getSize().x) {
      
      sf::Mouse::setPosition(sf::Vector2i(m_fsm->m_screen.m_mainWindow.getSize().x - 20,
                                          m_mousePosition.y),
                             m_fsm->m_screen.m_mainWindow);

      m_mainCamera.move(10.0f, 0);
    }

    if (sf::Mouse::getPosition(m_fsm->m_screen.m_mainWindow).y < 20 &&
        sf::Mouse::getPosition(m_fsm->m_screen.m_mainWindow).y > 0) {

      sf::Mouse::setPosition(sf::Vector2i(m_mousePosition.x, 20),
                             m_fsm->m_screen.m_mainWindow);

      m_mainCamera.move(0.0f, -10.0f);
    }

    if (sf::Mouse::getPosition(m_fsm->m_screen.m_mainWindow).y >
        m_fsm->m_screen.m_mainWindow.getSize().y - 20 &&
        sf::Mouse::getPosition(m_fsm->m_screen.m_mainWindow).y <
        m_fsm->m_screen.m_mainWindow.getSize().y) {

      sf::Mouse::setPosition(sf::Vector2i(m_mousePosition.x,
                                          m_fsm->m_screen.m_mainWindow.getSize().y - 20),
                             m_fsm->m_screen.m_mainWindow);

      m_mainCamera.move(0.0f, 10.0f);
    }

  }

  else if (event.type == sf::Event::MouseWheelMoved) {
    std::cout << "mouse scrolled" << std::endl;
    if (event.mouseWheel.delta < 0.0f) {
      m_mainCamera.zoom(0.9f); 
      std::cout << event.mouseWheel.delta;
    }

    if (event.mouseWheel.delta > 0.0f) { 
      m_mainCamera.zoom(1.1f); 
      std::cout << event.mouseWheel.delta;
    }
  }


  return true;
}

bool 
Play_State::onInputUpdate(sf::Event event) {
  m_fsm->m_screen.m_mainWindow.setView(m_mainCamera);
  if (event.type == sf::Event::KeyPressed || 
      event.type == sf::Event::MouseMoved ||
      event.type == sf::Event::MouseWheelMoved) {
    return handleInput(event);

  }
  return true;
}

void 
Play_State::onEntry() {
  std::cout << "Playing..." << std::endl;
  m_ID = 5;

  m_world.initialization();

  //Only for testing
  sf::Texture* t = new sf::Texture();
  t->loadFromFile("resources/sprites/minecraft.jpg");
  m_testMap.setTexture(*t);
  m_testMap.setPosition(sf::Vector2f(m_fsm->m_screen.m_mainWindow.getSize().x / 2 -
    m_testMap.getGlobalBounds().width / 2,
    m_fsm->m_screen.m_mainWindow.getSize().y / 2 -
    m_testMap.getGlobalBounds().height / 2));

  //camera creation
  m_mainCamera = { 
    m_fsm->m_screen.m_mainWindow.getDefaultView().getCenter(),
    m_fsm->m_screen.m_mainWindow.getDefaultView().getSize() };
  
  //mini map creation
  m_miniMapCamera = {
    m_fsm->m_screen.m_mainWindow.getDefaultView().getCenter(),
    m_fsm->m_screen.m_mainWindow.getDefaultView().getSize() };
  
  m_miniMapCamera.setViewport(sf::FloatRect(0.05f, 0.705f, 0.25f, 0.25f));
  m_miniMapCamera.zoom(0.9f);
  
  //Main camera setting
  m_fsm->m_screen.m_mainWindow.setView(m_mainCamera);
  m_fsm->m_screen.m_mainWindow.setView(m_fsm->m_screen.m_mainWindow.getDefaultView());
  

}

void 
Play_State::onExit() {
  //delete m_fsm;
}

void
Play_State::onRender(sf::RenderWindow* window) {
  
  window->draw(m_testMap);

  m_fsm->m_screen.m_mainWindow.setView(m_miniMapCamera);
  window->draw(m_testMap);

  m_fsm->m_screen.m_mainWindow.setView(m_mainCamera);

  for (auto unit : m_world.m_unitsInGame) {
    window->draw(unit.m_actualFrame);
  }
} 

void
Play_State::onUpdate() {
  m_mousePosition = sf::Mouse::getPosition(m_fsm->m_screen.m_mainWindow);

  
}

/*******************************************************************************/
bool 
Options_State::handleInput(sf::Event event) {
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

bool 
Options_State::onInputUpdate(sf::Event event) {
  if (event.type == sf::Event::KeyPressed) {
    return handleInput(event);
  }
  return true;
}

void 
Options_State::onEntry() {
  std::cout << "Options" << std::endl;
  m_ID = 6;
}

void 
Options_State::onExit() {
  //delete m_fsm;
}

void
Options_State::onRender(sf::RenderWindow* window) {

}

void
Options_State::onUpdate() {

}

/*******************************************************************************/
bool 
GamePlay_State::handleInput(sf::Event event) {
  if (event.key.code == sf::Keyboard::Escape) {
    return false;
  }
  return true;
}

bool 
GamePlay_State::onInputUpdate(sf::Event event) {
  if (event.type == sf::Event::KeyPressed) {
    return handleInput(event);
  }
  return true;
}

void 
GamePlay_State::onEntry() {
  std::cout << "Gameplay" << std::endl;
  m_ID = 7;
}

void 
GamePlay_State::onExit() {
  //delete m_fsm;
}

void
GamePlay_State::onRender(sf::RenderWindow* window) {

}

void
GamePlay_State::onUpdate() {

}

/*******************************************************************************/
bool
Graphics_State::handleInput(sf::Event event) {
  if (event.key.code == sf::Keyboard::Escape) {
    return false;
  }
  return true;
}

bool 
Graphics_State::onInputUpdate(sf::Event event) {
  if (event.type == sf::Event::KeyPressed) {
    return handleInput(event);
  }
  return true;
}

void 
Graphics_State::onEntry() {
  std::cout << "Graphics" << std::endl;
  m_ID = 8;
}

void 
Graphics_State::onExit() {
  //delete m_fsm;
}

void
Graphics_State::onRender(sf::RenderWindow* window) {

}

void
Graphics_State::onUpdate() {

}

/*******************************************************************************/
bool 
Sound_State::handleInput(sf::Event event) {
  if (event.key.code == sf::Keyboard::Escape) {
    return false;
  }
  return true;
}

bool 
Sound_State::onInputUpdate(sf::Event event) {
  if (event.type == sf::Event::KeyPressed) {
    return handleInput(event);
  }
  return true;
}

void 
Sound_State::onEntry() {
  std::cout << "Sound" << std::endl;
  m_ID = 9;
}

void 
Sound_State::onExit() {
  //delete m_fsm;
}

void
Sound_State::onRender(sf::RenderWindow* window) {

}

void
Sound_State::onUpdate() {

}
