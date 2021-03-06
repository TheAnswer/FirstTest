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


object_weapon_ranged_grenade_shared_grenade_bug_bomb = SharedWeaponObjectTemplate:new {
	appearanceFilename = "appearance/wp_grenade_class_a.apt",
	arrangementDescriptorFilename = "",
	attackType = 1,

	certificationsRequired = {},
	clearFloraRadius = 0,
	clientDataFile = "clientdata/client_shared_grenade_bug_bomb.cdf",
	collisionActionBlockFlags = 0,
	collisionActionFlags = 51,
	collisionActionPassFlags = 1,
	collisionMaterialBlockFlags = 0,
	collisionMaterialFlags = 1,
	collisionMaterialPassFlags = 0,
	containerType = 0,
	containerVolumeLimit = 0,
	customizationVariableMapping = {},

	detailedDescription = "@weapon_detail:grenade_bug_bomb",

	gameObjectType = 131075,

	locationReservationRadius = 0,
	lookAtText = "string_id_table",

	noBuildRadius = 0,

	objectName = "@weapon_name:grenade_bug_bomb",
	onlyVisibleInTools = 0,

	paletteColorCustomizationVariables = {},
	portalLayoutFilename = "",

	rangedIntCustomizationVariables = {},

	scale = 1,
	scaleThresholdBeforeExtentTest = 0.5,
	sendToClient = 1,
	slotDescriptorFilename = "",
	snapToTerrain = 1,
	socketDestinations = {},
	structureFootprintFileName = "",
	surfaceType = 0,

	targetable = 1,

	useStructureFootprintOutline = 0,

	weaponEffect = "bolt",
	weaponEffectIndex = 0
}

ObjectTemplates:addTemplate(object_weapon_ranged_grenade_shared_grenade_bug_bomb, 4031568609)

object_weapon_ranged_grenade_shared_grenade_cryoban = SharedWeaponObjectTemplate:new {
	appearanceFilename = "appearance/wp_grenade_ww41.apt",
	arrangementDescriptorFilename = "",
	attackType = 1,

	certificationsRequired = {},
	clearFloraRadius = 0,
	clientDataFile = "clientdata/client_shared_grenade_cryoban.cdf",
	collisionActionBlockFlags = 0,
	collisionActionFlags = 51,
	collisionActionPassFlags = 1,
	collisionMaterialBlockFlags = 0,
	collisionMaterialFlags = 1,
	collisionMaterialPassFlags = 0,
	containerType = 0,
	containerVolumeLimit = 0,
	customizationVariableMapping = {},

	detailedDescription = "@weapon_detail:grenade_cryoban",

	gameObjectType = 131075,

	locationReservationRadius = 0,
	lookAtText = "@weapon_lookat:grenade_cryoban",

	noBuildRadius = 0,

	objectName = "@weapon_name:grenade_cryoban",
	onlyVisibleInTools = 0,

	paletteColorCustomizationVariables = {},
	portalLayoutFilename = "",

	rangedIntCustomizationVariables = {},

	scale = 1,
	scaleThresholdBeforeExtentTest = 0.5,
	sendToClient = 1,
	slotDescriptorFilename = "",
	snapToTerrain = 1,
	socketDestinations = {},
	structureFootprintFileName = "",
	surfaceType = 0,

	targetable = 1,

	useStructureFootprintOutline = 0,

	weaponEffect = "bolt",
	weaponEffectIndex = 0
}

ObjectTemplates:addTemplate(object_weapon_ranged_grenade_shared_grenade_cryoban, 2139866976)

object_weapon_ranged_grenade_shared_grenade_fallback = SharedWeaponObjectTemplate:new {
	appearanceFilename = "appearance/wp_grenade_c22.apt",
	arrangementDescriptorFilename = "",
	attackType = 1,

	certificationsRequired = {},
	clearFloraRadius = 0,
	clientDataFile = "clientdata/client_shared_grenade_small_01.cdf",
	collisionActionBlockFlags = 0,
	collisionActionFlags = 51,
	collisionActionPassFlags = 1,
	collisionMaterialBlockFlags = 0,
	collisionMaterialFlags = 1,
	collisionMaterialPassFlags = 0,
	containerType = 0,
	containerVolumeLimit = 0,
	customizationVariableMapping = {},

	detailedDescription = "string_id_table",

	gameObjectType = 131075,

	locationReservationRadius = 0,
	lookAtText = "string_id_table",

	noBuildRadius = 0,

	objectName = "@obj_n:unknown_weapon",
	onlyVisibleInTools = 0,

	paletteColorCustomizationVariables = {},
	portalLayoutFilename = "",

	rangedIntCustomizationVariables = {},

	scale = 1,
	scaleThresholdBeforeExtentTest = 0.5,
	sendToClient = 1,
	slotDescriptorFilename = "",
	snapToTerrain = 1,
	socketDestinations = {},
	structureFootprintFileName = "",
	surfaceType = 0,

	targetable = 1,

	useStructureFootprintOutline = 0,

	weaponEffect = "bolt",
	weaponEffectIndex = 0
}

