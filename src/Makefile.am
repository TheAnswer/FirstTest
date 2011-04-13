# Copyright (C) 2007 <SWGEmu>
 
# This File is part of Core3.
 
# This program is free software; you can redistribute 
# it and/or modify it under the terms of the GNU Lesser 
# General Public License as published by the Free Software
# Foundation; either version 2 of the License, 
# or (at your option) any later version.
 
# This program is distributed in the hope that it will be useful, 
# but WITHOUT ANY WARRANTY; without even the implied warranty of 
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
# See the GNU Lesser General Public License for
# more details.
 
# You should have received a copy of the GNU Lesser General 
# Public License along with this program; if not, write to
# the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 
# Linking Engine3 statically or dynamically with other modules 
# is making a combined work based on Engine3. 
# Thus, the terms and conditions of the GNU Lesser General Public License 
# cover the whole combination.
 
# In addition, as a special exception, the copyright holders of Engine3 
# give you permission to combine Engine3 program with free software 
# programs or libraries that are released under the GNU LGPL and with 
# code included in the standard release of Core3 under the GNU LGPL 
# license (or modified versions of such code, with unchanged license). 
# You may copy and distribute such a system following the terms of the 
# GNU LGPL for Engine3 and the licenses of the other code concerned, 
# provided that you include the source code of that other code when 
# and as the GNU LGPL requires distribution of source code.
 
# Note that people who make modified versions of Engine3 are not obligated 
# to grant this special exception for their modified versions; 
# it is their choice whether to do so. The GNU Lesser General Public License 
# gives permission to release a modified version without this exception; 
# this exception also makes it possible to release a modified version 
# which carries forward this exception.

AM_CXXFLAGS=-ggdb -Wall -Wextra -Wno-unused -Wno-sign-compare -Wno-multichar

ENGINE3_PATH=../../../../MMOEngine

INCLUDES =  $(SYSTEM_INCLUDES) \
	    -I$(USER_INCLUDES_PATH) -I$(USER_INCLUDES_PATH)/mysql \
	    -I$(ENGINE3_PATH)/include -I/usr/include/lua5.1 -I/usr/include/mysql \
	    -I/usr/local/BerkeleyDB.5.0/include \
	    -I../../../src/trelib/include \
	    -I/usr/include/db5.0
			
LIBS =	$(SYSTEM_LIBS)  \
	-L../../../build/unix/src/client \
	-L/usr/local/BerkeleyDB.5.0/lib \
	-L../../../src/trelib/lib \
	-L/usr/local/BerkeleyDB.5.0/lib \
	-L$(USER_LIBS_PATH)/ -L$(USER_LIBS_PATH)/mysql -L$(USER_LIBS_PATH)/mysql5/mysql -L$(USER_LIBS_PATH)/lua -L$(ENGINE3_PATH)/lib/unix \
	-lmysqlclient -ltreLib -lz -lengine3 -llua -ldb-5.0

bin_PROGRAMS = core3

