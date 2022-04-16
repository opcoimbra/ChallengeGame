// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Orbes.h"
#include "HealOrb.generated.h"

/**
 * 
 */
UCLASS()
class CHALLENGEGAME_API AHealOrb : public AOrbes
{
	GENERATED_BODY()

public:
	AHealOrb();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Healing")float HealingAmount;

	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
};
