// Fill out your copyright notice in the Description page of Project Settings.

#include "PawnTurret.h"
#include "PawnTank.h"
#include "Kismet/GameplayStatics.h"

APawnTurret::APawnTurret()
{
	PrimaryActorTick.bCanEverTick = true;
}

void APawnTurret::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);

	PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
}

// Called every frame
void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APawnTurret::CheckFireCondition()
{
	if (!PlayerPawn) { return; }
	if (ReturnDistanceToPlayer() <= FireRange)
	{
		// Fire!
		UE_LOG(LogTemp, Warning, TEXT("Fire condition met!"));
	}
}

float APawnTurret::ReturnDistanceToPlayer() const
{
	if (!PlayerPawn) { return 0.0f; }
	return FVector::Dist(PlayerPawn->GetActorLocation(), GetActorLocation());
}
