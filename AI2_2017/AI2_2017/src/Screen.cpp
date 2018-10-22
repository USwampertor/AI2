/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file Screen.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/09/28 2018
 * @brief the pp file of the Screen class | Method definition
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#include "stdafx.h"
#include "Screen.h"
#include "State.h"


Screen::~Screen() {
  
}

void 
Screen::onRender() {
  m_mainWindow.draw(m_shape);
  m_mainWindow.draw(m_text);
  m_mainWindow.draw(m_logo);
}

bool 
Screen::createWindow() {
  //(sf::VideoMode(800, 400), "AI 2018 C");
  //m_mainWindow = {sf::VideoMode(800, 400), "AI 2018 C"};
  m_mainWindow.create(sf::VideoMode(800, 400), "AI 2018 C");
  m_shape.setPosition(sf::Vector2f(0.0f,0.0f));
  m_shape.setSize(sf::Vector2f(800.0f,400.0f));
  m_texture.loadFromFile("resources/Pato.png");
  m_logo.setTexture(m_texture);
  m_logo.setPosition(sf::Vector2f(200,100));
  m_logo.setRotation(45.f);
  m_logo.setPosition(m_logo.getPosition().x, m_logo.getPosition().y*2.0f);
  return true;
}

void 
Screen::CheckState(State* s)
{
  if      (s->m_ID == 0) { m_shape.setFillColor(sf::Color::Blue   ); }
  else if (s->m_ID == 1) { m_shape.setFillColor(sf::Color::Green  ); }
  else if (s->m_ID == 2) { m_shape.setFillColor(sf::Color::Red    ); }
  else if (s->m_ID == 3) { m_shape.setFillColor(sf::Color::Magenta); }
  else if (s->m_ID == 4) { m_shape.setFillColor(sf::Color::Black  ); }
  else if (s->m_ID == 5) { m_shape.setFillColor(sf::Color::Yellow ); }
  else if (s->m_ID == 6) { m_shape.setFillColor(sf::Color::Cyan   ); }
  else if (s->m_ID == 7) { m_shape.setFillColor(sf::Color::Color(150, 100, 100, 255)); }
  else if (s->m_ID == 8) { m_shape.setFillColor(sf::Color::Color(150, 150, 100, 255)); }
  else if (s->m_ID == 9) { m_shape.setFillColor(sf::Color::Color(150, 100, 200, 255)); }
  
  std::stringstream alfa;
  std::string a;
  alfa << s->m_ID;
  alfa >> a;
  m_text.setString(a);
}
