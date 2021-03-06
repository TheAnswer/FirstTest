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
areaStrike = {
	attackname = "areaStrike",
	animation = "creature_attack_light",
	
	requiredWeaponType = NONE,

	range = 14,

	damageRatio = 1.2,

	speedRatio = 2,

	arearange = 14,
	accuracyBonus = 0,
		
	knockdownChance = 0,
	postureDownChance = 0,
	postureUpChance = 0,
	dizzyChance = 0,
	blindChance = 0,
	stunChance = 0,
	intimidateChance = 0,
	
	CbtSpamBlock = "attack_block",
	CbtSpamCounter = "attack_counter",
	CbtSpamEvade = "attack_evade",
	CbtSpamHit = "attack_hit",
	CbtSpamMiss = "attack_miss",

	invalidStateMask = 0,
	invalidPostures = "",
	instant = 0
}

AddRandomPoolAttackTargetSkill(areaStrike)

-------------------------------------------------------------------------------

cripplingStrike = {
	attackname = "cripplingStrike",
	animation = "creature_attack_light",
	
	requiredWeaponType = NONE,

	range = 14,

	damageRatio = 1.2,

	speedRatio = 2,

	arearange = 14,
	accuracyBonus = 0,
		
	knockdownChance = 0,
	postureDownChance = 0,
	postureUpChance = 0,
	dizzyChance = 0,
	blindChance = 0,
	stunChance = 0,
	intimidateChance = 0,
	
	CbtSpamBlock = "attack_block",
	CbtSpamCounter = "attack_counter",
	CbtSpamEvade = "attack_evade",
	CbtSpamHit = "attack_hit",
	CbtSpamMiss = "attack_miss",

	invalidStateMask = 0,
	invalidPostures = "",
	instant = 0
}

AddRandomPoolAttackTargetSkill(cripplingStrike)

-------------------------------------------------------------------------------

stunningStrike = {
	attackname = "stunningStrike",
	animation = "creature_attack_light",
	
	requiredWeaponType = NONE,

	range = 14,

	damageRatio = 1.2,

	speedRatio = 2,

	arearange = 14,
	accuracyBonus = 0,
		
	knockdownChance = 0,
	postureDownChance = 0,
	postureUpChance = 0,
	dizzyChance = 0,
	blindChance = 0,
	stunChance = 50,
	intimidateChance = 0,
	
	CbtSpamBlock = "attack_block",
	CbtSpamCounter = "attack_counter",
	CbtSpamEvade = "attack_evade",
	CbtSpamHit = "attack_hit",
	CbtSpamMiss = "attack_miss",

	invalidStateMask = 0,
	invalidPostures = "",
	instant = 0
}

AddRandomPoolAttackTargetSkill(stunningStrike)

-------------------------------------------------------------------------------

forceStrike = {
	attackname = "forceStrike",
	animation = "creature_attack_light",
	
	requiredWeaponType = NONE,

	range = 14,

	damageRatio = 1.2,

	speedRatio = 2,

	arearange = 14,
	accuracyBonus = 0,
		
	knockdownChance = 30,
	postureDownChance = 0,
	postureUpChance = 0,
	dizzyChance = 50,
	blindChance = 0,
	stunChance = 0,
	intimidateChance = 0,
	
	CbtSpamBlock = "attack_block",
	CbtSpamCounter = "attack_counter",
	CbtSpamEvade = "attack_evade",
	CbtSpamHit = "attack_hit",
	CbtSpamMiss = "attack_miss",

	invalidStateMask = 0,
	invalidPostures = "",
	instant = 0
}

AddRandomPoolAttackTargetSkill(forceStrike)

-------------------------------------------------------------------------------

areaCombo = {
	attackname = "areaCombo",
	animation = "creature_attack_light",
	
	requiredWeaponType = NONE,

	range = 14,

	damageRatio = 1.2,

	speedRatio = 2,

	arearange = 14,
	accuracyBonus = 0,
		
	knockdownChance = 60,
	postureDownChance = 0,
	postureUpChance = 0,
	dizzyChance = 60,
	blindChance = 60,
	stunChance = 60,
	intimidateChance = 60,
	
	CbtSpamBlock = "attack_block",
	CbtSpamCounter = "attack_counter",
	CbtSpamEvade = "attack_evade",
	CbtSpamHit = "attack_hit",
	CbtSpamMiss = "attack_miss",

	invalidStateMask = 0,
	invalidPostures = "",
	instant = 0
}

AddRandomPoolAttackTargetSkill(areaCombo)

-------------------------------------------------------------------------------

kraytAttack6 = {
	attackname = "kraytAttack6",
	animation = "creature_attack_light",
	
	requiredWeaponType = NONE,

	range = 14,

	damageRatio = 1.2,

	speedRatio = 2,

	arearange = 14,
	accuracyBonus = 0,
		
	knockdownChance = 0,
	postureDownChance = 0,
	postureUpChance = 0,
	dizzyChance = 0,
	blindChance = 0,
	stunChance = 0,
	intimidateChance = 0,
	
	CbtSpamBlock = "attack_block",
	CbtSpamCounter = "attack_counter",
	CbtSpamEvade = "attack_evade",
	CbtSpamHit = "attack_hit",
	CbtSpamMiss = "attack_miss",

	invalidStateMask = 0,
	invalidPostures = "",
	instant = 0
}

AddRandomPoolAttackTargetSkill(kraytAttack6)

-------------------------------------------------------------------------------

kraytAttack7 = {
	attackname = "kraytAttack7",
	animation = "creature_attack_light",
	
	requiredWeaponType = NONE,

	range = 14,

	damageRatio = 1.2,

	speedRatio = 2,

	arearange = 14,
	accuracyBonus = 0,
		
	knockdownChance = 0,
	postureDownChance = 0,
	postureUpChance = 0,
	dizzyChance = 0,
	blindChance = 0,
	stunChance = 0,
	intimidateChance = 0,
	
	CbtSpamBlock = "attack_block",
	CbtSpamCounter = "attack_counter",
	CbtSpamEvade = "attack_evade",
	CbtSpamHit = "attack_hit",
	CbtSpamMiss = "attack_miss",

	invalidStateMask = 0,
	invalidPostures = "",
	instant = 0
}

AddRandomPoolAttackTargetSkill(kraytAttack7)
