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

scatterPistol = Object:new {

   objectName = "Scatter Pistol",
   stfName = "pistol_scatter",
   stfFile = "weapon_name",
   objectCRC = 636138859,
   groupName = "craftWeaponRangedGroupD", -- Group schematic is awarded in (See skills table)

   craftingToolTab = 1, -- (See DraftSchemticImplementation.h)
   complexity = 22, 
   size = 1, 

   xpType = "crafting_weapons_general", 
   xp = 134, 

   assemblySkill = "weapon_assembly", 
   experimentingSkill = "weapon_experimentation", 

   ingredientTemplateNames = "craft_weapon_ingredients_n, craft_weapon_ingredients_n, craft_weapon_ingredients_n, craft_weapon_ingredients_n, craft_weapon_ingredients_n, craft_weapon_ingredients_n",
   ingredientTitleNames = "frame_assembly, receiver_assembly, grip_assembly, powerhandler, barrel, scope",
   ingredientSlotType = "0, 0, 0, 2, 2, 4",
   resourceTypes = "iron_doonium, metal_ferrous, metal, object/tangible/component/weapon/shared_blaster_power_handler.iff, object/tangible/component/weapon/shared_projectile_pistol_barrel.iff, object/tangible/component/weapon/shared_scope_weapon.iff",
   resourceQuantities = "33, 22, 10, 1, 1, 1",
   combineTypes = "0, 0, 0, 1, 1, 1",
   contribution = "100, 100, 100, 100, 100, 100",

   numberExperimentalProperties = "1, 1, 2, 2, 2, 2, 2, 2, 1, 1, 1, 2, 2, 2, 2",
   experimentalProperties = "XX, XX, CD, OQ, CD, OQ, CD, OQ, CD, OQ, CD, OQ, CD, OQ, XX, XX, XX, CD, OQ, CD, OQ, CD, OQ, CD, OQ",
   experimentalWeights = "1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1",
   experimentalGroupTitles = "null, null, expDamage, expDamage, expDamage, expDamage, expEffeciency, exp_durability, null, null, null, expRange, expEffeciency, expEffeciency, expEffeciency",

   experimentalSubGroupTitles = "null, null, mindamage, maxdamage, attackspeed, woundchance, roundsused, hitpoints, zerorangemod, maxrangemod, midrange, midrangemod, attackhealthcost, attackactioncost, attackmindcost",
   experimentalMin = "0, 0, 49, 56, 4.8, 15, 30, 750, -45, -95, 7, 18, 20, 58, 20",
   experimentalMax = "0, 0, 91, 104, 3.3, 27, 30, 1500, -15, -65, 7, 35, 10, 31, 10",
   experimentalPrecision = "0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0",

   tanoAttributes = "objecttype=131082:objectcrc=3345683635:stfFile=weapon_name:stfName=pistol_scatter:stfDetail=:itemmask=65535:customattributes=damagetype=2;:",

   blueFrogAttributes = "",
   blueFrogEnabled = False,

   customizationOptions = "",
   customizationDefaults = "",
   customizationSkill = "weapon_customization"

}

DraftSchematics:addDraftSchematic(scatterPistol, 636138859)--- Add to global DraftSchematics table
