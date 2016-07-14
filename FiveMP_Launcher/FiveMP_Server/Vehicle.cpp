#include "stdafx.h"

SVehicle::SVehicle()
{
}

SVehicle::~SVehicle()
{
}

void SVehicle::SpawnVehicles(int playerid)
{
	for (int i = 0; i < sizeof(vehicleData) / sizeof(*vehicleData); i++) {
		if (vehicleData[i].used == true) {

			RakNet::BitStream sCreateVehicle;
			sCreateVehicle.Write(vehicleData[i].vehicleid);
			sCreateVehicle.Write(vehicleData[i].vehicleModel);
			sCreateVehicle.Write(vehicleData[i].x);
			sCreateVehicle.Write(vehicleData[i].y);
			sCreateVehicle.Write(vehicleData[i].z);
			sCreateVehicle.Write(vehicleData[i].r);
			sCreateVehicle.Write(vehicleData[i].vehicleColor1);
			sCreateVehicle.Write(vehicleData[i].vehicleColor2);
			sCreateVehicle.Write(vehicleData[i].respawn);
			sCreateVehicle.Write(vehicleData[i].respawndelay);
			NetworkManager->rpc.Signal("CreateVehicle", &sCreateVehicle, HIGH_PRIORITY, RELIABLE_ORDERED, 0, netPool.GetPlayerGUIDfromId(playerid), false, false);
		}
	}
}