core3_IDLS =	server/login/LoginServer.cpp \
				server/login/account/Account.cpp \
				server/zone/ZoneServer.cpp \
				server/zone/ZoneProcessServer.cpp \
				server/zone/ZoneClientSession.cpp \
				server/zone/Zone.cpp \
				server/zone/objects/scene/SceneObject.cpp \
				server/zone/objects/area/ActiveArea.cpp \
				server/zone/objects/area/BadgeActiveArea.cpp \
				server/zone/objects/area/GarageArea.cpp \
				server/zone/objects/area/MissionSpawnActiveArea.cpp \
				server/zone/objects/area/MissionReconActiveArea.cpp \
				server/zone/objects/area/SpawnArea.cpp \
				server/zone/objects/area/DynamicSpawnArea.cpp \
				server/zone/objects/area/StaticSpawnArea.cpp \
				server/zone/objects/area/SpawnObserver.cpp \
				server/zone/objects/factorycrate/FactoryCrate.cpp \
				server/zone/objects/intangible/IntangibleObject.cpp \
				server/zone/objects/intangible/ControlDevice.cpp \
				server/zone/objects/staticobject/StaticObject.cpp \
				server/zone/objects/intangible/VehicleControlDevice.cpp \
				server/zone/objects/tangible/TangibleObject.cpp \
				server/zone/objects/tangible/Container.cpp \
				server/zone/objects/tangible/Instrument.cpp \
				server/zone/objects/tangible/InstrumentObserver.cpp \
				server/zone/objects/tangible/consumable/Food.cpp \
				server/zone/objects/tangible/consumable/Drink.cpp \
				server/zone/objects/tangible/loot/LootkitObject.cpp \
				server/zone/objects/tangible/camp/CampKit.cpp \
				server/zone/objects/creature/CreatureObject.cpp \
				server/zone/objects/creature/vendor/VendorCreature.cpp \
				server/zone/objects/creature/trainer/TrainerCreature.cpp \
				server/zone/objects/creature/informant/InformantCreature.cpp \
				server/zone/objects/creature/junkdealer/JunkdealerCreature.cpp \
				server/zone/objects/creature/VehicleObject.cpp \
				server/zone/objects/creature/NonPlayerCreatureObject.cpp \
				server/zone/objects/creature/Creature.cpp \
				server/zone/objects/creature/AiAgent.cpp \
				server/zone/objects/creature/AiObserver.cpp \
				server/zone/objects/creature/shuttle/ShuttleCreature.cpp \
				server/zone/objects/creature/buffs/Buff.cpp \
				server/zone/objects/creature/aigroup/AiGroup.cpp \
				server/zone/objects/creature/aigroup/HerdGroup.cpp \
				server/zone/objects/creature/aigroup/LairGroup.cpp \
				server/zone/objects/creature/aigroup/PackGroup.cpp \
				server/zone/objects/creature/aigroup/AiGroupObserver.cpp \
				server/zone/objects/creature/buffs/DelayedBuff.cpp \
				server/zone/objects/creature/buffs/SpiceBuff.cpp \
				server/zone/objects/creature/buffs/PowerBoostBuff.cpp \
				server/zone/objects/creature/buffs/DurationBuff.cpp \
				server/zone/objects/creature/buffs/SpiceDownerBuff.cpp \
				server/zone/objects/player/PlayerObject.cpp \
				server/zone/objects/player/sui/SuiBox.cpp \
				server/zone/objects/player/sui/messagebox/SuiMessageBox.cpp \
				server/zone/objects/player/sui/listbox/SuiListBox.cpp \
				server/zone/objects/player/sui/listbox/teachplayerlistbox/TeachPlayerListBox.cpp \
				server/zone/objects/player/sui/listbox/resourcedeedlistbox/ResourceDeedListBox.cpp \
				server/zone/objects/player/sui/listbox/playerlearnlistbox/PlayerLearnListBox.cpp \
				server/zone/objects/player/sui/inputbox/SuiInputBox.cpp \
				server/zone/objects/player/sui/listbox/SuiListBoxMenuItem.cpp \
				server/zone/objects/player/sui/slotmachinebox/SuiSlotMachineBox.cpp \
				server/zone/objects/player/sui/banktransferbox/SuiBankTransferBox.cpp \
				server/zone/objects/player/sui/characterbuilderbox/SuiCharacterBuilderBox.cpp \
				server/zone/objects/player/sui/transferbox/SuiTransferBox.cpp \
				server/zone/objects/waypoint/WaypointObject.cpp \
				server/zone/objects/player/PlayerCreature.cpp \
				server/zone/objects/player/sessions/EntertainingSession.cpp \
				server/zone/objects/player/sessions/MigrateStatsSession.cpp \
				server/zone/objects/player/sessions/ImageDesignSession.cpp \
				server/zone/objects/player/sessions/SlicingSession.cpp \
				server/zone/objects/player/sessions/vendor/CreateVendorSession.cpp \
				server/zone/objects/player/EntertainingObserver.cpp \
				server/zone/objects/cell/CellObject.cpp \
				server/zone/objects/group/GroupObject.cpp \
				server/zone/objects/guild/GuildObject.cpp \
				server/zone/objects/region/Region.cpp \
				server/zone/objects/installation/InstallationObject.cpp \
				server/zone/objects/installation/shuttle/ShuttleInstallation.cpp \
				server/zone/objects/installation/garage/GarageInstallation.cpp \
				server/zone/objects/installation/factory/FactoryObject.cpp \
				server/zone/objects/installation/generator/GeneratorObject.cpp \
				server/zone/objects/installation/harvester/HarvesterObject.cpp \
				server/zone/objects/building/BuildingObject.cpp \
				server/zone/objects/building/cloning/CloningBuildingObject.cpp \
				server/zone/objects/building/city/CityHallObject.cpp \
				server/zone/objects/building/medical/MedicalBuildingObject.cpp \
				server/zone/objects/building/recreation/RecreationBuildingObject.cpp \
				server/zone/objects/building/travel/TravelBuildingObject.cpp \
				server/zone/objects/building/tutorial/TutorialBuildingObject.cpp \
				server/zone/managers/guild/GuildManager.cpp \
				server/chat/room/ChatRoom.cpp \
				server/chat/ChatManager.cpp \
				server/chat/PersistentMessage.cpp \
				server/zone/managers/ZoneManager.cpp \
				server/zone/managers/objectcontroller/ObjectController.cpp \
				server/zone/managers/player/PlayerManager.cpp \
				server/zone/objects/draftschematic/DraftSchematic.cpp \
				server/zone/objects/manufactureschematic/ManufactureSchematic.cpp \
				server/zone/objects/manufactureschematic/craftingvalues/CraftingValues.cpp \
				server/zone/objects/manufactureschematic/factoryblueprint/FactoryBlueprint.cpp \
				server/zone/objects/manufactureschematic/factoryblueprint/BlueprintEntry.cpp \
				server/zone/objects/resource/ResourceSpawn.cpp \
				server/zone/objects/structure/StructureObject.cpp \
				server/zone/objects/tangible/fishing/FishingPoleObject.cpp \
				server/zone/objects/tangible/fishing/FishingBaitObject.cpp \
				server/zone/objects/tangible/fishing/FishObject.cpp \
				server/zone/objects/tangible/firework/FireworkObject.cpp \
				server/zone/objects/tangible/consumable/Consumable.cpp \
				server/zone/objects/tangible/pharmaceutical/CurePack.cpp \
				server/zone/objects/tangible/pharmaceutical/DotPack.cpp \
				server/zone/objects/tangible/pharmaceutical/EnhancePack.cpp \
				server/zone/objects/tangible/pharmaceutical/PharmaceuticalObject.cpp \
				server/zone/objects/tangible/pharmaceutical/RangedStimPack.cpp \
				server/zone/objects/tangible/pharmaceutical/StimPack.cpp \
				server/zone/objects/tangible/pharmaceutical/RevivePack.cpp \
				server/zone/objects/tangible/pharmaceutical/StatePack.cpp \
				server/zone/objects/tangible/pharmaceutical/WoundPack.cpp \
				server/zone/managers/minigames/FishingManager.cpp \
				server/zone/managers/minigames/GamblingManager.cpp \
				server/zone/managers/minigames/ForageManager.cpp \
				server/zone/objects/tangible/weapon/WeaponObject.cpp \
				server/zone/managers/crafting/CraftingManager.cpp \
				server/zone/managers/loot/LootManager.cpp \
				server/zone/managers/loot/lootgroup/LootGroupObject.cpp \
				server/zone/managers/loot/lootgroup/LootObject.cpp \
				server/zone/managers/crafting/schematicmap/SchematicMap.cpp \
				server/zone/managers/structure/StructureManager.cpp \
				server/zone/managers/weather/WeatherManager.cpp \
				server/zone/managers/city/CityManager.cpp \
				server/zone/managers/planet/PlanetManager.cpp \
				server/zone/managers/radial/RadialManager.cpp \
				server/zone/managers/resource/ResourceManager.cpp \
				server/zone/managers/creature/CreatureManager.cpp \
				server/zone/managers/auction/AuctionManager.cpp \
				server/zone/managers/auction/AuctionsMap.cpp \
				server/zone/managers/mission/MissionManager.cpp \
				server/zone/managers/vendor/VendorManager.cpp \
				server/zone/objects/resource/ResourceContainer.cpp \
				server/zone/objects/tangible/component/Component.cpp \
				server/zone/objects/tangible/component/armor/ArmorComponent.cpp \
				server/zone/objects/tangible/tool/CraftingTool.cpp \
				server/zone/objects/tangible/tool/CraftingStation.cpp \
				server/zone/objects/tangible/tool/ToolTangibleObject.cpp \
				server/zone/objects/tangible/tool/smuggler/SlicingTool.cpp \
				server/zone/objects/tangible/tool/smuggler/PrecisionLaserKnife.cpp \
				server/zone/objects/tangible/tool/SurveyTool.cpp \
				server/zone/objects/tangible/wearables/WearableObject.cpp \
				server/zone/objects/tangible/wearables/ClothingObject.cpp \
				server/zone/objects/tangible/wearables/ArmorObject.cpp \
				server/zone/objects/tangible/wearables/PsgArmorObject.cpp \
				server/zone/objects/tangible/attachment/Attachment.cpp \
				server/zone/objects/tangible/deed/Deed.cpp \
				server/zone/objects/tangible/deed/vehicle/VehicleDeed.cpp \
				server/zone/objects/tangible/deed/building/BuildingDeed.cpp \
				server/zone/objects/tangible/deed/installation/InstallationDeed.cpp \
				server/zone/objects/tangible/deed/resource/ResourceDeed.cpp \
				server/zone/objects/tangible/sign/SignObject.cpp \
				server/zone/objects/tangible/terminal/Terminal.cpp \
				server/zone/objects/tangible/lair/LairObject.cpp \
				server/zone/objects/tangible/terminal/bank/BankTerminal.cpp \
				server/zone/objects/tangible/terminal/city/CityTerminal.cpp \
				server/zone/objects/tangible/terminal/city/CityVoteTerminal.cpp \
				server/zone/objects/tangible/terminal/guild/GuildTerminal.cpp \
				server/zone/objects/tangible/terminal/mission/MissionTerminal.cpp \
				server/zone/objects/tangible/terminal/vendor/VendorTerminal.cpp \
				server/zone/objects/tangible/terminal/vendor/bazaar/BazaarTerminal.cpp \
				server/zone/objects/auction/AuctionItem.cpp \
				server/zone/objects/auction/Vendor.cpp \
				server/zone/objects/auction/events/VendorCheckTask.cpp \
				server/zone/objects/tangible/terminal/elevator/ElevatorTerminal.cpp \
				server/zone/objects/tangible/terminal/structure/StructureTerminal.cpp \
				server/zone/objects/tangible/terminal/travel/TravelTerminal.cpp \
				server/zone/objects/tangible/terminal/gambling/GamblingTerminal.cpp \
				server/zone/objects/tangible/terminal/cloning/CloningTerminal.cpp \
				server/zone/objects/mission/MissionObject.cpp \
				server/zone/objects/mission/MissionObjective.cpp \
				server/zone/objects/mission/SurveyMissionObjective.cpp \
				server/zone/objects/mission/DestroyMissionObjective.cpp \
				server/zone/objects/mission/DeliverMissionObjective.cpp \
				server/zone/objects/mission/BountyMissionObjective.cpp \
				server/zone/objects/mission/CraftingMissionObjective.cpp \
				server/zone/objects/mission/EntertainerMissionObjective.cpp \
				server/zone/objects/mission/HuntingMissionObjective.cpp \
				server/zone/objects/mission/ReconMissionObjective.cpp \
				server/zone/objects/mission/MissionObserver.cpp \
				server/zone/objects/tangible/terminal/startinglocation/StartingLocationTerminal.cpp \
				server/zone/objects/tangible/terminal/ticketcollector/TicketCollector.cpp \
				server/zone/objects/tangible/ticket/TicketObject.cpp \
				server/zone/objects/tangible/terminal/characterbuilder/CharacterBuilderTerminal.cpp
				
