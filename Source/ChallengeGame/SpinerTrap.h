// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Traps.h"
#include "SpinerTrap.generated.h"

/**
 * 
 */
UCLASS()
class CHALLENGEGAME_API ASpinerTrap : public ATraps
{
	GENERATED_BODY()

public:
	ASpinerTrap();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
		float Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
		float PitchValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
		float YawValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
		float RollValue;

protected:

	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;

	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

	virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActro, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;
	
};
