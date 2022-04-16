// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractInterface.h"
#include "InteractableActors.generated.h"

UCLASS()
class CHALLENGEGAME_API AInteractableActors : public AActor, public IInteractInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractableActors();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaticMesh")
		UStaticMeshComponent* StaticMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
		void OnInteraction(AActor* Caller); virtual void OnInteraction_Implementation(AActor* Caller) override;

};