core3_SOURCES =	$(core3_IDLS) \
		tre3/TreeFile.cpp \
		server/zone/managers/vendor/VendorOutfitManager.cpp \
		server/conf/ConfigManager.cpp \
		server/features/Features.cpp \
		server/db/ServerDatabase.cpp \
		server/db/MantisDatabase.cpp \
		server/login/LoginProcessServerImplementation.cpp \
		server/login/LoginPacketHandler.cpp \
		server/login/LoginServerImplementation.cpp \
		server/login/account/AccountManager.cpp \
		server/ping/PingServer.cpp \
		server/status/StatusServer.cpp \
		server/ServerCore.cpp \
		server/zone/ZoneServerImplementation.cpp \
		server/zone/ZoneClientSessionImplementation.cpp \
		server/zone/ZonePacketHandler.cpp \
		server/zone/ZoneProcessServerImplementation.cpp \
		server/zone/ZoneImplementation.cpp \
		server/zone/managers/crafting/CraftingManagerImplementation.cpp \
		server/zone/managers/loot/LootManagerImplementation.cpp \
		server/zone/managers/loot/lootgroup/LootGroupObjectImplementation.cpp \
		server/zone/managers/faction/FactionManager.cpp \
		server/zone/managers/faction/FactionMap.cpp \
		server/zone/managers/planet/HeightMap.cpp \
		server/zone/managers/object/ObjectManager.cpp \
		server/zone/managers/object/ObjectVersionUpdateManager.cpp \
		server/zone/managers/object/UpdateModifiedObjectsThread.cpp \
		server/zone/managers/planet/PlanetManagerImplementation.cpp \
		server/zone/managers/planet/MapLocationTable.cpp \
		server/zone/managers/planet/MapLocationEntry.cpp \
		server/zone/managers/player/PlayerManagerImplementation.cpp \
		server/zone/managers/collision/PathFinderManager.cpp \
		server/zone/managers/collision/CollisionManager.cpp \
		server/zone/managers/guild/GuildManagerImplementation.cpp \
		server/zone/objects/guild/GuildMemberInfo.cpp \
		server/zone/managers/holocron/HolocronManager.cpp \
		server/zone/managers/name/NameManager.cpp \
		server/zone/managers/group/GroupManager.cpp \
		server/zone/managers/professions/ProfessionManager.cpp \
		server/zone/managers/professions/PerformanceManager.cpp \
		server/zone/managers/professions/imagedesign/ImageDesignManager.cpp \
		server/zone/managers/sui/SuiManager.cpp \
		server/zone/managers/auction/AuctionManagerImplementation.cpp \
		server/zone/managers/minigames/FishingManagerImplementation.cpp \
		server/zone/managers/minigames/GamblingManagerImplementation.cpp \
		server/zone/managers/minigames/ForageManagerImplementation.cpp \
		server/zone/managers/minigames/events/ForageCleanupEvent.cpp \
		server/zone/managers/resource/resourcespawner/ResourceSpawner.cpp \
		server/zone/managers/resource/resourcespawner/resourcetree/ResourceTree.cpp \
		server/zone/managers/resource/resourcespawner/resourcetree/ResourceTreeNode.cpp \
		server/zone/managers/resource/resourcespawner/resourcemap/ResourceMap.cpp \
		server/zone/managers/resource/resourcespawner/resourcepool/MinimumPool.cpp \
		server/zone/managers/resource/resourcespawner/resourcepool/RandomPool.cpp \
		server/zone/managers/resource/resourcespawner/resourcepool/FixedPool.cpp \
		server/zone/managers/resource/resourcespawner/resourcepool/NativePool.cpp \
		server/zone/managers/resource/resourcespawner/resourcepool/ManualPool.cpp \
		server/zone/objects/draftschematic/DraftSchematicImplementation.cpp \
		server/zone/objects/factorycrate/FactoryCrateImplementation.cpp \
		server/zone/objects/manufactureschematic/ManufactureSchematicImplementation.cpp \
		server/zone/objects/scene/SceneObjectImplementation.cpp \
		server/zone/objects/scene/WorldCoordinates.cpp \
		server/zone/objects/area/ActiveAreaImplementation.cpp \
		server/zone/objects/area/DynamicSpawnAreaImplementation.cpp \
		server/zone/objects/area/StaticSpawnAreaImplementation.cpp \
		server/zone/objects/region/RegionImplementation.cpp \
		server/zone/objects/terrain/ProceduralTerrainAppearance.cpp \
		server/zone/objects/terrain/MapFractal.cpp \
		server/zone/objects/terrain/TerrainGenerator.cpp \
		server/zone/objects/terrain/layer/Layer.cpp \
		server/zone/objects/terrain/layer/affectors/AffectorHeightFractal.cpp \
		server/zone/objects/terrain/layer/filters/FilterFractal.cpp \
		server/zone/objects/intangible/IntangibleObjectImplementation.cpp \
		server/zone/objects/staticobject/StaticObjectImplementation.cpp \
		server/zone/objects/intangible/VehicleControlDeviceImplementation.cpp \
		server/zone/objects/tangible/TangibleObjectImplementation.cpp \
		server/zone/objects/tangible/InstrumentImplementation.cpp \
		server/zone/objects/tangible/InstrumentObserverImplementation.cpp \
		server/zone/objects/tangible/ContainerImplementation.cpp \
		server/zone/objects/tangible/fishing/FishingPoleObjectImplementation.cpp \
		server/zone/objects/tangible/fishing/FishingBaitObjectImplementation.cpp \
		server/zone/objects/tangible/fishing/FishObjectImplementation.cpp \
		server/zone/objects/tangible/firework/FireworkObjectImplementation.cpp \
		server/zone/objects/tangible/loot/LootkitObjectImplementation.cpp \
		server/zone/objects/tangible/terminal/vendor/VendorTerminalImplementation.cpp \
		server/zone/objects/tangible/terminal/vendor/bazaar/BazaarTerminalImplementation.cpp \
		server/zone/objects/auction/AuctionItemImplementation.cpp \
		server/zone/objects/tangible/terminal/city/CityTerminalImplementation.cpp \
		server/zone/objects/tangible/terminal/city/CityVoteTerminalImplementation.cpp \
		server/zone/objects/tangible/terminal/guild/GuildTerminalImplementation.cpp \
		server/zone/objects/tangible/terminal/gambling/GamblingTerminalImplementation.cpp \
		server/zone/objects/tangible/terminal/elevator/ElevatorTerminalImplementation.cpp \
		server/zone/objects/tangible/terminal/structure/StructureTerminalImplementation.cpp \
		server/zone/objects/tangible/terminal/cloning/CloningTerminalImplementation.cpp \
		server/zone/objects/tangible/consumable/ConsumableImplementation.cpp \
		server/zone/objects/tangible/deed/DeedImplementation.cpp \
		server/zone/objects/tangible/deed/vehicle/VehicleDeedImplementation.cpp \
		server/zone/objects/tangible/deed/building/BuildingDeedImplementation.cpp \
		server/zone/objects/tangible/deed/installation/InstallationDeedImplementation.cpp \
		server/zone/objects/tangible/deed/resource/ResourceDeedImplementation.cpp \
		server/zone/objects/tangible/sign/SignObjectImplementation.cpp \
		server/zone/objects/installation/factory/FactoryObjectImplementation.cpp \
		server/zone/objects/installation/shuttle/ShuttleInstallationImplementation.cpp \
		server/zone/objects/installation/garage/GarageInstallationImplementation.cpp \
		server/zone/objects/installation/harvester/HarvesterObjectImplementation.cpp \
		server/zone/objects/installation/generator/GeneratorObjectImplementation.cpp \
		server/zone/objects/tangible/component/ComponentImplementation.cpp \
		server/zone/objects/tangible/component/armor/ArmorComponentImplementation.cpp \
		server/zone/objects/tangible/tool/SurveyToolImplementation.cpp \
		server/zone/objects/tangible/tool/CraftingToolImplementation.cpp \
		server/zone/objects/tangible/tool/CraftingStationImplementation.cpp \
		server/zone/objects/tangible/tool/smuggler/SlicingToolImplementation.cpp \
		server/zone/objects/tangible/tool/smuggler/PrecisionLaserKnifeImplementation.cpp \
		server/zone/objects/group/GroupObjectImplementation.cpp \
		server/zone/objects/guild/GuildObjectImplementation.cpp \
		server/zone/objects/creature/CreatureObjectImplementation.cpp \
		server/zone/objects/creature/CreatureImplementation.cpp \
		server/zone/objects/creature/NonPlayerCreatureObjectImplementation.cpp \
		server/zone/objects/creature/AiAgentImplementation.cpp \
		server/zone/objects/tangible/DamageMap.cpp \
		server/zone/objects/creature/damageovertime/DamageOverTime.cpp \
		server/zone/objects/creature/damageovertime/DamageOverTimeList.cpp \
		server/zone/objects/creature/buffs/BuffImplementation.cpp \
		server/zone/objects/creature/buffs/SpiceBuffImplementation.cpp \
		server/zone/objects/creature/buffs/PowerBoostBuffImplementation.cpp \
		server/zone/objects/creature/buffs/BuffList.cpp \
		server/zone/objects/creature/commands/sui/FindCommandSuiCallback.cpp \
		server/zone/objects/creature/vendor/VendorCreatureImplementation.cpp \
		server/zone/objects/creature/trainer/TrainerCreatureImplementation.cpp \
		server/zone/objects/creature/informant/InformantCreatureImplementation.cpp \
		server/zone/objects/creature/junkdealer/JunkdealerCreatureImplementation.cpp \
		server/zone/objects/creature/variables/CommandQueueAction.cpp \
		server/zone/objects/creature/commands/QueueCommand.cpp \
		server/zone/objects/creature/LuaCreatureObject.cpp \
		server/zone/objects/creature/VehicleObjectImplementation.cpp \
		server/zone/objects/creature/shuttle/ShuttleCreatureImplementation.cpp \
		server/zone/objects/creature/variables/SkillBoxList.cpp \
		server/zone/objects/creature/aigroup/AiGroupImplementation.cpp \
		server/zone/objects/creature/aigroup/HerdGroupImplementation.cpp \
		server/zone/objects/creature/aigroup/LairGroupImplementation.cpp \
		server/zone/objects/creature/aigroup/PackGroupImplementation.cpp \
		server/zone/objects/player/PlayerObjectImplementation.cpp \
		server/zone/objects/player/variables/SkillList.cpp \
		server/zone/objects/player/variables/SchematicList.cpp \
		server/zone/objects/resource/ResourceSpawnImplementation.cpp \
		server/zone/objects/resource/simplexnoise/SimplexNoise.cpp \
		server/zone/objects/resource/ResourceContainerImplementation.cpp \
		server/zone/objects/scene/variables/StringId.cpp \
		server/zone/objects/scene/variables/StringIdParameter.cpp \
		server/zone/objects/scene/variables/CustomizationVariables.cpp \
		server/zone/objects/cell/CellObjectImplementation.cpp \
		server/zone/objects/installation/InstallationObjectImplementation.cpp \
		server/zone/objects/building/BuildingObjectImplementation.cpp \
		server/zone/objects/building/tutorial/TutorialBuildingObjectImplementation.cpp \
		server/zone/objects/building/city/CityHallObjectImplementation.cpp \
		server/zone/objects/structure/StructurePermissionList.cpp \
		server/zone/objects/player/PlayerCreatureImplementation.cpp \
		server/zone/objects/player/ValidatedPosition.cpp \
		server/zone/objects/player/sessions/EntertainingSessionImplementation.cpp \
		server/zone/objects/player/sessions/ImageDesignSessionImplementation.cpp \
		server/zone/objects/player/sessions/SlicingSessionImplementation.cpp \
		server/zone/objects/player/sessions/vendor/CreateVendorSessionImplementation.cpp \
		server/zone/objects/player/sui/SuiBoxImplementation.cpp \
		server/zone/objects/player/sui/inputbox/SuiInputBoxImplementation.cpp \
		server/zone/objects/player/sui/listbox/SuiListBoxImplementation.cpp \
		server/zone/objects/player/sui/listbox/teachplayerlistbox/TeachPlayerListBoxImplementation.cpp \
		server/zone/objects/player/sui/listbox/resourcedeedlistbox/ResourceDeedListBoxImplementation.cpp \
		server/zone/objects/player/sui/listbox/playerlearnlistbox/PlayerLearnListBoxImplementation.cpp \
		server/zone/objects/player/sui/messagebox/SuiMessageBoxImplementation.cpp \
		server/zone/objects/player/sui/characterbuilderbox/SuiCharacterBuilderBoxImplementation.cpp \
		server/zone/objects/player/badges/Badge.cpp \
		server/zone/objects/player/sui/banktransferbox/SuiBankTransferBoxImplementation.cpp \
		server/zone/objects/player/sui/transferbox/SuiTransferBoxImplementation.cpp \
		server/zone/packets/charcreation/ClientCreateCharacterCallback.cpp \
		server/zone/packets/object/ObjectControllerMessageCallback.cpp \
		server/chat/room/ChatRoomImplementation.cpp \
		server/chat/ChatManagerImplementation.cpp \
		server/chat/PersistentMessageImplementation.cpp \
		server/chat/ChatParameter.cpp \
		server/chat/StringIdChatParameter.cpp \
		server/chat/WaypointChatParameter.cpp \
		server/zone/managers/objectcontroller/ObjectControllerImplementation.cpp \
		server/zone/managers/objectcontroller/command/CommandConfigManager.cpp \
		server/zone/managers/terrain/TerrainManager.cpp \
		server/zone/managers/templates/TemplateManager.cpp \
		server/zone/managers/mission/MissionManagerImplementation.cpp \
		server/zone/objects/waypoint/WaypointObjectImplementation.cpp \
		server/zone/objects/tangible/weapon/WeaponObjectImplementation.cpp \
		server/zone/managers/structure/StructureManagerImplementation.cpp \
		server/zone/managers/weather/WeatherManagerImplementation.cpp \
		server/zone/managers/city/CityManagerImplementation.cpp \
		server/zone/objects/structure/StructureObjectImplementation.cpp \
		server/zone/objects/tangible/wearables/WearableObjectImplementation.cpp \
		server/zone/objects/tangible/wearables/ArmorObjectImplementation.cpp \
		server/zone/objects/tangible/wearables/PsgArmorObjectImplementation.cpp \
		server/zone/objects/tangible/attachment/AttachmentImplementation.cpp \
		server/zone/objects/tangible/terminal/TerminalImplementation.cpp \
		server/zone/objects/tangible/lair/LairObjectImplementation.cpp \
		server/zone/objects/tangible/terminal/startinglocation/StartingLocationTerminalImplementation.cpp \
		server/zone/objects/tangible/terminal/characterbuilder/CharacterBuilderTerminalImplementation.cpp \
		server/zone/objects/tangible/terminal/mission/MissionTerminalImplementation.cpp \
		server/zone/objects/tangible/terminal/ticketcollector/TicketCollectorImplementation.cpp \
		server/zone/objects/tangible/terminal/travel/TravelTerminalImplementation.cpp \
		server/zone/objects/tangible/ticket/TicketObjectImplementation.cpp \
		server/zone/managers/radial/RadialManagerImplementation.cpp \
		server/zone/managers/resource/ResourceManagerImplementation.cpp \
		server/zone/managers/creature/CreatureManagerImplementation.cpp \
		server/zone/managers/combat/CombatManager.cpp \
		server/zone/managers/combat/CreatureAttackData.cpp \
		server/zone/objects/mission/MissionObjectImplementation.cpp \
		server/zone/objects/mission/MissionObjectiveImplementation.cpp \
		server/zone/objects/mission/SurveyMissionObjectiveImplementation.cpp \
		server/zone/objects/mission/DestroyMissionObjectiveImplementation.cpp \
		server/zone/objects/mission/DeliverMissionObjectiveImplementation.cpp \
		server/zone/objects/mission/BountyMissionObjectiveImplementation.cpp \
		server/zone/objects/mission/CraftingMissionObjectiveImplementation.cpp \
		server/zone/objects/mission/EntertainerMissionObjectiveImplementation.cpp \
		server/zone/objects/mission/HuntingMissionObjectiveImplementation.cpp \
		server/zone/objects/mission/ReconMissionObjectiveImplementation.cpp \
		server/zone/objects/mission/MissionObserverImplementation.cpp \
		server/zone/templates/datatables/DataTableIff.cpp \
		server/zone/templates/snapshot/WorldSnapshotIff.cpp \
		server/zone/templates/SharedTangibleObjectTemplate.cpp \
		server/zone/templates/appearance/FloorMesh.cpp \
		server/zone/templates/appearance/MeshAppearanceTemplate.cpp \
		server/zone/templates/appearance/DetailAppearanceTemplate.cpp \
		server/zone/templates/appearance/PortalLayout.cpp \
		server/zone/templates/appearance/PathGraph.cpp \
		server/zone/templates/intangible/DraftSchematicObjectTemplate.cpp \
		server/zone/templates/SharedObjectTemplate.cpp \
		server/zone/templates/tangible/SharedBuildingObjectTemplate.cpp \
		server/zone/templates/tangible/SharedStructureObjectTemplate.cpp \
		server/zone/templates/tangible/SharedCreatureObjectTemplate.cpp \
		server/zone/templates/tangible/SharedWeaponObjectTemplate.cpp \
		server/zone/templates/customization/AssetCustomizationManagerTemplate.cpp \
		main.cpp