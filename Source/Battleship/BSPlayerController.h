// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "BattleshipGameMode.h"
#include "BSPlayerController.generated.h"



/**
 * 
 */
UCLASS()
class BATTLESHIP_API ABSPlayerController : public APlayerController
{
	GENERATED_BODY()

	ABSPlayerController();

	virtual void Tick(float DeltaSeconds) override;

	virtual void BeginPlay() override;

	ABattleshipGameMode* UCurrentGameMode;
	
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Placement")
	FVector FCurrentPlacementPosition;

	void SetPlacementPosition(FVector placementPos) { FCurrentPlacementPosition = placementPos; }
	FVector GetPlacementPosition() { return FCurrentPlacementPosition; }

	UFUNCTION(BlueprintCallable, Category = "Placement")
	void GetTileUnderCursor();
};
