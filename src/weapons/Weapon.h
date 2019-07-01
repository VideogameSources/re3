#pragma once
#include "Entity.h"

enum eWeaponType
{
	WEAPONTYPE_UNARMED = 0,
	WEAPONTYPE_BASEBALLBAT,
	WEAPONTYPE_COLT45,
	WEAPONTYPE_UZI,
	WEAPONTYPE_SHOTGUN,
	WEAPONTYPE_AK47,
	WEAPONTYPE_M16,
	WEAPONTYPE_SNIPERRIFLE,
	WEAPONTYPE_ROCKETLAUNCHER,
	WEAPONTYPE_FLAMETHROWER,
	WEAPONTYPE_MOLOTOV,
	WEAPONTYPE_GRENADE,
	WEAPONTYPE_DETONATOR,
	NUM_PED_WEAPONTYPES = 13,
	WEAPONTYPE_HELICANNON = 13,
	NUM_WEAPONTYPES,
	NO_STORED_WEAPON = 22
};

enum eWeaponFire {
	WEAPON_FIRE_MELEE,
	WEAPON_FIRE_INSTANT_HIT,
	WEAPON_FIRE_PROJECTILE,
	WEAPON_FIRE_AREA_EFFECT,
	WEAPON_FIRE_USE
};

// Taken from MTA SA, seems it's unchanged
enum eWeaponState
{
	WEAPONSTATE_READY,
	WEAPONSTATE_FIRING,
	WEAPONSTATE_RELOADING,
	WEAPONSTATE_OUT_OF_AMMO,
	WEAPONSTATE_MELEE_MADECONTACT
};

class CWeapon
{
public:
	eWeaponType m_eWeaponType;
	eWeaponState m_eWeaponState;
	uint32 m_nAmmoInClip;
	uint32 m_nAmmoTotal;
	int32 m_nTimer;
	bool m_bAddRotOffset;

	CWeapon() {
		m_bAddRotOffset = false;
	}

	void Initialise(eWeaponType type, int ammo);
	void Reload(void);
	bool Fire(CEntity*, CVector*);
	void AddGunshell(CEntity*, CVector const&, CVector2D const&, float);
};
static_assert(sizeof(CWeapon) == 0x18, "CWeapon: error");
