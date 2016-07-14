#include "stdafx.h"

// -- WEAPON --
void ShowMessageToPlayer(RakNet::BitStream *bitStream, RakNet::Packet *packet) {
	int playerid;
	char string[128];

	bitStream->Read(string);

	player.ShowMessageAboveMap(string);
}

void GivePlayerWeapon(RakNet::BitStream *bitStream, RakNet::Packet *packet) {
	int playerid;
	char weaponid[20];
	int ammo;

	bitStream->Read(playerid);
	bitStream->Read(weaponid);
	bitStream->Read(ammo);

	weapon.GiveWeapon(weaponid, ammo);
}

void RemovePlayerWeapon(RakNet::BitStream *bitStream, RakNet::Packet *packet) {
	int playerid;
	char weaponid[20];

	bitStream->Read(playerid);
	bitStream->Read(weaponid);

	weapon.RemoveWeapon(weaponid);
}

void GivePlayerAmmo(RakNet::BitStream *bitStream, RakNet::Packet *packet) {
	int playerid;
	char weaponid[20];
	int ammo;

	bitStream->Read(playerid);
	bitStream->Read(weaponid);
	bitStream->Read(ammo);

	weapon.GiveAmmo(weaponid, ammo);
}

void RemovePlayerAmmo(RakNet::BitStream *bitStream, RakNet::Packet *packet) {
	int playerid;
	char weaponid[20];
	int ammo;

	bitStream->Read(playerid);
	bitStream->Read(weaponid);
	bitStream->Read(ammo);

	weapon.RemoveAmmo(weaponid, ammo);
}

void RemoveAllPlayerWeapons(RakNet::BitStream *bitStream, RakNet::Packet *packet) {
	int playerid;
	bitStream->Read(playerid);

	weapon.RemoveAllWeapons();
}

// -- MONEY --
void SetPlayerMoney(RakNet::BitStream* bitStream, RakNet::Packet *packet) {
	int playerid;
	int amount;

	bitStream->Read(playerid);
	bitStream->Read(amount);

	LocalPlayer->playerMoney = amount;
	UI::_SET_SINGLEPLAYER_HUD_CASH(amount, amount);

	for (int i = 0; i < 3; i++)
	{
		char statNameFull[32];
		sprintf_s(statNameFull, "SP%d_TOTAL_CASH", i);
		Hash hash = GAMEPLAY::GET_HASH_KEY(statNameFull);
		int val;
		STATS::STAT_GET_INT(hash, &val, -1);
		val = amount;
		STATS::STAT_SET_INT(hash, val, 1);
	}
}

// -- POSITION --
void SetPlayerPos(RakNet::BitStream* bitStream, RakNet::Packet *packet) {
	int playerid;
	float posx;
	float posy;
	float posz;

	bitStream->Read(playerid);
	bitStream->Read(posx);
	bitStream->Read(posy);
	bitStream->Read(posz);

	LocalPlayer->SetPos(posx, posy, posz);
}

void SetPlayerFacingAngle(RakNet::BitStream * bitStream, RakNet::Packet * packet)
{
	int playerid;
	float rotation;

	bitStream->Read(playerid);
	bitStream->Read(rotation);

	LocalPlayer->SetHeading(rotation);
}

void SetPlayerHealth(RakNet::BitStream * bitStream, RakNet::Packet * packet)
{
	int playerid;
	int health;

	bitStream->Read(playerid);
	bitStream->Read(health);

	LocalPlayer->SetHealth(health);
}

void SetPlayerArmour(RakNet::BitStream * bitStream, RakNet::Packet * packet)
{
	int playerid;
	int armour;

	bitStream->Read(playerid);
	bitStream->Read(armour);

	LocalPlayer->SetArmour(armour);
}

void SetPlayerMaxNickDrawDistance(RakNet::BitStream * bitStream, RakNet::Packet * packet) {
	int playerid;
	float distance;

	bitStream->Read(playerid);
	bitStream->Read(distance);

	LocalPlayer->maxNickDrawDistance = distance;
}

void SetPlayerModel(RakNet::BitStream * bitStream, RakNet::Packet * packet)
{
	int playerid;
	int modelid;

	bitStream->Read(playerid);
	bitStream->Read(modelid);

	LocalPlayer->SetModel(GetModelHashFromModelID(modelid));
}

