// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerShip.h"
#include "GameFramework/PlayerController.h"
#include "PlayerShipController.generated.h"

/**
 * 
 */
UCLASS()
class ASTEROID_API APlayerShipController : public APlayerController
{
	GENERATED_BODY()

	APlayerShip* myPlayerShip;

	void SetupInputComponent() override;
	void SetPawn(APawn* InPawn) override;
	void MoveForward(float Value);
	void MoveRight(float Value);
};
