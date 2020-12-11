// Fill out your copyright notice in the Description page of Project Settings.


#include "BatteryMan_GameMode.h"
#include "GameFramework/Actor.h"

ABatteryMan_GameMode::ABatteryMan_GameMode()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ABatteryMan_GameMode::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle UnusedHandle;
	GetWorldTimerManager().SetTimer(
		UnusedHandle, this, &ABatteryMan_GameMode::SpawnRecharge, FMath::FRandRange(2, 5), true
	);
}

void ABatteryMan_GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABatteryMan_GameMode::SpawnRecharge()
{
	float RandX = FMath::FRandRange(SpawnXMin, SpawnXMax);
	float RandY = FMath::FRandRange(SpawnYMin, SpawnYMax);

	FVector SpawnPosition = FVector(RandX, RandY, SpawnZ);
	FRotator SpawnRotation = FRotator(0.0f, 0.0f, 0.0f);

	GetWorld()->SpawnActor(Recharge, &SpawnPosition, &SpawnRotation);
}

