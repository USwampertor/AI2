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
}

bool 
Screen::createWindow() {
  m_mainWindow.create(sf::VideoMode(800, 400), "AI 2018 C");
  return true;
}

void 
Screen::CheckState(State* s)
{
 
}
