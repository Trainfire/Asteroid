// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerShip.h"

// Sets default values
APlayerShip::APlayerShip()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SetRootComponent(RootComponent);

	MyArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("ShipCameraSpringArm"));
	MyArmComponent->SetupAttachment(RootComponent);
	MyArmComponent->bUsePawnControlRotation = false;

	MyCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("ShipCamera"));
	MyCameraComponent->SetupAttachment(MyArmComponent, USpringArmComponent::SocketName);

	MyMovementComponent = CreateDefaultSubobject<UPlayerShipPawnMovementComponent>(TEXT("Movement"));
	MyMovementComponent->UpdatedComponent = RootComponent;
}

// Called when the game starts or when spawned
void APlayerShip::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APlayerShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (MyArmComponent)
	{
		MyArmComponent->SetWorldRotation(MyCameraRotation);
		MyArmComponent->SetRelativeLocation(MyCameraOffset);
	}

	if (MyMovementComponent)
		MyMovementComponent->SetMovementSpeed(MyMovementSpeed);

	const FVector& start = GetActorLocation();
	DrawDebugLine(GetWorld(), GetActorLocation(), start + (GetActorForwardVector() * 200.0f), FColor::Red, false, -1.0f, 0, 2.0f);
	DrawDebugSphere(GetWorld(), start, 32, 32, FColor::Red);
}

UPlayerShipPawnMovementComponent * APlayerShip::GetMovementComponent() const
{
	return MyMovementComponent;
}

void APlayerShip::MoveForward(float Value)
{
	if (MyMovementComponent && (MyMovementComponent->UpdatedComponent == RootComponent))
		MyMovementComponent->AddInputVector(GetActorForwardVector() * Value);
}

void APlayerShip::MoveRight(float Value)
{
	FRotator rotation = GetActorRotation();
	rotation.Yaw += Value * MyTurnSpeed;
	SetActorRotation(rotation);
}

