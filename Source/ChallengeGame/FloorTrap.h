// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Traps.h"
#include "FloorTrap.generated.h"

/**
 * 
 */
UCLASS()
class CHALLENGEGAME_API AFloorTrap : public ATraps
{
	GENERATED_BODY()

public:

	AFloorTrap();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage") 
		float Damage;
	
	bool characterOnTrap;

	FTimerHandle TimerHandle;

protected:
	virtual void BeginPlay() override;


public:
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

	virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActro, UPrimitiveComponent*OtherComp, int32 OtherBodyIndex) override;

	void DamagePerSecound(AActor* OtherActor);
};