ObjectTemplates:addTemplate(object_weapon_ranged_grenade_shared_grenade_fallback, 1363204393)

object_weapon_ranged_grenade_shared_grenade_fragmentation = SharedWeaponObjectTemplate:new {
	appearanceFilename = "appearance/wp_grenade_c22.apt",
	arrangementDescriptorFilename = "",
	attackType = 1,

	certificationsRequired = {},
	clearFloraRadius = 0,
	clientDataFile = "clientdata/client_shared_grenade_fragmentation.cdf",
	collisionActionBlockFlags = 0,
	collisionActionFlags = 51,
	collisionActionPassFlags = 1,
	collisionMaterialBlockFlags = 0,
	collisionMaterialFlags = 1,
	collisionMaterialPassFlags = 0,
	containerType = 0,
	containerVolumeLimit = 0,
	customizationVariableMapping = {},

	detailedDescription = "@weapon_detail:grenade_fragmentation",

	gameObjectType = 131075,

	locationReservationRadius = 0,
	lookAtText = "@weapon_lookat:grenade_fragmentation",

	noBuildRadius = 0,

	objectName = "@weapon_name:grenade_fragmentation",
	onlyVisibleInTools = 0,

	paletteColorCustomizationVariables = {},
	portalLayoutFilename = "",

	rangedIntCustomizationVariables = {},

	scale = 1,
	scaleThresholdBeforeExtentTest = 0.5,
	sendToClient = 1,
	slotDescriptorFilename = "",
	snapToTerrain = 1,
	socketDestinations = {},
	structureFootprintFileName = "",
	surfaceType = 0,

	targetable = 1,

	useStructureFootprintOutline = 0,

	weaponEffect = "bolt",
	weaponEffectIndex = 0
}

ObjectTemplates:addTemplate(object_weapon_ranged_grenade_shared_grenade_fragmentation, 2723525196)

object_weapon_ranged_grenade_shared_grenade_fragmentation_light = SharedWeaponObjectTemplate:new {
	appearanceFilename = "appearance/wp_grenade_c22.apt",
	arrangementDescriptorFilename = "",
	attackType = 1,

	certificationsRequired = {},
	clearFloraRadius = 0,
	clientDataFile = "clientdata/client_shared_grenade_fragmentation.cdf",
	collisionActionBlockFlags = 0,
	collisionActionFlags = 51,
	collisionActionPassFlags = 1,
	collisionMaterialBlockFlags = 0,
	collisionMaterialFlags = 1,
	collisionMaterialPassFlags = 0,
	containerType = 0,
	containerVolumeLimit = 0,
	customizationVariableMapping = {},

	detailedDescription = "@weapon_detail:grenade_fragmentation_light",

	gameObjectType = 131075,

	locationReservationRadius = 0,
	lookAtText = "@weapon_lookat:grenade_fragmentation_light",

	noBuildRadius = 0,

	objectName = "@weapon_name:grenade_fragmentation_light",
	onlyVisibleInTools = 0,

	paletteColorCustomizationVariables = {},
	portalLayoutFilename = "",

	rangedIntCustomizationVariables = {},

	scale = 1,
	scaleThresholdBeforeExtentTest = 0.5,
	sendToClient = 1,
	slotDescriptorFilename = "",
	snapToTerrain = 1,
	socketDestinations = {},
	structureFootprintFileName = "",
	surfaceType = 0,

	targetable = 1,

	useStructureFootprintOutline = 0,

	weaponEffect = "bolt",
	weaponEffectIndex = 0
}

ObjectTemplates:addTemplate(object_weapon_ranged_grenade_shared_grenade_fragmentation_light, 2839802123)

