// Fill out your copyright notice in the Description page of Project Settings.

#include "Battleship.h"
#include "BSPlayerController.h"
#include "BattleshipGameMode.h"

ABattleshipGameMode::ABattleshipGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ABSPlayerController::StaticClass();
	GameStateClass = ABattleshipGameState::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/BP_PlayerPawn"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	static ConstructorHelpers::FClassFinder<AHUD> BattleshipHUDBPClass(TEXT("/Game/Blueprints/BP_BattleShipHUD"));
	if (BattleshipHUDBPClass.Class != NULL)
	{
		HUDClass = BattleshipHUDBPClass.Class;
	}

	ePlayState = EPlayState::PS_Placement;


}