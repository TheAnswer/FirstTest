monumenter_bandit = Creature:new {
	objectName = "@mob/creature_names:monumenter_bandit",
	socialGroup = "Monumenter",
	pvpFaction = "Monumenter",
	faction = "monumenter",
	level = 11,
	chanceHit = 0.290000,
	damageMin = 120,
	damageMax = 130,
	baseXp = 430,
	baseHAM = 1000,
	baseHAMmax = 1200,
	armor = 0,
	resists = {0,0,0,0,0,0,0,-1,-1},
	meatType = "",
	meatAmount = 0,
	hideType = "",
	hideAmount = 0,
	boneType = "",
	boneAmount = 0,
	milk = 0,
	tamingChance = 0.000000,
	ferocity = 0,
	pvpBitmask = ATTACKABLE,
	creatureBitmask = PACK,
	diet = HERBIVORE,

	templates = {"object/mobile/dressed_mugger.iff",
		"object/mobile/dressed_crook_zabrak_female_01.iff",
		"object/mobile/dressed_crook_zabrak_male_01.iff",
		"object/mobile/dressed_robber_human_female_01.iff",
		"object/mobile/dressed_robber_human_male_01.iff",
		"object/mobile/dressed_robber_twk_female_01.iff",
		"object/mobile/dressed_robber_twk_male_01.iff",
		"object/mobile/dressed_ruffian_zabrak_female_01.iff",
		"object/mobile/dressed_ruffian_zabrak_male_01.iff"},
	lootGroups = {},
	weapons = {"pirate_weapons_medium"},
	attacks = {}
}

CreatureTemplates:addCreatureTemplate(monumenter_bandit, "monumenter_bandit")
