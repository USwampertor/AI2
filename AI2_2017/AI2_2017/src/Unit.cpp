/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file Unit.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/12/04 2018
 * @brief Unit member definition
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#include "Unit.h"

bool
Unit::initialize() {
  m_idleS   = new Idle_State();
  m_attackS = new Attack_State();
  m_runS    = new Run_State();
  m_deadS   = new Dead_State();
  m_orientation = { 1 , 0 };
  m_currentState = nullptr;
  setState(m_idleS);
  
  return true;
}

DIR
Unit::orientation() {
  float angle = (float)std::atan(m_orientation.y / m_orientation.x) * 3.14159 / 180;
  //Looking Right

  if (angle < 67.5f && angle > 22.5f) {
    m_actualFrame.m_flipped = false;
    return DIR::NEAST;
  }

  if (angle < 112.5f  && angle > 67.5f) {
    m_actualFrame.m_flipped = false;
    return DIR::NORTH;
  }

  if (angle < 157.5f && angle > 112.5f) {
    m_actualFrame.m_flipped = false;
    return DIR::NWEST;
  }

  if (angle < 202.5f && angle > 157.5f) {
    m_actualFrame.m_flipped = false;
    return DIR::WEST;
  }

  if (angle < 247.5f && angle > 202.5f) {
    m_actualFrame.m_flipped = false;
    return DIR::SWEST;
  }

  if (angle < 292.5f && angle > 247.5f) {
    m_actualFrame.m_flipped = true;
    return DIR::SOUTH;
  }

  if (angle < 337.5F && angle > 292.5f) {
    m_actualFrame.m_flipped = true;
    return DIR::SEAST;
  }

  m_actualFrame.m_flipped = true;
  return DIR::EAST;
}

void
Unit::update(float deltaTime) {
  m_timeInState += deltaTime;

  float AnimDuration = 0.75f;
  float numFrames = 10.0f;
  float rate = AnimDuration / numFrames;

  float modTA = std::fmodf(m_timeInState, AnimDuration);
  int actualFrame = (int)((float)(modTA / rate));
  m_actualFrame = m_anim.m_frame[m_currentState->getANIM()][orientation()][actualFrame];

}

void
Unit::setState(UnitState* state) {
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

  else if (m_currentState != nullptr) {
    //m_stateStack.pop();
    state->m_owner = this;
    m_stateStack.push(state);
    m_currentState->onExit();
    m_currentState = m_stateStack.top();
    m_currentState->onEntry();
    m_timeInState = 0;
  }

  else {
    state->m_owner = this;
    m_stateStack.push(state);
    m_currentState = m_stateStack.top();
    m_currentState->onEntry();
  }
}

void
Unit::finish() {

}

void
Unit::setName(const char* name) {
  m_name = name;
}

const char*
Unit::getName() {
  return m_name.c_str();
}

void
Unit::setType(int type) {
  m_type = type;
}

const int
Unit::getType() {
  return m_type;
}



/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * Unit.cpp Lua function definition
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

int
createUnit(lua_State* L) {
  int type = static_cast<int>(luaL_checknumber(L, 1));

  Unit** userdata = (Unit**)lua_newuserdata(L, sizeof(Unit*));
  *userdata = new Unit(type);
  luaL_getmetatable(L, "luaUnit");
  lua_setmetatable(L, -2);
  return 1;
}

int
copyUnit(lua_State* L) {
  Unit* copy = getUnit(L, 1);
  Unit** userdata = (Unit**)lua_newuserdata(L, sizeof(Unit*));
  userdata = &copy;
  luaL_getmetatable(L, "luaUnit");
  lua_setmetatable(L, -2);
  return 1;
}

int
destroyUnit(lua_State* L) {
  Unit* c = getUnit(L, 1);
  delete c;
  return 0;
}

Unit*
getUnit(lua_State* L, int n) {
  return *(Unit**)luaL_checkudata(L, n, "luaUnit");
}

int
unitGetName(lua_State* L) {
  Unit* c = getUnit(L, 1);
  //c->getName();
  lua_pushstring(L, c->getName());
  return 1;
}

int
unitSetName(lua_State* L) {
  Unit* c = getUnit(L, 1);
  const char* name = luaL_checkstring(L, 2);
  c->setName(name);
  //lua_pushstring(L, name);
  return 1;
}

int
unitGetType(lua_State* L) {
  Unit* c = getUnit(L, 1);
  //c->getName();
  lua_pushnumber(L, c->getType());
  return 1;
}

int
unitSetType(lua_State* L) {
  Unit* c = getUnit(L, 1);
  int name = static_cast<int>(luaL_checknumber(L, 2));
  c->setType(name);
  //lua_pushstring(L, name);
  return 1;
}

void
registerUnit(lua_State* L) {
  luaL_Reg unitRegs[] = {
    {"new",     createUnit},
    {"setName", unitSetName},
    {"getName", unitGetName},
    {"copy", copyUnit},
    {NULL, NULL}
  };
  luaL_newmetatable(L, "luaUnit");
  luaL_setfuncs(L, unitRegs, 0);
  lua_pushvalue(L, -1);
  lua_setfield(L, -1, "__index");
  lua_setglobal(L, "Unit");
}
