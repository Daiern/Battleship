// Fill out your copyright notice in the Description page of Project Settings.

#include "Battleship.h"
#include "MapTile.h"
#include "BSPlayerController.h"


ABSPlayerController::ABSPlayerController() {
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;

	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//set current placement to zero to avoid problems due to it being null at start of game
	FCurrentPlacementPosition = FVector(0, 0, 0);
}

void ABSPlayerController::Tick(float DeltaSeconds) {
	Super::Tick(DeltaSeconds);

	if (UCurrentGameMode->getPlayState() == EPlayState::PS_Placement) {
		GetTileUnderCursor();
	}
	
}

void ABSPlayerController::BeginPlay() {
	UCurrentGameMode = Cast<ABattleshipGameMode>(GetWorld()->GetAuthGameMode());
}

void ABSPlayerController::GetTileUnderCursor() {
	//Trace to see if anything is behind the mouse cursor
	FHitResult Hit;
	GetHitResultUnderCursor(ECC_WorldStatic, false, Hit);

	if (Hit.bBlockingHit)
	{
		AMapTile* HoveredTile = Cast<AMapTile>(Hit.GetActor());
		if (HoveredTile) {
			if (FCurrentPlacementPosition != HoveredTile->GetActorTransform().GetLocation()){
				FCurrentPlacementPosition = HoveredTile->GetActorTransform().GetLocation();
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, HoveredTile->GetName());
			}
		}
	}
}