// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "Traps.generated.h"

UCLASS()
class CHALLENGEGAME_API ATraps : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATraps();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TrapInfo")
		UStaticMeshComponent* TrapMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TrapInfo")
		UBoxComponent* TrapCollision;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActro, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};