object_weapon_ranged_grenade_shared_grenade_glop = SharedWeaponObjectTemplate:new {
	appearanceFilename = "appearance/wp_grenade_glop.apt",
	arrangementDescriptorFilename = "",
	attackType = 1,

	certificationsRequired = {},
	clearFloraRadius = 0,
	clientDataFile = "clientdata/client_shared_grenade_glop.cdf",
	collisionActionBlockFlags = 0,
	collisionActionFlags = 51,
	collisionActionPassFlags = 1,
	collisionMaterialBlockFlags = 0,
	collisionMaterialFlags = 1,
	collisionMaterialPassFlags = 0,
	containerType = 0,
	containerVolumeLimit = 0,
	customizationVariableMapping = {},

	detailedDescription = "@weapon_detail:grenade_glop",

	gameObjectType = 131075,

	locationReservationRadius = 0,
	lookAtText = "@weapon_lookat:grenade_glop",

	noBuildRadius = 0,

	objectName = "@weapon_name:grenade_glop",
	onlyVisibleInTools = 0,

	paletteColorCustomizationVariables = {},
	portalLayoutFilename = "",

	rangedIntCustomizationVariables = {},

	scale = 1,
	scaleThresholdBeforeExtentTest = 0.5,
	sendToClient = 1,
	slotDescriptorFilename = "",
	snapToTerrain = 1,
	socketDestinations = {},
	structureFootprintFileName = "",
	surfaceType = 0,

	targetable = 1,

	useStructureFootprintOutline = 0,

	weaponEffect = "bolt",
	weaponEffectIndex = 0
}

ObjectTemplates:addTemplate(object_weapon_ranged_grenade_shared_grenade_glop, 595784365)

object_weapon_ranged_grenade_shared_grenade_imperial_detonator = SharedWeaponObjectTemplate:new {
	appearanceFilename = "appearance/wp_grenade_imp_detonator.apt",
	arrangementDescriptorFilename = "",
	attackType = 1,

	certificationsRequired = {},
	clearFloraRadius = 0,
	clientDataFile = "clientdata/client_shared_grenade_imp_detonator.cdf",
	collisionActionBlockFlags = 0,
	collisionActionFlags = 51,
	collisionActionPassFlags = 1,
	collisionMaterialBlockFlags = 0,
	collisionMaterialFlags = 1,
	collisionMaterialPassFlags = 0,
	containerType = 0,
	containerVolumeLimit = 0,
	customizationVariableMapping = {},

	detailedDescription = "@weapon_detail:grenade_imperial_detonator",

	gameObjectType = 131075,

	locationReservationRadius = 0,
	lookAtText = "@weapon_lookat:grenade_imperial_detonator",

	noBuildRadius = 0,

	objectName = "@weapon_name:grenade_imperial_detonator",
	onlyVisibleInTools = 0,

	paletteColorCustomizationVariables = {},
	portalLayoutFilename = "",

	rangedIntCustomizationVariables = {},

	scale = 1,
	scaleThresholdBeforeExtentTest = 0.5,
	sendToClient = 1,
	slotDescriptorFilename = "",
	snapToTerrain = 1,
	socketDestinations = {},
	structureFootprintFileName = "",
	surfaceType = 0,

	targetable = 1,

	useStructureFootprintOutline = 0,

	weaponEffect = "bolt",
	weaponEffectIndex = 0
}

ObjectTemplates:addTemplate(object_weapon_ranged_grenade_shared_grenade_imperial_detonator, 4036235024)

object_weapon_ranged_grenade_shared_grenade_poison = SharedWeaponObjectTemplate:new {
	appearanceFilename = "appearance/wp_grenade_class_a.apt",
	arrangementDescriptorFilename = "",
	attackType = 1,

	certificationsRequired = {},
	clearFloraRadius = 0,
	clientDataFile = "clientdata/client_shared_grenade_small_01.cdf",
	collisionActionBlockFlags = 0,
	collisionActionFlags = 51,
	collisionActionPassFlags = 1,
	collisionMaterialBlockFlags = 0,
	collisionMaterialFlags = 1,
	collisionMaterialPassFlags = 0,
	containerType = 0,
	containerVolumeLimit = 0,
	customizationVariableMapping = {},

	detailedDescription = "string_id_table",

	gameObjectType = 131075,

	locationReservationRadius = 0,
	lookAtText = "string_id_table",

	noBuildRadius = 0,

	objectName = "@obj_n:unknown_weapon",
	onlyVisibleInTools = 0,

	paletteColorCustomizationVariables = {},
	portalLayoutFilename = "",

	rangedIntCustomizationVariables = {},

	scale = 1,
	scaleThresholdBeforeExtentTest = 0.5,
	sendToClient = 1,
	slotDescriptorFilename = "",
	snapToTerrain = 1,
	socketDestinations = {},
	structureFootprintFileName = "",
	surfaceType = 0,

	targetable = 1,

	useStructureFootprintOutline = 0,

	weaponEffect = "bolt",
	weaponEffectIndex = 0
}

