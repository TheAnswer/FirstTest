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

electronicsGPModule = Object:new {

   objectName = "Electronics GP Module",
   stfName = "electronics_gp_module",
   stfFile = "craft_item_ingredients_n",
   objectCRC = 4228360112,
   groupName = "craftArtisanMasterGroupA", -- Group schematic is awarded in (See skills table)

   craftingToolTab = 524288, -- (See DraftSchemticImplementation.h)
   complexity = 15, 
   size = 3, 

   xpType = "crafting_general", 
   xp = 50, 

   assemblySkill = "general_assembly", 
   experimentingSkill = "general_experimentation", 

   ingredientTemplateNames = "craft_item_ingredients_n, craft_item_ingredients_n, craft_item_ingredients_n, craft_item_ingredients_n, craft_item_ingredients_n",
   ingredientTitleNames = "module_brackets, circuit_stabilization_medium, circuit_shielding_and_substrate, pre_processing_logic_circuitry, thermal_and_contaminant_shield",
   ingredientSlotType = "0, 0, 0, 0, 0",
   resourceTypes = "metal, petrochem_inert_polymer, ore, copper, gas_inert",
   resourceQuantities = "10, 7, 3, 3, 3",
   combineTypes = "0, 0, 0, 0, 0",
   contribution = "100, 100, 100, 100, 100",

   numberExperimentalProperties = "1, 1, 1, 1",
   experimentalProperties = "XX, XX, UT, OQ",
   experimentalWeights = "1, 1, 1, 1",
   experimentalGroupTitles = "null, null, exp_durability, exp_effectiveness",

   experimentalSubGroupTitles = "null, null, hitpoints, usemodifier",
   experimentalMin = "0, 0, 100, -5",
   experimentalMax = "0, 0, 150, 5",
   experimentalPrecision = "0, 0, 0, 0",

   tanoAttributes = "objecttype=8200:objectcrc=3786408832:stfFile=craft_item_ingredients_n:stfName=electronics_gp_module:stfDetail=:itemmask=65535::",

   blueFrogAttributes = "",
   blueFrogEnabled = False,

   customizationOptions = "",
   customizationDefaults = "",
   customizationSkill = "clothing_customization"

}

DraftSchematics:addDraftSchematic(electronicsGPModule, 4228360112)--- Add to global DraftSchematics table
