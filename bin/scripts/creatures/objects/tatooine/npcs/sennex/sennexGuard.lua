--Copyright (C) 2008 <SWGEmu>


--This File is part of Core3.

--This program is free software; you can redistribute 
--it and/or modify it under the terms of the GNU Lesser 
--General Public License as published by the Free Software
--Foundation; either version 2 of the License, 
--or (at your option) any later version.

--This program is distributed in the hope that it will be useful, 
--but WITHOUT ANY WARRANTY; without even the implied warranty of 
--MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
--See the GNU Lesser General Public License for
--more details.

--You should have received a copy of the GNU Lesser General 
--Public License along with this program; if not, write to
--the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

--Linking Engine3 statically or dynamically with other modules 
--is making a combined work based on Engine3. 
--Thus, the terms and conditions of the GNU Lesser General Public License 
--cover the whole combination.

--In addition, as a special exception, the copyright holders of Engine3 
--give you permission to combine Engine3 program with free software 
--programs or libraries that are released under the GNU LGPL and with 
--code included in the standard release of Core3 under the GNU LGPL 
--license (or modified versions of such code, with unchanged license). 
--You may copy and distribute such a system following the terms of the 
--GNU LGPL for Engine3 and the licenses of the other code concerned, 
--provided that you include the source code of that other code when 
--and as the GNU LGPL requires distribution of source code.

--Note that people who make modified versions of Engine3 are not obligated 
--to grant this special exception for their modified versions; 
--it is their choice whether to do so. The GNU Lesser General Public License 
--gives permission to release a modified version without this exception; 
--this exception also makes it possible to release a modified version 
--which carries forward this exception.
sennexGuard = Creature:new {
	objectName = "sennexGuard",  -- Lua Object Name
	creatureType = "NPC",
	gender = "",

	speciesName = "sennex_guard",
	stfName = "mob/creature_names", 
	objectCRC = 2453845306, 
	socialGroup = "Sennex",
	level = 62,

	combatFlags = ATTACKABLE_FLAG + ENEMY_FLAG + AGGRESSIVE_FLAG,

	healthMax = 10700,
	healthMin = 8700,
	strength = 500,
	constitution = 500,

	actionMax = 10700,
	actionMin = 8700,
	quickness = 500,
	stamina = 500,

	mindMax = 10700,
	mindMin = 8700,
	focus = 500,
	willpower = 500,

	height = 1, -- Size of creature
	armor = 1, -- 0 = None; 1 = Light; 2 = Medium; 3 = Heavy
	kinetic = 0,
	energy = 0,
	electricity = 30,
	stun = -1,
	blast = 0,
	heat = 30,
	cold = -1,
	acid = 0,
	lightsaber = 0,

	accuracy = 300,

	healer = 0,

	pack = 1,
	herd = 0,
	stalker = 0,
	killer = 1,
	ferocity = 0,
	aggressive = 1,
	invincible = 0, 

	meleeDefense = 1,  
	rangedDefense = 1,

	attackCreatureOnSight = "", -- Enter socialGroups 

	weapon = "object/weapon/melee/polearm/shared_polearm_vibro_axe.iff", -- File path to weapon -> object\xxx\xxx\xx
	weaponName = "a Long Vibro Axe", -- Name ex. 'a Vibrolance'
	weaponTemp = "lance_vibro_axe", -- Weapon Template ex. 'lance_vibrolance'
	weaponClass = "PolearmMeleeWeapon", -- Weapon Class ex. 'PolearmMeleeWeapon'
	weaponEquipped = 1,
	weaponMinDamage = 310,
	weaponMaxDamage = 330,
	weaponAttackSpeed = 2,
	weaponDamageType = "ELECTRICITY", -- ELECTRICITY, KINETIC, etc
	weaponArmorPiercing = "NONE", -- LIGHT, NONE, MEDIUM, HEAVY

	alternateWeapon = "object/weapon/melee/axe/shared_axe_vibroaxe.iff", -- File path to weapon -> object\xxx\xxx\xx
	alternateWeaponName = "a Vibro Axe", -- Name ex. 'a Vibrolance'
	alternateWeaponTemp = "axe_vibro", -- Weapon Template ex. 'lance_vibrolance'
	alternateWeaponClass = "TwoHandedMeleeWeapon", -- Weapon Class ex. 'PolearmMeleeWeapon'
	alternateWeaponEquipped = 1,
	alternateWeaponMinDamage = 310,
	alternateWeaponMaxDamage = 330,
	alternateWeaponAttackSpeed = 2,
	alternateWeaponDamageType = "KINETIC", -- ELECTRICITY, KINETIC, etc
	alternateWeaponArmorPiercing = "NONE", -- LIGHT, NONE, MEDIUM

	internalNPCDamageModifier = 0.3, -- Damage Modifier to other NPC's

	lootGroup = "0,11,15,19,33,39", -- Group it belongs to for loot

	tame = 0,
	datapadItemCRC = 0,
	mountCRC = 0,
	mountSpeed = 0,
	mountAcceleration = 0,

	milk = 0,

	boneType = "",
	boneMax = 0,

	hideType = "",
	hideMax = 0,

	meatType = "",
	meatMax = 0,

	skills = { "sennexattack1", "sennexattack2", "sennexattack3", "sennexattack4", "sennexattack5" },
	respawnTimer = 300,

	behaviorScript = "", -- Link to the behavior script for this object
}

Creatures:addCreature(sennexGuard, 2453845306) --  Add to Global Table
