--Copyright (C) 2010 <SWGEmu>


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


object_draft_schematic_clothing_clothing_bandolier_field_06 = object_draft_schematic_clothing_shared_clothing_bandolier_field_06:new {

   templateType = DRAFTSCHEMATIC,

   customObjectName = "Rank Sash",

   groupName = "craftClothingFieldGroupB", -- Group schematic is awarded in (See skills table)

   craftingToolTab = 8, -- (See DraftSchemticImplementation.h)
   complexity = 20, 
   size = 2, 

   xpType = "crafting_clothing_general", 
   xp = 100, 

   assemblySkill = "clothing_assembly", 
   experimentingSkill = "clothing_experimentation", 
   customizationSkill = "clothing_customization", 

   customizationOptions = {2},
   customizationStringNames = {"/private/index_color_1"},
   customizationDefaults = {0},

   ingredientTemplateNames = {"craft_clothing_ingredients_n", "craft_clothing_ingredients_n", "craft_clothing_ingredients_n", "craft_clothing_ingredients_n"},
   ingredientTitleNames = {"utility_pocket", "load_bearing_harness", "steel_interstructure", "reinforcement"},
   ingredientSlotType = {2, 0, 0, 2},
   resourceTypes = {"object/tangible/component/clothing/shared_cargo_pocket.iff", "fiberplast", "metal", "object/tangible/component/clothing/shared_reinforced_fiber_panels.iff"},
   resourceQuantities = {1, 20, 20, 1},
   combineTypes = {1, 0, 0, 1},
   contribution = {100, 100, 100, 100},

   templates = {
              2021886631, -- Script: 'object/tangible/wearables/bandolier/bandolier_s06.iff'
             }

}
ObjectTemplates:addTemplate(object_draft_schematic_clothing_clothing_bandolier_field_06, "object/draft_schematic/clothing/clothing_bandolier_field_06.iff")