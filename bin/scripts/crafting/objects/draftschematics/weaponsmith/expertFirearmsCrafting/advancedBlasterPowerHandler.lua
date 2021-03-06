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

advancedBlasterPowerHandler = Object:new {

   objectName = "Advanced Blaster Power Handler",
   stfName = "blaster_power_handler_advanced",
   stfFile = "craft_weapon_ingredients_n",
   objectCRC = 669027229,
   groupName = "craftWeaponRangedGroupD", -- Group schematic is awarded in (See skills table)

   craftingToolTab = 1, -- (See DraftSchemticImplementation.h)
   complexity = 20, 
   size = 3, 

   xpType = "crafting_weapons_general", 
   xp = 50, 

   assemblySkill = "weapon_assembly", 
   experimentingSkill = "weapon_experimentation", 

   ingredientTemplateNames = "craft_weapon_ingredients_n, craft_weapon_ingredients_n, craft_weapon_ingredients_n, craft_weapon_ingredients_n, craft_weapon_ingredients_n, craft_weapon_ingredients_n",
   ingredientTitleNames = "module_assembly, xciter_circuitry, circuitry_substrate, gas_containment_unit, reactant_source, weapon_enhancement",
   ingredientSlotType = "0, 0, 0, 0, 0, 4",
   resourceTypes = "petrochem_inert_polymer, copper_diatium, ore_carbonate_ostrine, aluminum_phrik, gas_reactive_irolunn, object/tangible/component/weapon/shared_base_blaster_power_handler_enhancement.iff",
   resourceQuantities = "10, 5, 5, 8, 16, 1",
   combineTypes = "0, 0, 0, 0, 0, 1",
   contribution = "100, 100, 100, 100, 100, 100",

   numberExperimentalProperties = "1, 1, 2, 2, 2, 2",
   experimentalProperties = "XX, XX, CD, OQ, CD, OQ, CD, OQ, CD, OQ",
   experimentalWeights = "1, 1, 2, 1, 2, 1, 2, 1, 2, 1",
   experimentalGroupTitles = "null, null, expDamage, expDamage, expDamage, exp_durability",

   experimentalSubGroupTitles = "null, null, mindamage, maxdamage, attackspeed, hitpoints",
   experimentalMin = "0, 0, 1, 1, 0, 10",
   experimentalMax = "0, 0, 25, 50, -0.5, 100",
   experimentalPrecision = "0, 0, 0, 0, 1, 0",

   tanoAttributes = "objecttype=262155:objectcrc=1426378303:stfFile=craft_weapon_ingredients_n:stfName=blaster_power_handler_advanced:stfDetail=:itemmask=65535::",

   blueFrogAttributes = "",
   blueFrogEnabled = False,

   customizationOptions = "",
   customizationDefaults = "",
   customizationSkill = "weapon_customization"

}

DraftSchematics:addDraftSchematic(advancedBlasterPowerHandler, 669027229)--- Add to global DraftSchematics table
