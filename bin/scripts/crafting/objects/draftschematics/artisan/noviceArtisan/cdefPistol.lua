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

cdefPistol = Object:new {

   objectName = "CDEF Pistol",
   stfName = "pistol_cdef",
   stfFile = "weapon_name",
   objectCRC = 2266178839,
   groupName = "craftArtisanNewbieGroupA", -- Group schematic is awarded in (See skills table)

   craftingToolTab = 1, -- (See DraftSchemticImplementation.h)
   complexity = 8, 
   size = 3, 

   xpType = "crafting_general", 
   xp = 42, 

   assemblySkill = "general_assembly", 
   experimentingSkill = "general_experimentation", 

   ingredientTemplateNames = "craft_weapon_ingredients_n, craft_weapon_ingredients_n, craft_weapon_ingredients_n",
   ingredientTitleNames = "frame_assembly, receiver_assembly, grip_assembly",
   ingredientSlotType = "0, 0, 0",
   resourceTypes = "metal, chemical, metal",
   resourceQuantities = "12, 6, 3",
   combineTypes = "0, 0, 0",
   contribution = "100, 100, 100",

   numberExperimentalProperties = "1, 1, 2, 2, 2, 2, 2, 2, 1, 1, 1, 2, 2, 2, 2",
   experimentalProperties = "XX, XX, CD, OQ, CD, OQ, CD, OQ, CD, OQ, CD, OQ, CD, OQ, XX, XX, XX, CD, OQ, CD, OQ, CD, OQ, CD, OQ",
   experimentalWeights = "1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1",
   experimentalGroupTitles = "null, null, expDamage, expDamage, expDamage, expDamage, expEffeciency, exp_durability, null, null, null, expRange, expEffeciency, expEffeciency, expEffeciency",

   experimentalSubGroupTitles = "null, null, mindamage, maxdamage, attackspeed, woundchance, roundsused, hitpoints, zerorangemod, maxrangemod, midrange, midrangemod, attackhealthcost, attackactioncost, attackmindcost",
   experimentalMin = "0, 0, 17, 35, 4.6, 4, 5, 750, 0, -80, 15, 35, 10, 22, 10",
   experimentalMax = "0, 0, 32, 65, 3.2, 5, 20, 1500, 0, -80, 15, 65, 7, 15, 7",
   experimentalPrecision = "0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0",

   tanoAttributes = "objecttype=131082:objectcrc=937103853:stfFile=weapon_name:stfName=pistol_cdef:stfDetail=:itemmask=65535:customattributes=damagetype=2;:",

   blueFrogAttributes = "",
   blueFrogEnabled = False,

   customizationOptions = "",
   customizationDefaults = "",
   customizationSkill = "clothing_customization"

}

DraftSchematics:addDraftSchematic(cdefPistol, 2266178839)--- Add to global DraftSchematics table
