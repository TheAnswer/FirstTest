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

bofaTreat = Object:new {

   objectName = "Bofa Treat",
   stfName = "bofa_treat",
   stfFile = "food_name",
   objectCRC = 2207249955,
   groupName = "craftArtisanNewbieGroupB", -- Group schematic is awarded in (See skills table)

   craftingToolTab = 4, -- (See DraftSchemticImplementation.h)
   complexity = 3, 
   size = 1, 

   xpType = "crafting_general", 
   xp = 20, 

   assemblySkill = "general_assembly", 
   experimentingSkill = "general_experimentation", 

   ingredientTemplateNames = "craft_food_ingredients_n, craft_food_ingredients_n, craft_food_ingredients_n",
   ingredientTitleNames = "dried_fruit, crust, additive",
   ingredientSlotType = "0, 0, 4",
   resourceTypes = "organic, cereal, object/tangible/food/crafted/additive/shared_additive_light.iff",
   resourceQuantities = "3, 8, 1",
   combineTypes = "0, 0, 1",
   contribution = "100, 100, 100",

   numberExperimentalProperties = "1, 1, 1, 2, 2, 2, 2",
   experimentalProperties = "XX, XX, XX, PE, OQ, FL, OQ, DR, PE, DR, OQ",
   experimentalWeights = "1, 1, 1, 2, 1, 2, 1, 1, 3, 3, 1",
   experimentalGroupTitles = "null, null, null, exp_nutrition, exp_flavor, exp_quantity, exp_filling",

   experimentalSubGroupTitles = "null, null, hitpoints, nutrition, flavor, quantity, filling",
   experimentalMin = "0, 0, 1000, 75, 60, 60, 80",
   experimentalMax = "0, 0, 1000, 120, 120, 100, 120",
   experimentalPrecision = "0, 0, 0, 0, 0, 0, 0",

   tanoAttributes = "objecttype=8202:objectcrc=2010692823:stfFile=food_name:stfName=bofa_treat:stfDetail=:itemmask=65535:customattributes=buffCRC=2339561171;downerCRC=0;buffType=1;numAttributes=1;mods=;buffs=health=50,;heals=;quantity=10;filling=9;duration=3000;:",

   blueFrogAttributes = "",
   blueFrogEnabled = False,

   customizationOptions = "",
   customizationDefaults = "",
   customizationSkill = "clothing_customization"

}

DraftSchematics:addDraftSchematic(bofaTreat, 2207249955)--- Add to global DraftSchematics table
