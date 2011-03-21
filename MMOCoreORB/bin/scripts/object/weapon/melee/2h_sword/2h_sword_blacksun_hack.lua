--Copyright (C) 2010 <SWGEmu>


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


object_weapon_melee_2h_sword_2h_sword_blacksun_hack = object_weapon_melee_2h_sword_shared_2h_sword_blacksun_hack:new {

	-- ALL, ALLSEXES, ALLFACTIONS, HUMANOIDS, HUMANOID_FOOTWEAR, HUMANOID_MALES, HUMANOID_FEMALES, HUMANOID_IMPERIALS, HUMANOID_REBELS, WOOKIES, ITHORIANS, TWILEKS
	playerUseMask = ALL,
	
	-- RANGEDATTACK, MELEEATTACK, FORCEATTACK, TRAPATTACK, GRENADEATTACK, HEAVYACIDBEAMATTACK,
	-- HEAVYLIGHTNINGBEAMATTACK, HEAVYPARTICLEBEAMATTACK, HEAVYROCKETLAUNCHERATTACK, HEAVYLAUNCHERATTACK
	attackType = MELEEATTACK,
	
	-- ENERGY, KINETIC, ELECTRICITY, STUN, BLAST, HEAT, COLD, ACID, FORCE, LIGHTSABER
	damageType = KINETIC,
	
	-- NONE, LIGHT, MEDIUM, HEAVY
	armorPiercing = MEDIUM,
	
	-- combat_rangedspecialize_bactarifle, combat_rangedspecialize_rifle, combat_rangedspecialize_pistol, combat_rangedspecialize_heavy, combat_rangedspecialize_carbine
	-- combat_meleespecialize_unarmed, combat_meleespecialize_twohand, combat_meleespecialize_polearm, combat_meleespecialize_onehand, combat_general,
	-- combat_meleespecialize_twohandlightsaber, combat_meleespecialize_polearmlightsaber, combat_meleespecialize_onehandlightsaber
	xpType = "combat_meleespecialize_twohand",
	       
	-- See http://www.ocdsoft.com/files/certifications.xls
	certificationsRequired = { "cert_sword_techniques2" },
	-- See http://www.ocdsoft.com/files/accuracy.xls
	creatureAccuracyModifiers = { "twohandedmelee_accuracy" },
	
	-- See http://www.ocdsoft.com/files/defense.xls
	defenderDefenseModifiers = { "melee_defense" },
	
	-- Leave as "dodge" for now, may have additions later
	defenderSecondaryDefenseModifiers = { "dodge" },
	
	-- See http://www.ocdsoft.com/files/speed.xls
	speedModifiers = { "twohandmelee_speed" },
	
	-- Leave blank for now
	damageModifiers = { },
	       
	
	-- The values below are the default values.  To be used for blue frog objects primarily
	healthAttackCost = 49,
	actionAttackCost = 74,
	mindAttackCost = 42,
	forceCost = 0,
	
	pointBlankAccuracy = 0,
	pointBlankRange = -8,
	
	idealRange = 11,
	idealAccuracy = 6,
	
	maxRange = -8,
	maxRangeAccuracy = 5,

	minDamage = 171,
        maxDamage = 300,
	
	attackSpeed = 2.7

}

ObjectTemplates:addTemplate(object_weapon_melee_2h_sword_2h_sword_blacksun_hack, "object/weapon/melee/2h_sword/2h_sword_blacksun_hack.iff")