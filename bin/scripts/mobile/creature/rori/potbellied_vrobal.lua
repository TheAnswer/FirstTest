potbellied_vrobal = Creature:new {
	objectName = "@mob/creature_names:potbellied_vrobal",
	socialGroup = "Vrobal",
	pvpFaction = "",
	faction = "",
	level = 12,
	chanceHit = 0.290000,
	damageMin = 130,
	damageMax = 140,
	baseXp = 430,
	baseHAM = 1300,
	baseHAMmax = 1300,
	armor = 0,
	resists = {0,0,0,10,0,0,0,-1,-1},
	meatType = "meat_carnivore",
	meatAmount = 10,
	hideType = "hide_leathery",
	hideAmount = 15,
	boneType = "bone_mammal",
	boneAmount = 10,
	milk = 0,
	tamingChance = 0.250000,
	ferocity = 0,
	pvpBitmask = ATTACKABLE,
	creatureBitmask = NONE,
	diet = CARNIVORE,

	templates = {"object/mobile/vrobal.iff"},
	lootgroups = {},
	weapons = {},
	attacks = {}
}

CreatureTemplates:addCreatureTemplate(potbellied_vrobal, "potbellied_vrobal")