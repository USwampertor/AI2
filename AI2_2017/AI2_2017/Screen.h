#pragma once
#include "Utilities.h"
class State;
class Screen
{
 public:
  Screen() = default;
  ~Screen();
  sf::RenderWindow m_mainWindow;
  std::vector<sf::Drawable*> m_objects;
  void onRender();
  bool createWindow();
  void CheckState(State* s);
  sf::RectangleShape m_shape;
};

