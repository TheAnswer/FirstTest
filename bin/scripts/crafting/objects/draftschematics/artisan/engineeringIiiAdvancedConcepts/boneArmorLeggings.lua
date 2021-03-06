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

boneArmorLeggings = Object:new {

   objectName = "Bone Armor Leggings",
   stfName = "armor_bone_s01_leggings",
   stfFile = "wearables_name",
   objectCRC = 4006019725,
   groupName = "craftArtisanEngineeringGroupC", -- Group schematic is awarded in (See skills table)

   craftingToolTab = 2, -- (See DraftSchemticImplementation.h)
   complexity = 16, 
   size = 3, 

   xpType = "crafting_general", 
   xp = 260, 

   assemblySkill = "general_assembly", 
   experimentingSkill = "general_experimentation", 

   ingredientTemplateNames = "craft_clothing_ingredients_n, craft_clothing_ingredients_n, craft_clothing_ingredients_n, craft_clothing_ingredients_n, craft_clothing_ingredients_n, craft_clothing_ingredients_n, craft_clothing_ingredients_n, craft_clothing_ingredients_n, craft_clothing_ingredients_n",
   ingredientTitleNames = "auxilary_coverage, body, liner, hardware_and_attachments, binding_and_reinforcement, padding, armor, load_bearing_harness, reinforcement",
   ingredientSlotType = "0, 0, 0, 0, 0, 0, 2, 2, 2",
   resourceTypes = "bone, hide, hide, metal, petrochem_inert, hide, object/tangible/component/armor/shared_armor_segment_bone.iff, object/tangible/component/clothing/shared_fiberplast_panel.iff, object/tangible/component/clothing/shared_fiberplast_panel.iff",
   resourceQuantities = "30, 30, 30, 20, 10, 10, 1, 1, 1",
   combineTypes = "0, 0, 0, 0, 0, 0, 1, 1, 1",
   contribution = "100, 100, 100, 100, 100, 100, 100, 100, 100",

   numberExperimentalProperties = "1, 1, 1, 2, 2, 2, 2, 2, 2, 1, 1, 2, 1",
   experimentalProperties = "XX, XX, XX, OQ, SR, OQ, SR, OQ, UT, MA, OQ, MA, OQ, MA, OQ, XX, XX, OQ, SR, XX",
   experimentalWeights = "1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1",
   experimentalGroupTitles = "null, null, null, exp_durability, exp_quality, exp_durability, exp_durability, exp_durability, exp_durability, null, null, exp_resistance, null",

   experimentalSubGroupTitles = "null, null, sockets, hit_points, armor_effectiveness, armor_integrity, armor_health_encumbrance, armor_action_encumbrance, armor_mind_encumbrance, armor_rating, armor_special_type, armor_special_effectiveness, armor_special_integrity",
   experimentalMin = "0, 0, 0, 1000, 5, 7500, 18, 60, 4, 1, 2, 5, 7500",
   experimentalMax = "0, 0, 0, 1000, 20, 12500, 10, 36, 2, 1, 2, 30, 12500",
   experimentalPrecision = "0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0",

   tanoAttributes = "objecttype=260:objectcrc=2709205528:stfFile=wearables_name:stfName=armor_bone_s01_leggings:stfDetail=:itemmask=62975:customattributes=specialprotection=energyeffectiveness;vunerability=kineticeffectiveness,blasteffectiveness,stuneffectiveness,heateffectiveness,coldeffectiveness,acideffectiveness,restraineffectiveness;armorPiece=262;armorStyle=4099;:",

   blueFrogAttributes = "",
   blueFrogEnabled = False,

   customizationOptions = "/private/index_color_1, /private/index_color_2",
   customizationDefaults = "7, 0",
   customizationSkill = "armor_customization"

}

DraftSchematics:addDraftSchematic(boneArmorLeggings, 4006019725)--- Add to global DraftSchematics table
