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
RandPoolAtt = { 
	attackname = "panicshot",
	animation = "fire_1_special_single_light",

	requiredWeaponType = PISTOL,
	
	range = 0,
	damageRatio = 2.0,
	speedRatio = 2.6,
	areaRange = 0,
	coneAngle = 45,
	accuracyBonus = 0,

	healthCostMultiplier = 1,
	actionCostMultiplier = 1,
	mindCostMultiplier = 1,
	forceCostMultiplier = 0,

	knockdownChance = 0,
	postureDownChance = 0,
	postureUpChance = 0,
	dizzyChance = 0,
	blindChance = 0,
	stunChance = 0,
	intimidateChance = 0,
	
	CbtSpamBlock = "shockshot_block",
	CbtSpamCounter = "shockshot_counter",
	CbtSpamEvade = "shockshot_evade",
	CbtSpamHit = "shockshot_hit",
	CbtSpamMiss = "shockshot_miss",

        invalidStateMask = 3894805552, --alert, berzerk, tumbling, frozen, swimming, glowingJedi, ridingMount, pilotingShip, shipOperations, shipGunner, 
        invalidPostures = "3,5,6,7,8,9,10,11,12,13,14,4,",
	instant = 0
}

AddRandomPoolAttackTargetSkill(RandPoolAtt)

-----------------------------------------------------------------------

RandPoolAtt = { 
	attackname = "lowblow",
	animation = "fire_5_single_light",

	requiredWeaponType = PISTOL,
	
	range = 0,
	damageRatio = 2.0,
	speedRatio = 2.4,
	areaRange = 0,
	accuracyBonus = 5,

	healthCostMultiplier = 1,
	actionCostMultiplier = 1,
	mindCostMultiplier = 1,
	forceCostMultiplier = 0,

	knockdownChance = 30,
	postureDownChance = 0,
	postureUpChance = 0,
	dizzyChance = 0,
	blindChance = 0,
	stunChance = 0,
	intimidateChance = 0,
	
	CbtSpamBlock = "debilitatingshot_block",
	CbtSpamCounter = "debilitatingshot_counter",
	CbtSpamEvade = "debilitatingshot_evade",
	CbtSpamHit = "debilitatingshot_hit",
	CbtSpamMiss = "debilitatingshot_miss",

        invalidStateMask = 3894805552, --alert, berzerk, tumbling, frozen, swimming, glowingJedi, ridingMount, pilotingShip, shipOperations, shipGunner, 
        invalidPostures = "3,5,6,7,8,9,10,11,12,13,14,4,",
	instant = 0
}

AddRandomPoolAttackTargetSkill(RandPoolAtt)


-----------------------------------------------------------------------

RandPoolAtt = { 
	attackname = "lastditch",
	animation = "fire_1_special_single_light",

	requiredWeaponType = PISTOL,
	
	range = 0,
	damageRatio = 6.0,
	speedRatio = 4.0,
	areaRange = 0,
	accuracyBonus = 10,

	healthCostMultiplier = 1,
	actionCostMultiplier = 1,
	mindCostMultiplier = 1,
	forceCostMultiplier = 0,

	knockdownChance = 0,
	postureDownChance = 0,
	postureUpChance = 0,
	dizzyChance = 0,
	blindChance = 0,
	stunChance = 40,
	intimidateChance = 0,
	
	CbtSpamBlock = "lastditch_block",
	CbtSpamCounter = "lastditch_counter",
	CbtSpamEvade = "lastditch_evade",
	CbtSpamHit = "lastditch_hit",
	CbtSpamMiss = "lastditch_miss",

        invalidStateMask = 3894805552, --alert, berzerk, tumbling, frozen, swimming, glowingJedi, ridingMount, pilotingShip, shipOperations, shipGunner, 
        invalidPostures = "3,5,6,7,8,9,10,11,12,13,14,4,",
	instant = 0
}

AddRandomPoolAttackTargetSkill(RandPoolAtt)



