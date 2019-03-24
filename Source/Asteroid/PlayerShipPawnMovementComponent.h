// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PawnMovementComponent.h"
#include "PlayerShipPawnMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class ASTEROID_API UPlayerShipPawnMovementComponent : public UPawnMovementComponent
{
	GENERATED_BODY()

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	float MyMovementSpeed;

public:
	void SetMovementSpeed(float MovementSpeed);
	float GetMovementSpeed();
};