void CreateVehicle(RakNet::BitStream * bitStream, RakNet::Packet * packet)
{
	int vehicleid;
	char vehiclename[32];

	bitStream->Read(vehicleid);
	
	vehicleData[vehicleid].vehicleid = vehicleid;

	bitStream->Read(vehiclename);
	bitStream->Read(vehicleData[vehicleid].x);
	bitStream->Read(vehicleData[vehicleid].y);
	bitStream->Read(vehicleData[vehicleid].z);
	bitStream->Read(vehicleData[vehicleid].r);
	bitStream->Read(vehicleData[vehicleid].vehicleColor1);
	bitStream->Read(vehicleData[vehicleid].vehicleColor2);
	bitStream->Read(vehicleData[vehicleid].respawn);
	bitStream->Read(vehicleData[vehicleid].respawndelay);

	Vector3 tempcoords;
	tempcoords.x = vehicleData[vehicleid].x;
	tempcoords.y = vehicleData[vehicleid].y;
	tempcoords.z = vehicleData[vehicleid].z;

	vehicle.CreateVehicle(vehicleid, vehiclename, tempcoords, vehicleData[vehicleid].r, vehicleData[vehicleid].vehicleColor1, vehicleData[vehicleid].vehicleColor2, vehicleData[vehicleid].respawn, vehicleData[vehicleid].respawndelay);
}

void SetPedComponentVariation(RakNet::BitStream * bitStream, RakNet::Packet * packet)
{
	int playerid;
	int componentid;
	int drawableid;
	int textureid;
	int paletteid;

	bitStream->Read(playerid);
	bitStream->Read(componentid);
	bitStream->Read(drawableid);
	bitStream->Read(textureid);
	bitStream->Read(paletteid);

	PED::SET_PED_COMPONENT_VARIATION(LocalPlayer->playerPed, componentid, drawableid, textureid, paletteid);
}

void ShowBlipForPlayer(RakNet::BitStream * bitStream, RakNet::Packet * packet)
{
	int blipid;
	int locationtype;
	float x;
	float y;
	float z;
	int attachID;

	bitStream->Read(blipid);
	bitStream->Read(locationtype);
	bitStream->Read(x);
	bitStream->Read(y);
	bitStream->Read(z);
	bitStream->Read(attachID);

	int clientblipid = -1;
	for (int i = 0; i < 100; i++) {
		if (!blipData[i].used) {
			clientblipid = i;
			break;
		}
	}

	if (clientblipid == -1) { return; }

	blipData[clientblipid].used = true;
	blipData[clientblipid].serverID = blipid;
	
	if (locationtype == 0) {
		blipData[clientblipid].blip = UI::ADD_BLIP_FOR_COORD(x, y, z);
	}
	else if (locationtype == 1) {
		int vehicleid = -1;
		for (int i = 0; i < 100; i++) {
			if (attachID == vehicleData[i].vehicleid) {
				vehicleid = vehicleData[i].vehicleVehicle;
				break;
			}
		}
		if (vehicleid == -1) { return; }

		blipData[clientblipid].blip = UI::ADD_BLIP_FOR_ENTITY(vehicleid);
	}
	else if (locationtype == 2) {

		if (attachID != LocalPlayer->playerID) {
			blipData[clientblipid].blip = UI::ADD_BLIP_FOR_ENTITY(attachID);
		}
		else {
			blipData[clientblipid].blip = UI::ADD_BLIP_FOR_ENTITY(LocalPlayer->playerPed);
		}
	}

	UI::SET_BLIP_AS_FRIENDLY(blipData[clientblipid].blip, true);
	UI::SET_BLIP_COLOUR(blipData[clientblipid].blip, 0);
	UI::SET_BLIP_SCALE(blipData[clientblipid].blip, 1.0f);
	UI::BEGIN_TEXT_COMMAND_SET_BLIP_NAME("STRING");
	UI::_ADD_TEXT_COMPONENT_STRING3("Test");
	UI::END_TEXT_COMMAND_SET_BLIP_NAME(blipData[clientblipid].blip);
	
}

void HideBlipFromPlayer(RakNet::BitStream * bitStream, RakNet::Packet * packet)
{
	int blipid;

	bitStream->Read(blipid);

	for (int i = 0; i < 100; i++) {
		if (blipData[i].serverID == blipid) {
			UI::REMOVE_BLIP(&blipData[i].blip);
			blipData[i].used = false;
			break;
		}
	}
}
