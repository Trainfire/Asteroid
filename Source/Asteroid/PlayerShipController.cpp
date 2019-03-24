// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerShipController.h"

void APlayerShipController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveForward", this, &APlayerShipController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &APlayerShipController::MoveRight);
}

void APlayerShipController::SetPawn(APawn * InPawn)
{
	Super::SetPawn(InPawn);

	if (InPawn)
	{
		APlayerShip* playerShip = Cast<APlayerShip>(InPawn);
		if (playerShip)
			myPlayerShip = playerShip;
	}
}

void APlayerShipController::MoveForward(float Value)
{
	if (myPlayerShip)
		myPlayerShip->MoveForward(Value);
}

void APlayerShipController::MoveRight(float Value)
{
	if (myPlayerShip)
		myPlayerShip->MoveRight(Value);
}