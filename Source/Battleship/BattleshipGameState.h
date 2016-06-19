// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameState.h"
#include "BattleshipGameState.generated.h"

/**
 * 
 */

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class EPlayState : uint8
{
	PS_Placement 	UMETA(DisplayName = "Placement Mode"),
	PS_Playing 	UMETA(DisplayName = "Play Mode"),
	PS_Finished	UMETA(DisplayName = "Finish")
};

UCLASS()
class BATTLESHIP_API ABattleshipGameState : public AGameState
{
	GENERATED_BODY()
	
	
	
	
};
