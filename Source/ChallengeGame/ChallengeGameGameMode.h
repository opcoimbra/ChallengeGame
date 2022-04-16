// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "ChallengeGameGameMode.generated.h"

UCLASS(minimalapi)
class AChallengeGameGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	AChallengeGameGameMode();

	UFUNCTION()
		void MyRestartGame();
};



