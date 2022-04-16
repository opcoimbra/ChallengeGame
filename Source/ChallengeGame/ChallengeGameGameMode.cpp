// Copyright Epic Games, Inc. All Rights Reserved.

#include "ChallengeGameGameMode.h"
#include "ChallengeGameCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/Engine.h"


AChallengeGameGameMode::AChallengeGameGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void AChallengeGameGameMode::MyRestartGame()
{
	RestartGame();
}
