RocketHideout_Elevator_MapScripts::
	.byte 0

RocketHideout_Elevator_EventScript_FloorSelect::
	lockall
	goto_if_unset FLAG_CAN_USE_ROCKET_HIDEOUT_LIFT, RocketHideout_Elevator_EventScript_NeedKey
	setvar VAR_0x8004, 2
	call_if_unset FLAG_TEMP_2, EventScript_GetElevatorFloor
	copyvar VAR_0x8005, VAR_ELEVATOR_FLOOR
	special DrawElevatorCurrentFloorWindow
	message Text_WantWhichFloor
	waitmessage
	setvar VAR_0x8004, 2
	specialvar VAR_RESULT, InitElevatorFloorSelectMenuPos
	switch VAR_RESULT
	case 0, RocketHideout_Elevator_EventScript_FloorSelectFromB1F
	case 1, RocketHideout_Elevator_EventScript_FloorSelectFromB4F
	end

RocketHideout_Elevator_EventScript_FloorSelectFromB1F::
	multichoicedefault 0, 0, MULTICHOICE_ROCKET_HIDEOUT_ELEVATOR, 0, FALSE
	goto RocketHideout_Elevator_EventScript_ChooseFloor
	end
RocketHideout_Elevator_EventScript_FloorSelectFromB4F::
	multichoicedefault 0, 0, MULTICHOICE_ROCKET_HIDEOUT_ELEVATOR, 1, FALSE
	goto RocketHideout_Elevator_EventScript_ChooseFloor
	end

RocketHideout_Elevator_EventScript_ChooseFloor::
	switch VAR_RESULT
	case 0, RocketHideout_Elevator_EventScript_ToB1F
	case 1, RocketHideout_Elevator_EventScript_ToB4F
	case 127, RocketHideout_Elevator_EventScript_ExitFloorSelect
	end

RocketHideout_Elevator_EventScript_ToB1F::
	setvar VAR_0x8006, 0
	setdynamicwarp MAP_ROCKET_HIDEOUT_B1F, 255, 13, 8
	goto_if_eq VAR_ELEVATOR_FLOOR, 0, RocketHideout_Elevator_EventScript_ExitFloorSelect
	call RocketHideout_Elevator_EventScript_MoveElevator
	setvar VAR_ELEVATOR_FLOOR, 0
	goto RocketHideout_Elevator_EventScript_ExitFloorSelect
	end


RocketHideout_Elevator_EventScript_ToB4F::
	setvar VAR_0x8006, 1
	setdynamicwarp MAP_ROCKET_HIDEOUT_B4F, 255, 20, 23
	goto_if_eq VAR_ELEVATOR_FLOOR, 1, RocketHideout_Elevator_EventScript_ExitFloorSelect
	call RocketHideout_Elevator_EventScript_MoveElevator
	setvar VAR_ELEVATOR_FLOOR, 1
	goto RocketHideout_Elevator_EventScript_ExitFloorSelect
	end

RocketHideout_Elevator_EventScript_ExitFloorSelect::
	special CloseElevatorCurrentFloorWindow
	releaseall
	end

RocketHideout_Elevator_EventScript_MoveElevator::
	special CloseElevatorCurrentFloorWindow
	closemessage
	waitse
	special AnimateElevator
	waitstate
	setflag FLAG_TEMP_2
	return

RocketHideout_Elevator_EventScript_NeedKey::
	msgbox RocketHideout_Elevator_Text_AppearsToNeedAKey
	releaseall
	end
