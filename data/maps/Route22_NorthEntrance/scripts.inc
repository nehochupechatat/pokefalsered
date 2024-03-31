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
	goto_if_set FLAG_BECAME_LEAGUE_CHAMPION, Route23_EventScript_AlreadyRecognizedChampion
	goto Route23_EventScript_CheckChampion
	end

Route23_EventScript_CheckChampion::
	goto_if_set FLAG_BECAME_LEAGUE_CHAMPION, Route23_EventScript_RecognizeChampion
	goto Route23_EventScript_MissingChamp
	end


Route23_EventScript_ChampGuardTrigger::
	textcolor NPC_TEXT_COLOR_MALE
	goto Route23_EventScript_CheckChampTrigger
	end

Route23_EventScript_CheckChampTrigger::
	lockall
	goto_if_set FLAG_BECAME_LEAGUE_CHAMPION, Route23_EventScript_RecognizeChampionTrigger
	goto Route23_EventScript_MissingChampTrigger
	end

Route23_EventScript_MissingChampTrigger::
	msgbox Text_OnlyPassWithChampDontHaveYet
	playse SE_BOO
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route23_Movement_WalkUp
	releaseall
	end

Route23_EventScript_RecognizeChampionTrigger::
	message Text_OhThatsChampGoRightAhead
	waitmessage
	playfanfare MUS_LEVEL_UP
	waitfanfare
	waitbuttonpress
	copyvar VAR_MAP_SCENE_ROUTE23, 9
	releaseall
	end
	
Route23_EventScript_RecognizeChampion::
	msgbox Text_OhThatsChampGoRightAhead
	copyvar VAR_MAP_SCENE_ROUTE23, 9
	release
	end

Route23_Movement_WalkUp::
	walk_up
	walk_up
	step_end
