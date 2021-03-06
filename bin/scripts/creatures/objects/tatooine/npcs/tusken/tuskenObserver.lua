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

tuskenObserver = Creature:new {
	objectName = "tuskenObserver",  -- Lua Object Name
	creatureType = "NPC",
	faction = "tusken_raider", 
	factionPoints = 20,
	gender = "",

	speciesName = "tusken_observer",
	stfName = "mob/creature_names", 
	objectCRC = 3780705985, 
	socialGroup = "tusken_raider",
	 

	level = 227,
	
	combatFlags = ATTACKABLE_FLAG + ENEMY_FLAG + AGGRESSIVE_FLAG,

	healthMax = 250000,
	healthMin = 210000,
	strength = 30000,
	constitution = 30000,

	actionMax = 250000,
	actionMin = 210000,
	quickness = 30000,
	stamina = 30000,

	mindMax = 250000,
	mindMin = 210000,
	focus = 30000,
	willpower = 30000,

	height = 1, -- Size of creature
	armor = 3, -- 0 = None; 1 = Light; 2 = Medium; 3 = Heavy
	kinetic = 85,
	energy = 85,
	electricity = 30,
	stun = 80,
	blast = 35,
	heat = 100,
	cold = 10,
	acid = 45,
	lightsaber = 0,

	accuracy = 350,

	healer = 0,

	pack = 1,
	herd = 0,
	stalker = 1,
	killer = 1,
	ferocity = 0,
	aggressive = 1,
	invincible = 0, 

	  
	
	meleeDefense = 1,    
	rangedDefense = 1,

	attackCreatureOnSight = "", -- Enter socialGroups 

	weapon = "object/weapon/melee/baton/shared_baton_gaderiffi.iff", -- File path to weapon -> object\xxx\xxx\xx
	weaponName = "a Gaderiffi", -- Name ex. 'a Vibrolance'
	weaponTemp = "baton_gaderiffi", -- Weapon Template ex. 'lance_vibrolance'
	weaponClass = "OneHandedMeleeWeapon", -- Weapon Class ex. 'PolearmMeleeWeapon'
	weaponEquipped = 1,
	weaponMinDamage = 1270,
	weaponMaxDamage = 2250,
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

	lootGroup = "0,1,4,11,15,24,25,33,39,40,99", -- Group it belongs to for loot

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

	 skills = { "tuskenAttack40", "tuskenAttack41", "tuskenAttack42", "tuskenAttack43",  "tuskenAttack44", "tuskenAttack45", "tuskenAttack46", "tuskenAttack47", "tuskenAttack49", "tuskenAttack50",  "tuskenAttack53" },
	respawnTimer = 7200,

	behaviorScript = "", -- Link to the behavior script for this object
}

Creatures:addCreature(tuskenObserver, 3780705985) --  Add to Global Table
