Route22_NorthEntrance_MapScripts::
	.byte 0

Route22_NorthEntrance_EventScript_BoulderBadgeGuard::
	lock
	faceplayer
	setvar VAR_TEMP_1, 8
	bufferstdstring STR_VAR_1, STDSTRING_BOULDER_BADGE
	goto Route23_EventScript_BadgeGuard
	end

Route22_NorthEntrance_EventScript_BoulderBadgeGuardTrigger::
	lockall
	setvar VAR_TEMP_1, 8
	setvar VAR_0x8009, 1
	bufferstdstring STR_VAR_1, STDSTRING_BOULDER_BADGE
	goto Route23_EventScript_BadgeGuardTrigger
	end
	
Route23_EventScript_MissingChamp::
	message Text_OnlyPassWithChampDontHaveYet
	waitmessage
	playse SE_BOO
	waitbuttonpress
	closemessage
	waitse
	release
	end

Route23_EventScript_AlreadyRecognizedChampion::
	message Text_OhThatsChampGoRightAhead
	waitmessage
	playfanfare MUS_LEVEL_UP
	waitfanfare
	waitbuttonpress
	release
	end

Route23_EventScript_MtSilverGuard::
	goto_if_ge VAR_MAP_SCENE_ROUTE23, Route23_EventScript_CheckChampion, Route23_EventScript_AlreadyRecognizedChampion
	end

Route23_EventScript_CheckChampion::
	goto_if_set FLAG_BECAME_LEAGUE_CHAMPION, Route23_EventScript_RecognizeChampion
	goto Route23_EventScript_MissingChamp
	end


Route23_EventScript_ChampGuardTrigger::
	textcolor NPC_TEXT_COLOR_MALE
	applymovement VAR_0x8009, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	goto Route23_EventScript_CheckChampTrigger
	end

Route23_EventScript_CheckChampTrigger::
	goto_if_set FLAG_BECAME_LEAGUE_CHAMPION, Route23_EventScript_RecognizeChampionTrigger
	goto Route23_EventScript_MissingChampTrigger
	end

Route23_EventScript_MissingChampTrigger::
	msgbox Text_OnlyPassWithChampDontHaveYet
	playse SE_BOO
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route23_Movement_WalkDown
	applymovement VAR_0x8009, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	releaseall
	end

Route23_EventScript_RecognizeChampionTrigger::
	message Text_OhThatsChampGoRightAhead
	waitmessage
	playfanfare MUS_LEVEL_UP
	waitfanfare
	waitbuttonpress
	copyvar VAR_MAP_SCENE_ROUTE23, VAR_TEMP_1
	releaseall
	end