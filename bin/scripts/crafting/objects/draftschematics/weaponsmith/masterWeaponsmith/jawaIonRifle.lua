--Copyright (C) 2009 <SWGEmu>


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

jawaIonRifle = Object:new {

   objectName = "Jawa Ion Rifle",
   stfName = "rifle_jawa_ion",
   stfFile = "weapon_name",
   objectCRC = 2607432911,
   groupName = "craftWeaponRangedGroupF", -- Group schematic is awarded in (See skills table)

   craftingToolTab = 1, -- (See DraftSchemticImplementation.h)
   complexity = 17, 
   size = 2, 

   xpType = "crafting_weapons_general", 
   xp = 230, 

   assemblySkill = "weapon_assembly", 
   experimentingSkill = "weapon_experimentation", 

   ingredientTemplateNames = "craft_weapon_ingredients_n, craft_weapon_ingredients_n, craft_weapon_ingredients_n, craft_weapon_ingredients_n, craft_weapon_ingredients_n",
   ingredientTitleNames = "stock, receiver_assembly, grip_assembly, powerhandler, barrel",
   ingredientSlotType = "0, 0, 0, 1, 2",
   resourceTypes = "copper_mythra, iron_doonium, metal, object/tangible/component/weapon/shared_blaster_power_handler.iff, object/tangible/component/weapon/shared_blaster_rifle_barrel.iff",
   resourceQuantities = "60, 35, 10, 5, 1",
   combineTypes = "0, 0, 0, 1, 1",
   contribution = "100, 100, 100, 100, 100",

   numberExperimentalProperties = "1, 1, 2, 2, 2, 2, 2, 2, 1, 1, 1, 2, 2, 2, 2",
   experimentalProperties = "XX, XX, CD, OQ, CD, OQ, CD, OQ, CD, OQ, CD, OQ, CD, OQ, XX, XX, XX, CD, OQ, CD, OQ, CD, OQ, CD, OQ",
   experimentalWeights = "1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1",
   experimentalGroupTitles = "null, null, expDamage, expDamage, expDamage, expDamage, expEffeciency, exp_durability, null, null, null, expRange, expEffeciency, expEffeciency, expEffeciency",

   experimentalSubGroupTitles = "null, null, mindamage, maxdamage, attackspeed, woundchance, roundsused, hitpoints, zerorangemod, maxrangemod, midrange, midrangemod, attackhealthcost, attackactioncost, attackmindcost",
   experimentalMin = "0, 0, 56, 105, 8.5, 3, 15, 750, -50, -80, 40, -5, 16, 33, 52",
   experimentalMax = "0, 0, 104, 195, 5.9, 5, 55, 1500, -50, -80, 40, 5, 8, 18, 28",
   experimentalPrecision = "0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0",

   tanoAttributes = "objecttype=131084:objectcrc=1928416827:stfFile=weapon_name:stfName=rifle_jawa_ion:stfDetail=:itemmask=65535:customattributes=damagetype=4;:",

   blueFrogAttributes = "",
   blueFrogEnabled = False,

   customizationOptions = "",
   customizationDefaults = "",
   customizationSkill = "weapon_customization"

}

DraftSchematics:addDraftSchematic(jawaIonRifle, 2607432911)--- Add to global DraftSchematics table
