#pragma once

void ShowMessageToPlayer(RakNet::BitStream *bitStream, RakNet::Packet *packet);
void GivePlayerWeapon(RakNet::BitStream *bitStream, RakNet::Packet *packet);
void RemovePlayerWeapon(RakNet::BitStream *bitStream, RakNet::Packet *packet);
void GivePlayerAmmo(RakNet::BitStream *bitStream, RakNet::Packet *packet);
void RemovePlayerAmmo(RakNet::BitStream *bitStream, RakNet::Packet *packet);
void SetPlayerMoney(RakNet::BitStream *bitStream, RakNet::Packet *packet);
void SetPlayerPos(RakNet::BitStream *bitStream, RakNet::Packet *packet);
void SetPlayerFacingAngle(RakNet::BitStream *bitStream, RakNet::Packet *packet);