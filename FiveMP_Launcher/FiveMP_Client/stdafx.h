#pragma once

#define WIN32_LEAN_AND_MEAN

// Windows Header Files:
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <intrin.h>
#include <string>
#include <map>
#include <string.h>
#include <vector>
#include <sstream>
#include <Psapi.h>
#include <iostream>
#include <fstream>
#include <timeapi.h>
#include <time.h>
#include <tlhelp32.h>
#include <math.h>
#include <iostream>
#include <future>
using namespace std;

#pragma comment(lib, "winmm.lib")

// RakNet
#include <MessageIdentifiers.h>
#include <RakPeerInterface.h>
#include <RakNetStatistics.h>
#include <RakNetTypes.h>
#include <BitStream.h>
#include <RakSleep.h>
#include <PacketLogger.h>
#include <Kbhit.h>
#include <Gets.h>
#include <WindowsIncludes.h>
#include <GetTime.h>
#include <RPC4Plugin.h>
using namespace RakNet;

// ScriptHook
#include <natives.h>
#include <types.h>
#include <enums.h>
#include <sh_main.h>
#include <keyboard.h>

// INI Reader
#include <IniWriter.h>
#include <IniReader.h>

// Client
#include "main.h"

// Rockstar
#include "Log.h"
#include "RAGEHelper.h"
#include "DrawHelper.h"
#include "Pattern.h"

// Game Functions
#include "Player.h"
#include "Weapon.h"
#include "Vehicles.h"
#include "World.h"
#include "Model.h"
#include "Blips.h"

// Math
#include "CMath.h"
#include "CVector3.h"

// Modification (FiveMP)
#include "Config.h"
#include "ScriptHook.h"

// Net
#include "NetworkManager.h"
#include "PlayerPed.h"
#include "LocalPlayer.h"
#include "LocalVehicle.h"
#include "RPCManager.h"
#include "Script.h"
#include "PlayerPool.h"

// Interface
#include "RenderDebug.h"
#include "Render.h"

namespace {
	// Classes (scripthook)
	class ScriptHook hook;

	// Classes (scripts)
	class GamePlayer player;
	class GameWeapon weapon;
	class GameWorld world;
	class GameVehicle vehicle;
}

extern MODULEINFO	g_MainModuleInfo;

extern CNetworkManager	*NetworkManager;
extern CRPCManager		*RPCManager;
extern CLocalPlayer		*LocalPlayer;
extern CLocalVehicle	*LocalVehicle;
extern CConfig			*Config;
extern CRenderDebug		*RenderDebug;
extern CRender			*Render;