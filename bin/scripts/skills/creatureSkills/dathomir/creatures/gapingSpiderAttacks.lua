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
gapingSpiderAttack1 = {
	attackname = "gapingSpiderAttack1",
	animation = "creature_attack_light",
	
	requiredWeaponType = NONE,

	range = 7,

	damageRatio = 1.2,

	speedRatio = 4,

	arearange = 7,
	accuracyBonus = 0,

	healthAttackChance = 50,
	actionAttackChance = 25,
	mindAttackChance = 10,

	dotChance = 50,
	tickStrengthOfHit = 1,

	fireStrength = 0,
	fireType = 0,

	bleedingStrength = 0,
	bleedingType = 0,

	poisonStrength = 100,
	poisonType = HEALTH,

	diseaseStrength = 0,
	diseaseType = 0,
		
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

AddDotPoolAttackTargetSkill(gapingSpiderAttack1)

-----------------------------------------------

gapingSpiderAttack2 = {
	attackname = "gapingSpiderAttack2",
	animation = "creature_attack_light",
	
	requiredWeaponType = NONE,

	range = 7,

	damageRatio = 1.2,

	speedRatio = 4,

	arearange = 7,
	
	accuracyBonus = 0,
		
	knockdownChance = 0,
	postureDownChance = 0,
	postureUpChance = 0,
	dizzyChance = 0,
	blindChance = 0,
	stunChance = 0,
	intimidateChance = 50,
	
	CbtSpamBlock = "attack_block",
	CbtSpamCounter = "attack_counter",
	CbtSpamEvade = "attack_evade",
	CbtSpamHit = "attack_hit",
	CbtSpamMiss = "attack_miss",

	invalidStateMask = 0,
	invalidPostures = "",
	instant = 0
}

AddDotPoolAttackTargetSkill(gapingSpiderAttack2)

-----------------------------------------------

gapingSpiderAttack3 = {
	attackname = "gapingSpiderAttack3",
	animation = "creature_attack_light",
	
	requiredWeaponType = NONE,

	range = 7,

	damageRatio = 1.2,

	speedRatio = 4,

	arearange = 7,
	
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

AddDotPoolAttackTargetSkill(gapingSpiderAttack3)

-----------------------------------------------

gapingSpiderAttack4 = {
	attackname = "gapingSpiderAttack4",
	animation = "creature_attack_light",
	
	requiredWeaponType = NONE,

	range = 7,

	damageRatio = 1.2,

	speedRatio = 4,

	arearange = 7,
	accuracyBonus = 0,

	healthAttackChance = 50,
	actionAttackChance = 25,
	mindAttackChance = 10,

	dotChance = 50,
	tickStrengthOfHit = 1,

	fireStrength = 0,
	fireType = 0,

	bleedingStrength = 0,
	bleedingType = 0,

	poisonStrength = 0,
	poisonType = 0,

	diseaseStrength = 100,
	diseaseType = HEALTH,
		
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

AddDotPoolAttackTargetSkill(gapingSpiderAttack4)

-----------------------------------------------

gapingSpiderAttack5 = {
	attackname = "gapingSpiderAttack5",
	animation = "creature_attack_light",
	
	requiredWeaponType = NONE,

	range = 7,

	damageRatio = 1.2,

	speedRatio = 4,

	arearange = 7,
	
	accuracyBonus = 0,
		
	knockdownChance = 50,
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

AddDotPoolAttackTargetSkill(gapingSpiderAttack5)

-----------------------------------------------

gapingSpiderAttack6 = {
	attackname = "gapingSpiderAttack6",
	animation = "creature_attack_light",
	
	requiredWeaponType = NONE,

	range = 7,

	damageRatio = 1.2,

	speedRatio = 4,

	arearange = 7,
	
	accuracyBonus = 0,
		
	knockdownChance = 50,
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

AddDotPoolAttackTargetSkill(gapingSpiderAttack6)

-----------------------------------------------

gapingSpiderAttack7 = {
        attackname = "gapingSpiderAttack7",
        animation = "creature_attack_light",
        
        requiredWeaponType = NONE,

        range = 7,

        damageRatio = 1.2,

        speedRatio = 4,

        arearange = 7,
        accuracyBonus = 0,

        healthAttackChance = 100,
        actionAttackChance = 0,
        mindAttackChance = 0,

        dotChance = 50,
        tickStrengthOfHit = 1,

        fireStrength = 0,
        fireType = 0,

        bleedingStrength = 0,
		bleedingType = 0,

        poisonStrength = 0,
        poisonType = 0,

        diseaseStrength = 0,
        diseaseType = 0,
                
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

AddDotPoolAttackTargetSkill(gapingSpiderAttack7)

--------------------------------------------------------------------------------------

gapingSpiderAttack8 = {
        attackname = "gapingSpiderAttack8",
        animation = "creature_attack_light",
        
        requiredWeaponType = NONE,

        range = 7,

        damageRatio = 1.2,

        speedRatio = 4,

        arearange = 7,
        accuracyBonus = 0,

        healthAttackChance = 100,
        actionAttackChance = 0,
        mindAttackChance = 0,

        dotChance = 50,
        tickStrengthOfHit = 1,

        fireStrength = 0,
        fireType = 0,

        bleedingStrength = 0,
		bleedingType = 0,

        poisonStrength = 0,
        poisonType = 0,

        diseaseStrength = 0,
        diseaseType = 0,
                
        knockdownChance = 50,
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

AddDotPoolAttackTargetSkill(gapingSpiderAttack8)

--------------------------------------------------------------------------------------

gapingSpiderAttack9 = {
	attackname = "gapingSpiderAttack9",
	animation = "creature_attack_light",
	
	requiredWeaponType = NONE,

	range = 7,

	damageRatio = 1.2,

	speedRatio = 4,

	arearange = 7,
	accuracyBonus = 0,

	healthAttackChance = 50,
	actionAttackChance = 25,
	mindAttackChance = 10,

	dotChance = 50,
	tickStrengthOfHit = 1,

	fireStrength = 0,
	fireType = 0,

	bleedingStrength = 0,
	bleedingType = 0,

	poisonStrength = 100,
	poisonType = HEALTH,

	diseaseStrength = 0,
	diseaseType = 0,
		
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

AddDotPoolAttackTargetSkill(gapingSpiderAttack9)

-----------------------------------------------

poisonSpray = {
	attackname = "poisonSpray",
	animation = "creature_attack_light",
	
	requiredWeaponType = NONE,

	range = 14,

	damageRatio = 1.2,

	speedRatio = 4,

	arearange = 14,
	accuracyBonus = 0,

	healthAttackChance = 50,
	actionAttackChance = 25,
	mindAttackChance = 10,

	dotChance = 50,
	tickStrengthOfHit = 1,

	fireStrength = 0,
	fireType = 0,

	bleedingStrength = 0,
	bleedingType = 0,

	poisonStrength = 100,
	poisonType = HEALTH,

	diseaseStrength = 0,
	diseaseType = 0,
		
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

AddDotPoolAttackTargetSkill(poisonSpray)

-----------------------------------------------

strongPoison = {
	attackname = "strongPoison",
	animation = "creature_attack_light",
	
	requiredWeaponType = NONE,

	range = 24,

	damageRatio = 1.2,

	speedRatio = 4,

	arearange = 1,
	accuracyBonus = 0,

	healthAttackChance = 50,
	actionAttackChance = 25,
	mindAttackChance = 10,

	dotChance = 70,
	tickStrengthOfHit = 2,

	fireStrength = 0,
	fireType = 0,

	bleedingStrength = 0,
	bleedingType = 0,

	poisonStrength = 200,
	poisonType = HEALTH,

	diseaseStrength = 0,
	diseaseType = 0,
		
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

AddDotPoolAttackTargetSkill(strongPoison)

-----------------------------------------------
