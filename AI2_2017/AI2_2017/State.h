#pragma once
#include "Utilities.h"
//#include "App.h"


class App;
class State {
 public:
  State() {m_fsm = nullptr; };
  virtual ~State() {};

  bool operator == (State* s);

  virtual bool handleInput(sf::Event event) = 0;
  virtual bool onUpdate(sf::Event event) = 0;
  virtual void onEntry() = 0;
  virtual void onExit() = 0;
 
 public:
  App* m_fsm;
  unsigned short m_ID;
  
};

class Pause_State : public State {
 public:
   bool handleInput(sf::Event event);
   bool onUpdate(sf::Event event);
   void onEntry();
   void onExit();
};
class Logo_State : public State {
 public:
  bool handleInput(sf::Event event);
  bool onUpdate(sf::Event event);
  void onEntry();
  void onExit();
  
 public:
  int counter;
};

class Help_State : public State {
 public:
  bool handleInput(sf::Event event);
  bool onUpdate(sf::Event event);
  void onEntry();
  void onExit();
  
};

class Menu_State : public State {
 public:
  bool handleInput(sf::Event event);
  bool onUpdate(sf::Event event);
  void onEntry();
  void onExit();
  
};

class GameOver_State : public State {
 public:
   bool handleInput(sf::Event event);
   bool onUpdate(sf::Event event);
   void onEntry();
   void onExit();
  
};
class Play_State : public State {
 public:
  bool handleInput(sf::Event event);
  bool onUpdate(sf::Event event);
  void onEntry();
  void onExit();
  
};
class Options_State : public State {
 public:
  bool handleInput(sf::Event event);
  bool onUpdate(sf::Event event);
  void onEntry();
  void onExit();
  
};
class GamePlay_State : public State {
 public:
  bool handleInput(sf::Event event);
  bool onUpdate(sf::Event event);
  void onEntry();
  void onExit();
  
};

class Graphics_State : public State {
 public:
  bool handleInput(sf::Event event);
  bool onUpdate(sf::Event event);
  void onEntry();
  void onExit();
  
};

class Sound_State : public State {
 public:
  bool handleInput(sf::Event event);
  bool onUpdate(sf::Event event);
  void onEntry();
  void onExit();
  
};