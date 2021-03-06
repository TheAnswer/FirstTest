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

deedForHeavyMineralMiningInstallation = Object:new {

   objectName = "",
   stfName = "ore_heavy_harvester_deed_name",
   stfFile = "deed",
   objectCRC = 1543208719,
   groupName = "craftInstallationGroupD", -- Group schematic is awarded in (See skills table)

   craftingToolTab = 1024, -- (See DraftSchemticImplementation.h)
   complexity = 35, 
   size = 12, 

   xpType = "crafting_structure_general", 
   xp = 3900, 

   assemblySkill = "structure_assembly", 
   experimentingSkill = "structure_experimentation", 

   ingredientTemplateNames = "craft_structure_ingredients_n, craft_structure_ingredients_n, craft_structure_ingredients_n, craft_structure_ingredients_n, craft_structure_ingredients_n, craft_structure_ingredients_n, craft_structure_ingredients_n, craft_structure_ingredients_n, craft_structure_ingredients_n, craft_structure_ingredients_n",
   ingredientTitleNames = "load_bearing_frame, body_shell_structure, body_casing, structure_foundation, bore_mechanism, ore_storage_tank, boreing_mechanism_buffers_and_bushings, power_supply_unit, ore_storage_unit, resource_handling_system",
   ingredientSlotType = "0, 0, 2, 0, 0, 2, 0, 1, 1, 1",
   resourceTypes = "steel, metal, object/tangible/component/structure/shared_wall_module.iff, metal, metal, object/tangible/component/structure/shared_wall_module.iff, chemical, object/tangible/component/structure/shared_generator_turbine.iff, object/tangible/component/structure/shared_structure_small_storage_section.iff, object/tangible/component/structure/shared_ore_mining_unit.iff",
   resourceQuantities = "400, 600, 1, 200, 300, 6, 400, 2, 6, 2",
   combineTypes = "0, 0, 1, 0, 0, 1, 0, 1, 1, 1",
   contribution = "100, 100, 100, 100, 100, 100, 100, 100, 100, 100",

   numberExperimentalProperties = "1, 1, 3, 2, 1",
   experimentalProperties = "XX, XX, HR, SR, UT, MA, UT, XX",
   experimentalWeights = "1, 1, 1, 1, 2, 1, 2, 1",
   experimentalGroupTitles = "null, null, expEffeciency, expStorage, null",

   experimentalSubGroupTitles = "null, null, extractrate, hoppersize, hitpoints",
   experimentalMin = "0, 0, 3, 100000, 1000",
   experimentalMax = "0, 0, 7, 150000, 1000",
   experimentalPrecision = "0, 0, 0, 0, 0",

   tanoAttributes = "objecttype=8388610:objectcrc=3224287923:stfFile=deed:stfName=ore_heavy_harvester_deed_name:stfDetail=:itemmask=65535:customattributes=targetObjectSubType=4099;targetStfFile=installation_n;targetStfName=heavy_ore_mine;targetObjectFile=object/installation/mining_ore/shared_mining_ore_harvester_heavy.iff;targetConstructionObjectCRC=1103585647;maintenanceRate=90.0;powerRate=75.0;harvesterType=6;lotSize=1;:",

   blueFrogAttributes = "",
   blueFrogEnabled = False,

   customizationOptions = "",
   customizationDefaults = "",
   customizationSkill = "structure_customization",
}

DraftSchematics:addDraftSchematic(deedForHeavyMineralMiningInstallation, 1543208719)--- Add to global DraftSchematics table
