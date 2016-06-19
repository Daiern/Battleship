// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "BattleshipGameState.h"
#include "BattleshipGameMode.generated.h"

/**
 * 
 */

UCLASS()
class BATTLESHIP_API ABattleshipGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	ABattleshipGameMode();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Play State")
	EPlayState ePlayState;

	UFUNCTION(BlueprintCallable, Category = "Play State")
	EPlayState getPlayState() { return ePlayState; }

	UFUNCTION(BlueprintCallable, Category = "Play State")
	void setPlayState(EPlayState newState) { ePlayState = newState; }
	
};
