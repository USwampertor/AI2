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

/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * State.cpp Base state
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
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

/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * State.cpp Logo state
 */
 /*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
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

/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * State.cpp Help state
 */
 /*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
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

/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * State.cpp Menu state
 */
 /*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
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

  m_title.m_font = 
    std::static_pointer_cast<Font>(m_fsm->m_resourceManager.loadFromFile(RESOURCETYPE::FONT,
                                                            "resources/fonts/BCastle.ttf"));
  m_title.m_text.setFont(m_title.m_font->m_font);
  m_title.m_text.setCharacterSize(30);
  m_title.m_text.setString("RUNESTONE");
  m_title.m_text.setOutlineThickness(2.0f);
  m_title.m_text.setFillColor(sf::Color::Black);
  m_title.m_text.setOutlineColor(sf::Color::White);
  m_title.m_text.setPosition(sf::Vector2f(m_fsm->m_screen.m_mainWindow.getSize().x / 2 -
                                          m_title.m_text.getLocalBounds().width / 2,
                                          m_fsm->m_screen.m_mainWindow.getSize().y / 2 -
                                          m_title.m_text.getLocalBounds().height / 2 ));
  m_play.m_text.m_font = 
    std::static_pointer_cast<Font>(m_fsm->m_resourceManager.loadFromFile(RESOURCETYPE::FONT,
                                                            "resources/fonts/BCastle.ttf"));
  m_play.m_text.m_text.setFont(m_play.m_text.m_font->m_font);
  m_play.m_text.m_text.setCharacterSize(30);
  m_play.m_text.m_text.setString("PLAY");
  m_play.m_text.m_text.setOutlineThickness(2.0f);
  m_play.m_text.m_text.setFillColor(sf::Color::Black);
  m_play.m_text.m_text.setOutlineColor(sf::Color::Red);
  m_play.setSize(100.0f, 100.0f);
  m_play.setSprite("resources/sprites/startButton.png");
  m_play.setPosition(sf::Vector2f((float)m_fsm->m_screen.m_mainWindow.getSize().x / 2 -
                                  (float)m_play.m_box.getLocalBounds().width / 2,
                                  (float)m_fsm->m_screen.m_mainWindow.getSize().y / 2));

}

void 
Menu_State::onExit() {
}

void
Menu_State::onRender(sf::RenderWindow* window) {
  window->draw(m_map);
  window->draw(m_title.m_text);
  m_play.draw(window);
}

void
Menu_State::onUpdate() {
  
}

/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * State.cpp Game Over state
 */
 /*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
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

/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * State.cpp Play state
 */
 /*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
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

    if (event.key.code == sf::Keyboard::U) {
      m_world.createUnit(2, Vector2(std::rand() % 50, std::rand() % 50));
      
    }

  }

  else if (event.type == sf::Event::MouseMoved) {
    
    if (sf::Mouse::getPosition(m_fsm->m_screen.m_mainWindow).x < 20 &&
        sf::Mouse::getPosition(m_fsm->m_screen.m_mainWindow).x > 0) {
      
      sf::Mouse::setPosition(sf::Vector2i(20, m_mousePosition.y), 
                             m_fsm->m_screen.m_mainWindow);
      
      m_mainCamera.move(-10.0f, 0);
    }

    if ((unsigned int)sf::Mouse::getPosition(m_fsm->m_screen.m_mainWindow).x > 
        m_fsm->m_screen.m_mainWindow.getSize().x - 20 &&
        (unsigned int)sf::Mouse::getPosition(m_fsm->m_screen.m_mainWindow).x <
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

    if ((unsigned int)sf::Mouse::getPosition(m_fsm->m_screen.m_mainWindow).y >
        m_fsm->m_screen.m_mainWindow.getSize().y - 20 &&
        (unsigned int)sf::Mouse::getPosition(m_fsm->m_screen.m_mainWindow).y <
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

  else if (event.type == sf::Event::MouseButtonPressed) {
    if (event.mouseButton.button == sf::Mouse::Left) {
      //m_anchor = m_mousePosition;
      
      m_anchor = m_worldPosition;
      m_mouseRect.setPosition(sf::Vector2f(m_anchor.x, m_anchor.y));
      m_pressed = true;
      std::cout << "HOLDING MOUSE \n";
    }
    else if (event.mouseButton.button == sf::Mouse::Right) {
      for (int i = 0; i < m_world.m_activeUnits.size(); ++i) {
        m_world.m_activeUnits[i]->m_objective = Vector2(m_worldPosition.x, m_worldPosition.y);
        m_world.m_activeUnits[i]->setState(m_world.m_activeUnits[i]->m_runS);
      }
    }
  }
  else if (event.type == sf::Event::MouseButtonReleased) {
    if (event.mouseButton.button == sf::Mouse::Left) {
      if (m_pressed) {
        m_world.clearActiveUnits();
        m_pressed = false;
        Frame t = {Vector2(m_mouseRect.getSize().x,m_mouseRect.getSize().y), 
                   Vector2(m_anchor.x,m_anchor.y),
                   false };
        m_world.insertActiveUnits(t);
      }
      std::cout << "RELEASING MOUSE \n";
    }
  }
  return true;
}

bool 
Play_State::onInputUpdate(sf::Event event) {
  m_fsm->m_screen.m_mainWindow.setView(m_mainCamera);
  if (event.type == sf::Event::KeyPressed         || 
      event.type == sf::Event::MouseMoved         ||
      event.type == sf::Event::MouseWheelMoved    ||
      event.type == sf::Event::MouseButtonPressed ||
      event.type == sf::Event::MouseButtonReleased ) {
    return handleInput(event);

  }
  return true;
}

void 
Play_State::onEntry() {
  std::cout << "Playing..." << std::endl;
  m_ID = 5;
  m_pressed = false;
 
  m_world.initialization();
  m_world.m_resourceManager = &m_fsm->m_resourceManager;
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
  
  m_mouseRect.setOutlineThickness(2);
  m_mouseRect.setOutlineColor(sf::Color::Blue);
  m_mouseRect.setFillColor(sf::Color::Transparent);
}

void 
Play_State::onExit() {
  //delete m_fsm;
}

void
Play_State::onRender(sf::RenderWindow* window) {
  
  m_worldPosition = sf::Mouse::getPosition(m_fsm->m_screen.m_mainWindow);
  m_worldPosition = sf::Vector2i(window->mapPixelToCoords(m_worldPosition, m_mainCamera).x,
                                 window->mapPixelToCoords(m_worldPosition, m_mainCamera).y);
  window->draw(m_testMap);

  for (auto unit : m_world.m_unitsInGame) {
    sf::Sprite t;
    t.setTexture(unit->m_SpriteResource->m_texture);
    t.setTextureRect(sf::IntRect((int)unit->m_actualFrame.position.x,
                                 (int)unit->m_actualFrame.position.y,
                                 (int)unit->m_actualFrame.size.x,
                                 (int)unit->m_actualFrame.size.y));
    t.setPosition(unit->getPosition().x, unit->getPosition().y);
    if (unit->m_actualFrame.m_flipped) { t.scale(-1,1); }
    window->draw(t);
  }

  if (m_pressed) { window->draw(m_mouseRect); }

  m_fsm->m_screen.m_mainWindow.setView(m_miniMapCamera);
  window->draw(m_testMap);

  m_fsm->m_screen.m_mainWindow.setView(m_mainCamera);
} 

void
Play_State::onUpdate() {
  float deltaTime = m_time.restart().asSeconds();
  m_mousePosition = sf::Mouse::getPosition(m_fsm->m_screen.m_mainWindow);
  //m_mousePosition = sf::Mouse::getPosition();
  
  if (m_pressed) { m_mouseRect.setSize(sf::Vector2f(m_worldPosition - m_anchor)); }
  
  for (unsigned int i = 0; i < m_world.m_unitsInGame.size(); ++i) {
    m_world.m_unitsInGame[i]->update(deltaTime);
  }
}

/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * State.cpp Options state
 */
 /*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
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

/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * State.cpp Game Play state
 */
 /*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
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

/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * State.cpp Graphics state
 */
 /*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
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

/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * State.cpp Sound state
 */
 /*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
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
