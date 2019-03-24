// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "PlayerShipPawnMovementComponent.h"
#include "PlayerShip.generated.h"

UCLASS()
class ASTEROID_API APlayerShip : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerShip();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual UPlayerShipPawnMovementComponent* GetMovementComponent() const override;

	UCameraComponent* MyCameraComponent;
	USpringArmComponent* MyArmComponent;
	UPlayerShipPawnMovementComponent* MyMovementComponent;

	void MoveForward(float Value);
	void MoveRight(float Value);

	UPROPERTY(EditAnywhere, Category = Camera)
	FVector MyCameraOffset = FVector(0.0f, 0.0f, 50.0f);

	UPROPERTY(EditAnywhere, Category = Camera)
	FRotator MyCameraRotation = FRotator(-50.0f, 0.0f, 0.0f);

	UPROPERTY(EditAnywhere)
	float MyMovementSpeed;

	UPROPERTY(EditAnywhere)
	float MyTurnSpeed;
};
