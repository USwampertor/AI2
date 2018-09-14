#pragma once
class State
{
public:
  App* m_appParent;
	State() = default;
	virtual ~State() {};
  virtual void handleInput() {};
  virtual void update() {};
  virtual void onEntry() {};
  virtual void onExit() {};
};

class Pause_State : public State
{

};
class Logo_State : public State
{

};
class Help_State : public State
{

};
class Menu_State : public State
{

};
class GameOver_State : public State
{

};
class Play_State : public State
{

};
class Options_State : public State
{

};
class GamePlay_State : public State
{

};
class Graphics_State : public State
{

};
class Sound_State : public State
{

};