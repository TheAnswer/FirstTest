rebel_gungan_captain = Creature:new {
	objectName = "Rebel Gungan Captain",
	socialGroup = "Rebel",
	pvpFaction = "Rebel",
	faction = "",
	level = 21,
	chanceHit = 0.340000,
	damageMin = 200,
	damageMax = 210,
	baseXp = 2006,
	baseHAM = 5400,
	baseHAMmax = 6600,
	armor = 0,
	resists = {0,0,0,-1,30,-1,-1,-1,-1},
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
	creatureBitmask = PACK + KILLER,
	diet = HERBIVORE,

	templates = {},
	lootgroups = {},
	weapons = {"rebel_weapons_medium"},
	attacks = {}
}

CreatureTemplates:addCreatureTemplate(rebel_gungan_captain, "rebel_gungan_captain")