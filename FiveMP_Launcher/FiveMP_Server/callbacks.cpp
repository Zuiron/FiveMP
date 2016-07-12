#include "stdafx.h"

int OnGameModeInit(lua_State* state)
{
	int result;

	printf("OnGameModeInit() was called\n");

	lua_getglobal(state, "OnGameModeInit");

	lua_call(state, 0, 1);

	result = (int)lua_tointeger(state, -1);
	lua_pop(state, 1);

	return result;
}

int OnGameModeExit(lua_State * state)
{
	int result;

	printf("OnGameModeExit() was called\n");

	lua_getglobal(state, "OnGameModeExit");

	lua_call(state, 0, 1);

	result = (int)lua_tointeger(state, -1);
	lua_pop(state, 1);

	return result;
}

int OnPlayerConnect(lua_State * state, int playerid)
{
	int result;

	printf("OnPlayerConnect() was called with %d\n", playerid);

	lua_getglobal(state, "OnPlayerConnect");

	lua_pushnumber(state, playerid);

	lua_call(state, 1, 1);

	result = lua_tointeger(state, -1);
	lua_pop(state, 1);

	return result;
}

int OnPlayerDisconnect(lua_State * state, int playerid)
{
	int result;

	printf("OnPlayerDisconnect() was called with %d\n", playerid);

	lua_getglobal(state, "OnPlayerDisconnect"); // <---Change it on main.lua

	lua_pushnumber(state, playerid);

	lua_call(state, 1, 1);

	result = lua_tointeger(state, -1);
	lua_pop(state, 1);

	return result;
}
