#pragma once
class CLocalPlayer
{
public:
	Ped		playerPed;
	bool	playerInitialized = false;

	CLocalPlayer();
	~CLocalPlayer();

	void	Initialize();
	void	OnTick();

	Hash	GetModel() { return ENTITY::GET_ENTITY_MODEL(playerPed); };
	Vector3 GetCoords() { return ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(playerPed, 0.0, 0.0, -1.0f); };
	Vector3 GetVelocity() { return ENTITY::GET_ENTITY_VELOCITY(playerPed); };
	Vector4 GetQuaternion();
	int		GetType() { return PED::GET_PED_TYPE(playerPed); };
	int		GetHealth() { return ENTITY::GET_ENTITY_HEALTH(playerPed); };
	float	GetHeading() { return ENTITY::GET_ENTITY_HEADING(playerPed); };

	void SetPos(float x, float y, float z) { PED::SET_PED_COORDS_KEEP_VEHICLE(playerPed, x, y, z); };
	void SetHeading(float heading) { ENTITY::SET_ENTITY_HEADING(playerPed, heading); };

	void	SendOnFootData();
	void	SendSyncRequest();
};

