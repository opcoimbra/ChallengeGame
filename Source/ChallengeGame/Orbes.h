// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Orbes.generated.h"

UCLASS()
class CHALLENGEGAME_API AOrbes : public AActor
{
	GENERATED_BODY()

	
public:	
	// Sets default values for this actor's properties
	AOrbes();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OrbInfo") 
		UStaticMeshComponent* OrbMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OrbInfo") 
		USphereComponent* OrbCollision;

	UFUNCTION()
		virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


};
