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

microSensorSuite = Object:new {

   objectName = "Micro Sensor Suite",
   stfName = "micro_sensor_suite",
   stfFile = "craft_item_ingredients_n",
   objectCRC = 622519855,
   groupName = "craftArtisanMasterGroupA", -- Group schematic is awarded in (See skills table)

   craftingToolTab = 524288, -- (See DraftSchemticImplementation.h)
   complexity = 17, 
   size = 5, 

   xpType = "crafting_general", 
   xp = 80, 

   assemblySkill = "general_assembly", 
   experimentingSkill = "general_experimentation", 

   ingredientTemplateNames = "craft_item_ingredients_n, craft_item_ingredients_n, craft_item_ingredients_n, craft_item_ingredients_n, craft_item_ingredients_n, craft_item_ingredients_n, craft_item_ingredients_n, craft_item_ingredients_n",
   ingredientTitleNames = "assembly_enclosure, assembly_frame, thermal_shielding, thermal_and_contaminant_shield, micro_transciever_net, base_pre_processing_unit, primary_array_processing_and_control_unit, sensor_array_wiring_harness",
   ingredientSlotType = "0, 0, 0, 0, 0, 2, 2, 2",
   resourceTypes = "steel, metal, ore, gas_inert, metal, object/tangible/component/item/shared_electronics_gp_module.iff, object/tangible/component/item/shared_electronic_control_unit.iff, object/tangible/component/item/shared_electronic_energy_distributor.iff",
   resourceQuantities = "10, 6, 3, 15, 3, 1, 1, 1",
   combineTypes = "0, 0, 0, 0, 0, 1, 1, 1",
   contribution = "100, 100, 100, 100, 100, 100, 100, 100",

   numberExperimentalProperties = "1, 1, 1, 2",
   experimentalProperties = "XX, XX, UT, CD, OQ",
   experimentalWeights = "1, 1, 1, 1, 2",
   experimentalGroupTitles = "null, null, exp_durability, exp_effectiveness",

   experimentalSubGroupTitles = "null, null, hitpoints, usemodifier",
   experimentalMin = "0, 0, 100, -5",
   experimentalMax = "0, 0, 150, 5",
   experimentalPrecision = "0, 0, 0, 0",

   tanoAttributes = "objecttype=262150:objectcrc=3198540321:stfFile=craft_item_ingredients_n:stfName=micro_sensor_suite:stfDetail=:itemmask=65535::",

   blueFrogAttributes = "",
   blueFrogEnabled = False,

   customizationOptions = "",
   customizationDefaults = "",
   customizationSkill = "clothing_customization"

}

DraftSchematics:addDraftSchematic(microSensorSuite, 622519855)--- Add to global DraftSchematics table
