--Copyright (C) 2007 <SWGEmu>
 
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
twilekSlave = Creature:new {
	objectName = "twilekSlave", -- name of the lua Object
	creatureType = "NPC",
	gender = "female",

	speciesName = "slave_twilek_female",
	stfName = "mob/creature_names", 
	objectCRC = 2673849471,
	socialGroup = "slaves",
	level = 600,

	combatFlags = ATTACKABLE_FLAG,

	healthMax = 20,
	healthMin = 10,
	strength = 10,
	constitution = 10,

	actionMax = 20,
	actionMin = 10,
	quickness = 10,
	stamina = 10,

	mindMax = 20,
	mindMin = 10,
	focus = 10,
	willpower = 10,
	
	armor = 0, -- 0 = None; 1 = Light; 2 = Medium; 3 = Heavy

	height = 1,
	kinetic = 0,
	energy = 0,
	electricity = 0,
	stun = 0,
	blast = 0,
	heat = 0,
	cold = 0,
	acid = 0,
	lightSaber = 0,
	
	accuracy = 300,

	
   	healer = 0,
	
	pack = 0,
	herd = 0,
	stalker = 0,
	killer = 0,
	ferocity = 0,
	aggressive = 0,
	invincible = 0, 

	meleeDefense = 1,  
	rangedDefense = 1,

		attackCreatureOnSight = "", -- Enter socialGroups 
	
	weapon = "", -- File path to weapon -> object\xxx\xxx\xx
		weaponName = "", -- Name ex. 'a Vibrolance'
		weaponTemp = "carbine_elite", -- Weapon Template ex. 'lance_vibrolance'
		weaponClass = "CarbineRangedWeapon", -- Weapon Class ex. 'PolearmMeleeWeapon'
		weaponEquipped = 1,
		weaponMinDamage = 55,
		weaponMaxDamage = 65,
		weaponAttackSpeed = 2,
		weaponDamageType = "ENERGY", -- ELECTRICITY, KINETIC, etc
		weaponArmorPiercing = "MEDIUM", -- LIGHT, NONE, MEDIUM, HEAVY

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

	skills = { "dwbMeleeAttack40" },
	respawnTimer = 180,
}

Creatures:addCreature(twilekSlave, 2673849471) --- Add to global creature table
