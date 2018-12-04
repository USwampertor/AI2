#include "Unit.h"


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
