// Fill out your copyright notice in the Description page of Project Settings.


#include "FloorTrap.h"
#include "DamageInterface.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"


AFloorTrap::AFloorTrap() 
{
	Damage = 20.f;
}

void AFloorTrap::BeginPlay()
{
	Super::BeginPlay();

}

void AFloorTrap::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	characterOnTrap = true;
	FTimerDelegate TimerDelegate = FTimerDelegate::CreateUObject(this, &AFloorTrap::DamagePerSecound, OtherActor);
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, TimerDelegate,0.001f, false);
}

void AFloorTrap::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActro, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	characterOnTrap = false;
}

void AFloorTrap::DamagePerSecound(AActor* OtherActor) {
	if (characterOnTrap) {
		IDamageInterface* DamageInterface = Cast<IDamageInterface>(OtherActor);
		if (DamageInterface)
		{
			DamageInterface->Execute_DealDamage(OtherActor, Damage);
			FTimerDelegate TimerDelegate = FTimerDelegate::CreateUObject(this, &AFloorTrap::DamagePerSecound, OtherActor);
			GetWorld()->GetTimerManager().SetTimer(TimerHandle, TimerDelegate, 0.5f, false);
		}
	}
}