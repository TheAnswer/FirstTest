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

advancedVibroBladeUnit = Object:new {

   objectName = "Advanced Vibro Blade Unit",
   stfName = "blade_vibro_unit_advanced",
   stfFile = "craft_weapon_ingredients_n",
   objectCRC = 2591525916,
   groupName = "craftWeaponMeleeGroupD", -- Group schematic is awarded in (See skills table)

   craftingToolTab = 1, -- (See DraftSchemticImplementation.h)
   complexity = 30, 
   size = 3, 

   xpType = "crafting_weapons_general", 
   xp = 70, 

   assemblySkill = "weapon_assembly", 
   experimentingSkill = "weapon_experimentation", 

   ingredientTemplateNames = "craft_weapon_ingredients_n, craft_weapon_ingredients_n, craft_weapon_ingredients_n, craft_weapon_ingredients_n",
   ingredientTitleNames = "module_housing, ultrasonic_vibration_generator, conductive_circuits, weapon_enhancement",
   ingredientSlotType = "0, 0, 0, 4",
   resourceTypes = "copper_desh, petrochem_fuel_solid_type3, copper_platinite, object/tangible/component/weapon/shared_base_vibro_unit_enhancement.iff",
   resourceQuantities = "25, 15, 13, 1",
   combineTypes = "0, 0, 0, 1",
   contribution = "100, 100, 100, 100",

   numberExperimentalProperties = "1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1",
   experimentalProperties = "XX, XX, UT, UT, UT, UT, UT, UT, UT, UT, UT, UT, UT",
   experimentalWeights = "1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1",
   experimentalGroupTitles = "null, null, expDamage, expDamage, expDamage, expDamage, exp_durability, expRange, expRange, expRange, expEffeciency, expEffeciency, expEffeciency",

   experimentalSubGroupTitles = "null, null, mindamage, maxdamage, attackspeed, woundchance, hitpoints, zerorangemod, maxrangemod, midrangemod, attackhealthcost, attackactioncost, attackmindcost",
   experimentalMin = "0, 0, 1, 1, 0, 0, 10, 0, 0, 0, 10, 10, 10",
   experimentalMax = "0, 0, 50, 75, -0.7, 25, 100, 30, 30, 30, -3, -3, -3",
   experimentalPrecision = "0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0",

   tanoAttributes = "objecttype=262153:objectcrc=1094994187:stfFile=craft_weapon_ingredients_n:stfName=blade_vibro_unit_advanced:stfDetail=:itemmask=65535::",

   blueFrogAttributes = "",
   blueFrogEnabled = False,

   customizationOptions = "",
   customizationDefaults = "",
   customizationSkill = "weapon_customization"

}

DraftSchematics:addDraftSchematic(advancedVibroBladeUnit, 2591525916)--- Add to global DraftSchematics table
