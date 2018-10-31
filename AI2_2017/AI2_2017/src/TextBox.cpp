/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file TextBox.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/10/15 2018
 * @brief TextBox member definition
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#include "Textbox.h"

TextBox
TextBox::operator = (const TextBox& other) const {
  return TextBox(other);
}

void
TextBox::setData(std::string userData) {
  m_text.setString(userData);
}

void
TextBox::setPosition(float x, float y) {
  m_box.setPosition(x, y);
  m_text.setPosition(x + m_box.getSize().x / 3.0f, y + m_box.getSize().y / 3.0f);
}

void
TextBox::setPosition(sf::Vector2f position) {
  m_box.setPosition(position);
  m_text.setPosition(position.x, position.y + m_box.getSize().y / 3.0f);
}

void
TextBox::setSize(float x, float y) {
  m_box.setSize(sf::Vector2f(x, y));
}

void
TextBox::setBoxColor(sf::Color color) {
  m_box.setFillColor(color);
}

void
TextBox::setSprite(std::string resourceName) {
  sf::Texture* texture = new sf::Texture();
  if (!texture->loadFromFile(resourceName)) {
    std::cout << "Couldn't load file with name " << resourceName << std::endl;
  }
  m_box.setTexture(texture);
}


bool
TextBox::CheckClick(sf::Vector2i mousePos) {

  return (mousePos.x > m_box.getPosition().x &&
          mousePos.x < m_box.getPosition().x + m_box.getSize().x &&
          mousePos.y > m_box.getPosition().y &&
          mousePos.y < m_box.getPosition().y + m_box.getSize().y);
}

void
TextBox::draw(sf::RenderWindow* window) {
  window->draw(m_box);
  window->draw(m_text);
}