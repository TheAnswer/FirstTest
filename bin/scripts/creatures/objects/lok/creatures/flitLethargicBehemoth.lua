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
flitLethargicBehemoth = Creature:new {
	objectName = "flitLethargicBehemoth",  -- Lua Object Name
	creatureType = "ANIMAL",
	gender = "",

	speciesName = "flit_lethargic_behemoth",
	stfName = "mob/creature_names",
	--objectCRC = 1138484659,
	objectCRC = 4002066866,
	socialGroup = "Flit",
	level = 23,

	combatFlags = ATTACKABLE_FLAG + ENEMY_FLAG + AGGRESSIVE_FLAG,

	healthMax = 7700,
	healthMin = 6300,
	strength = 0,
	constitution = 0,

	actionMax = 7700,
	actionMin = 6300,
	quickness = 0,
	stamina = 0,

	mindMax = 7700,
	mindMin = 6300,
	focus = 0,
	willpower = 0,

	height = 1, -- Size of creature
	armor = 0, -- 0 = None; 1 = Light; 2 = Medium; 3 = Heavy
	kinetic = 10,
	energy = 10,
	electricity = -1,
	stun = 0,
	blast = -1,
	heat = -1,
	cold = 0,
	acid = 0,
	lightsaber = 0,

	accuracy = 0,

	healer = 0,

	pack = 1,
	herd = 0,
	stalker = 0,
	killer = 0,
	ferocity = 0,
	aggressive = 1,
	invincible = 0, 

	meleeDefense = 1,  
	rangedDefense = 1,

	attackCreatureOnSight = "", -- Enter socialGroups 

	weapon = "object/weapon/creature/shared_creature_default_weapon.iff", -- File path to weapon -> object\xxx\xxx\xx
	weaponName = "Creature Defualt", -- Name ex. 'a Vibrolance'
	weaponTemp = "creature_default_weapon", -- Weapon Template ex. 'lance_vibrolance'
	weaponClass = "UnarmedMeleeWeapon", -- Weapon Class ex. 'PolearmMeleeWeapon'
	weaponEquipped = 0,
	weaponMinDamage = 250,
	weaponMaxDamage = 260,
	weaponAttackSpeed = 2,
	weaponDamageType = "KINETIC", -- ELECTRICITY, KINETIC, etc
	weaponArmorPiercing = "NONE", -- LIGHT, NONE, MEDIUM, HEAVY

	alternateWeapon = "", -- File path to weapon -> object\xxx\xxx\xx
	alternateWeaponName = "", -- Name ex. 'a Vibrolance'
	alternateWeaponTemp = "", -- Weapon Template ex. 'lance_vibrolance'
	alternateWeaponClass = "", -- Weapon Class ex. 'PolearmMeleeWeapon'
	alternateWeaponEquipped = 0,
	alternateWeaponMinDamage = 0,
	alternateWeaponMaxDamage = 0,
	alternateWeaponAttackSpeed = 0,
	alternateWeaponDamageType = "", -- ELECTRICITY, KINETIC, etc
	alternateWeaponArmorPiercing = "", -- LIGHT, NONE, MEDIUM, HEAVY

	internalNPCDamageModifier = 0.3, -- Damage Modifier to other NPC's

	lootGroup = "0", -- Group it belongs to for loot

	tame = 0.05,  -- Likely hood to be tamed
	datapadItemCRC = 2923608669,
	mountCRC = 0,
	mountSpeed = 0,
	mountAcceleration = 0,

	milk = 0,

	boneType = "bone_avian_lok",
	boneMax = 13,

	hideType = "",
	hideMax = 20,

	meatType = "meat_avian_lok",
	meatMax = 11,

	--skills = { " Stun attack", " Knockdown attack", "" }
	skills = { "flitAttack1", "flitAttack3" },
	respawnTimer = 60,

	behaviorScript = "", -- Link to the behavior script for this object
}

Creatures:addCreature(flitLethargicBehemoth, 4002066866) --  Add to Global Table
