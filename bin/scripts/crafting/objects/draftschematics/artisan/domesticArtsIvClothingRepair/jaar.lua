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

jaar = Object:new {

   objectName = "Jaar",
   stfName = "jaar",
   stfFile = "food_name",
   objectCRC = 4135578942,
   groupName = "craftArtisanDomesticGroupD", -- Group schematic is awarded in (See skills table)

   craftingToolTab = 4, -- (See DraftSchemticImplementation.h)
   complexity = 5, 
   size = 1, 

   xpType = "crafting_general", 
   xp = 70, 

   assemblySkill = "general_assembly", 
   experimentingSkill = "general_experimentation", 

   ingredientTemplateNames = "craft_food_ingredients_n, craft_food_ingredients_n, craft_food_ingredients_n, craft_food_ingredients_n",
   ingredientTitleNames = "water, fruit_flavoring, glass, additive",
   ingredientSlotType = "0, 0, 2, 4",
   resourceTypes = "milk, fruit, object/tangible/component/food/base/shared_drink_container_base.iff, object/tangible/food/crafted/additive/shared_additive_light.iff",
   resourceQuantities = "15, 10, 1, 1",
   combineTypes = "0, 0, 1, 1",
   contribution = "100, 100, 100, 100",

   numberExperimentalProperties = "1, 1, 1, 1, 2, 2, 2",
   experimentalProperties = "XX, XX, XX, XX, PE, OQ, DR, PE, DR, OQ",
   experimentalWeights = "1, 1, 1, 1, 2, 1, 1, 3, 3, 1",
   experimentalGroupTitles = "null, null, null, null, exp_nutrition, exp_quantity, exp_filling",

   experimentalSubGroupTitles = "null, null, hitpoints, quantity_bonus, nutrition, quantity, filling",
   experimentalMin = "0, 0, 1000, 0, 75, 60, 80",
   experimentalMax = "0, 0, 1000, 0, 120, 100, 120",
   experimentalPrecision = "0, 0, 0, 0, 0, 0, 0",

   tanoAttributes = "objecttype=:objectcrc=355298575:stfFile=food_name:stfName=jaar:stfDetail=:itemmask=65535::",

   blueFrogAttributes = "",
   blueFrogEnabled = False,

   customizationOptions = "",
   customizationDefaults = "",
   customizationSkill = "clothing_customization"

}

DraftSchematics:addDraftSchematic(jaar, 4135578942)--- Add to global DraftSchematics table
