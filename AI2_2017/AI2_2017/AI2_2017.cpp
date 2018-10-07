/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file AI2_2017.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/09/28 2018
 * @brief The main entry of the AI2_2017
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#include "stdafx.h"
#include "App.h"

int main() {
  App game;
  if(!game.onEntry()) {return 0;}
  game.onUpdate();
  return 0;
}