ObjectTemplates:addTemplate(object_weapon_ranged_grenade_shared_grenade_poison, 2714007859)

object_weapon_ranged_grenade_shared_grenade_proton = SharedWeaponObjectTemplate:new {
	appearanceFilename = "appearance/wp_grenade_7prg.apt",
	arrangementDescriptorFilename = "",
	attackType = 1,

	certificationsRequired = {},
	clearFloraRadius = 0,
	clientDataFile = "clientdata/client_shared_grenade_proton.cdf",
	collisionActionBlockFlags = 0,
	collisionActionFlags = 51,
	collisionActionPassFlags = 1,
	collisionMaterialBlockFlags = 0,
	collisionMaterialFlags = 1,
	collisionMaterialPassFlags = 0,
	containerType = 0,
	containerVolumeLimit = 0,
	customizationVariableMapping = {},

	detailedDescription = "@weapon_detail:grenade_proton",

	gameObjectType = 131075,

	locationReservationRadius = 0,
	lookAtText = "@weapon_lookat:grenade_proton",

	noBuildRadius = 0,

	objectName = "@weapon_name:grenade_proton",
	onlyVisibleInTools = 0,

	paletteColorCustomizationVariables = {},
	portalLayoutFilename = "",

	rangedIntCustomizationVariables = {},

	scale = 1,
	scaleThresholdBeforeExtentTest = 0.5,
	sendToClient = 1,
	slotDescriptorFilename = "",
	snapToTerrain = 1,
	socketDestinations = {},
	structureFootprintFileName = "",
	surfaceType = 0,

	targetable = 1,

	useStructureFootprintOutline = 0,

	weaponEffect = "bolt",
	weaponEffectIndex = 0
}

ObjectTemplates:addTemplate(object_weapon_ranged_grenade_shared_grenade_proton, 904042039)

object_weapon_ranged_grenade_shared_grenade_thermal_detonator = SharedWeaponObjectTemplate:new {
	appearanceFilename = "appearance/wp_grenade_class_a.apt",
	arrangementDescriptorFilename = "",
	attackType = 1,

	certificationsRequired = {},
	clearFloraRadius = 0,
	clientDataFile = "clientdata/client_shared_grenade_large_02.cdf",
	collisionActionBlockFlags = 0,
	collisionActionFlags = 51,
	collisionActionPassFlags = 1,
	collisionMaterialBlockFlags = 0,
	collisionMaterialFlags = 1,
	collisionMaterialPassFlags = 0,
	containerType = 0,
	containerVolumeLimit = 0,
	customizationVariableMapping = {},

	detailedDescription = "@weapon_detail:grenade_thermal_detonator",

	gameObjectType = 131075,

	locationReservationRadius = 0,
	lookAtText = "@weapon_lookat:grenade_thermal_detonator",

	noBuildRadius = 0,

	objectName = "@weapon_name:grenade_thermal_detonator",
	onlyVisibleInTools = 0,

	paletteColorCustomizationVariables = {},
	portalLayoutFilename = "",

	rangedIntCustomizationVariables = {},

	scale = 1,
	scaleThresholdBeforeExtentTest = 0.5,
	sendToClient = 1,
	slotDescriptorFilename = "",
	snapToTerrain = 1,
	socketDestinations = {},
	structureFootprintFileName = "",
	surfaceType = 0,

	targetable = 1,

	useStructureFootprintOutline = 0,

	weaponEffect = "bolt",
	weaponEffectIndex = 0
}

ObjectTemplates:addTemplate(object_weapon_ranged_grenade_shared_grenade_thermal_detonator, 4094720749)
