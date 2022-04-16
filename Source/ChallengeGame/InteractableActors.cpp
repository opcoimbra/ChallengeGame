// Fill out your copyright notice in the Description page of Project Settings.


#include "Kismet/GameplayStatics.h"
#include "ChallengeGameGameMode.h"
#include "InteractableActors.h"

// Sets default values
AInteractableActors::AInteractableActors()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = StaticMesh;

}

// Called when the game starts or when spawned
void AInteractableActors::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInteractableActors::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AInteractableActors::OnInteraction_Implementation(AActor* Caller)
{
	Destroy();
	AChallengeGameGameMode* ChallengeGameMode = Cast<AChallengeGameGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	if (ChallengeGameMode)
	{
		ChallengeGameMode->MyRestartGame();
	}
}


