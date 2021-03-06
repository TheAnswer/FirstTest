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

t21Rifle = Object:new {

   objectName = "T21 Rifle",
   stfName = "rifle_t21",
   stfFile = "weapon_name",
   objectCRC = 546888390,
   groupName = "craftWeaponRangedGroupF", -- Group schematic is awarded in (See skills table)

   craftingToolTab = 1, -- (See DraftSchemticImplementation.h)
   complexity = 30, 
   size = 4, 

   xpType = "crafting_weapons_general", 
   xp = 650, 

   assemblySkill = "weapon_assembly", 
   experimentingSkill = "weapon_experimentation", 

   ingredientTemplateNames = "craft_weapon_ingredients_n, craft_weapon_ingredients_n, craft_weapon_ingredients_n, craft_weapon_ingredients_n, craft_weapon_ingredients_n, craft_weapon_ingredients_n, craft_weapon_ingredients_n, craft_weapon_ingredients_n",
   ingredientTitleNames = "frame_assembly, receiver_assembly, grip_assembly, enhanced_cooling_mechanism, powerhandler, thermal_control_unit, barrel, stock",
   ingredientSlotType = "0, 0, 0, 0, 1, 0, 2, 4",
   resourceTypes = "steel_ditanium, iron_polonium, metal, crystalline_gallinorian, object/tangible/component/weapon/shared_blaster_power_handler.iff, ore_carbonate_alantium, object/tangible/component/weapon/shared_blaster_rifle_barrel.iff, object/tangible/component/weapon/shared_stock.iff",
   resourceQuantities = "150, 85, 20, 15, 10, 30, 1, 1",
   combineTypes = "0, 0, 0, 0, 1, 0, 1, 1",
   contribution = "100, 100, 100, 100, 100, 100, 100, 100",

   numberExperimentalProperties = "1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 1, 1, 2, 2, 2",
   experimentalProperties = "XX, XX, CD, OQ, CD, OQ, CD, OQ, CD, OQ, CD, OQ, CD, OQ, XX, CD, OQ, XX, XX, CD, OQ, CD, OQ, CD, OQ",
   experimentalWeights = "1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1",
   experimentalGroupTitles = "null, null, expDamage, expDamage, expDamage, expDamage, expEffeciency, exp_durability, null, expRange, null, null, expEffeciency, expEffeciency, expEffeciency",

   experimentalSubGroupTitles = "null, null, mindamage, maxdamage, attackspeed, woundchance, roundsused, hitpoints, zerorangemod, midrangemod, midrange, maxrangemod, attackhealthcost, attackactioncost, attackmindcost",
   experimentalMin = "0, 0, 80, 200, 10.5, 15, 30, 750, -70, -10, 50, 10, 46, 39, 83",
   experimentalMax = "0, 0, 115, 375, 6.5, 29, 65, 1500, -70, 15, 50, 10, 25, 21, 45",
   experimentalPrecision = "0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0",

   tanoAttributes = "objecttype=131084:objectcrc=1951509016:stfFile=weapon_name:stfName=rifle_t21:stfDetail=:itemmask=65535:customattributes=damagetype=2;:",

   blueFrogAttributes = "",
   blueFrogEnabled = False,

   customizationOptions = "",
   customizationDefaults = "",
   customizationSkill = "weapon_customization"

}

DraftSchematics:addDraftSchematic(t21Rifle, 546888390)--- Add to global DraftSchematics table
