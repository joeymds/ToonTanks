// Copyright 2021 Joey Matos Dos Santos

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TankGameModeBase.generated.h"

UCLASS()
class TOONTANKS_API ATankGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

private:

	void HandleGameStart();
	void HandleGameOver(bool PlayerWon);
	
public:

	void ActorDied(AActor* DeadActor);
	
protected:

	virtual void BeginPlay() override;
	UFUNCTION(BlueprintImplementableEvent)
	void GameState();
	UFUNCTION(BlueprintImplementableEvent)
	void GameOver(bool PlayerWon);
};