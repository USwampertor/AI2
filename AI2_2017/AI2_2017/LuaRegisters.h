/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file LuaRegisters.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/15 2018
 * @brief Lua registration of basic objects
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include <lua.hpp>
#include "Character.h"


int
createCharacter(lua_State* L) {
  const char* name = luaL_checkstring(L, 1);

  Character** userdata = (Character**)lua_newuserdata(L, sizeof(Character*));
  *userdata = new Character(name);
  luaL_getmetatable(L, "luaCharacter");
  lua_setmetatable(L, -2);
  return 1;
}

int
copyCharacter(lua_State* L) {
  Character* copy = getCharacter(L, 1);
  Character** userdata = (Character**)lua_newuserdata(L, sizeof(Character*));
  userdata = &copy;
  luaL_getmetatable(L, "luaCharacter");
  lua_setmetatable(L, -2);
  return 1;
}


Character*
getCharacter(lua_State* L, int n) {
  return *(Character**)luaL_checkudata(L, n, "luaCharacter");
}

int
characterSetName(lua_State* L) {
  Character* c = getCharacter(L, 1);
  const char* name = luaL_checkstring(L, 2);
  c->setName(name);
  //lua_pushstring(L, name);
  return 1;
}

int
characterGetName(lua_State* L) {
  Character* c = getCharacter(L, 1);
  //c->getName();
  lua_pushstring(L, c->getName());
  return 1;
}

int
destroyCharacter(lua_State* L) {
  Character* c = getCharacter(L, 1);
  delete c;
  return 0;
}

void
registerCharacter(lua_State* L) {
  luaL_Reg characterRegs[] = {
    {"new",     createCharacter},
    {"setName", characterSetName},
    {"getName", characterGetName},
    {"copy", copyCharacter},
    {NULL, NULL}
  };
  luaL_newmetatable(L, "luaCharacter");
  luaL_setfuncs(L, characterRegs, 0);
  lua_pushvalue(L, -1);
  lua_setfield(L, -1, "__index");
  lua_setglobal(L, "Character");
}
