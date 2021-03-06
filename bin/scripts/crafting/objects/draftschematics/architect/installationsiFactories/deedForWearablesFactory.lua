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

deedForWearablesFactory = Object:new {

   objectName = "Deed for: Wearables Factory",
   stfName = "clothing_factory",
   stfFile = "deed",
   objectCRC = 3925546520,
   groupName = "craftInstallationGroupA", -- Group schematic is awarded in (See skills table)

   craftingToolTab = 1024, -- (See DraftSchemticImplementation.h)
   complexity = 13, 
   size = 16, 

   xpType = "crafting_structure_general", 
   xp = 1900, 

   assemblySkill = "structure_assembly", 
   experimentingSkill = "structure_experimentation", 

   ingredientTemplateNames = "craft_structure_ingredients_n, craft_structure_ingredients_n, craft_structure_ingredients_n, craft_structure_ingredients_n, craft_structure_ingredients_n, craft_structure_ingredients_n, craft_structure_ingredients_n",
   ingredientTitleNames = "load_bearing_frame_and_reinforcement, body_shell_and_casing, structure_foundation, thermal_noise_and_charge_proof_shielding, power_supply_unit, ouput_storage_unit, semi_automated_assembly_mechanism",
   ingredientSlotType = "0, 0, 0, 0, 0, 0, 0",
   resourceTypes = "steel, steel, ore, ore, steel, steel, steel",
   resourceQuantities = "300, 3, 250, 400, 1, 1, 1",
   combineTypes = "0, 0, 0, 0, 0, 0, 0",
   contribution = "100, 100, 100, 100, 100, 100, 100",

   numberExperimentalProperties = "1, 1, 1, 2, 2, 2",
   experimentalProperties = "XX, XX, XX, DR, UT, DR, UT, DR, UT",
   experimentalWeights = "1, 1, 1, 1, 2, 1, 2, 1, 2",
   experimentalGroupTitles = "null, null, null, expEffeciency, expStorage, exp_durability",

   experimentalSubGroupTitles = "null, null, extractrate, buildrate, hoppersize, hitpoints",
   experimentalMin = "0, 0, 0, 5, 1500, 5000",
   experimentalMax = "0, 0, 0, 12, 4000, 7000",
   experimentalPrecision = "0, 0, 0, 0, 0, 0",

   tanoAttributes = "objecttype=8388610:objectcrc=1812501477:objecttemp=clothing_factory:templatetype=deed:itemmask=65535::",
   customizationOptions = "",
   customizationDefaults = "",
   customizationSkill = "structure_customization"

}

DraftSchematics:addDraftSchematic(deedForWearablesFactory, 3925546520)--- Add to global DraftSchematics table
