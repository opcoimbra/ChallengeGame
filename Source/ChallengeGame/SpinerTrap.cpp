// Fill out your copyright notice in the Description page of Project Settings.


#include "SpinerTrap.h"
#include "DamageInterface.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

ASpinerTrap::ASpinerTrap()
{
	Damage = 100.f;
}

void ASpinerTrap::BeginPlay()
{
	Super::BeginPlay();
}

void ASpinerTrap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FQuat Rotation = FQuat(FRotator(PitchValue, YawValue, RollValue));
	AddActorLocalRotation(Rotation, false, 0, ETeleportType::None);

}

void ASpinerTrap::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	IDamageInterface* DamageInterface = Cast<IDamageInterface>(OtherActor);
	if (DamageInterface) 
	{
		DamageInterface->Execute_DealDamage(OtherActor,Damage);
	}
}

void ASpinerTrap::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActro, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}