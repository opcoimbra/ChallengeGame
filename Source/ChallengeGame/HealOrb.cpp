// Fill out your copyright notice in the Description page of Project Settings.


#include "HealOrb.h"
#include "Engine/Engine.h"
#include "HealInterface.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

AHealOrb::AHealOrb() 
{
	HealingAmount = 50.f;

}

void AHealOrb::BeginPlay()
{
	Super::BeginPlay();

}

void AHealOrb::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Destroy();
	IHealInterface* HealInterface = Cast<IHealInterface>(OtherActor);
	if (HealInterface)
	{
		HealInterface->Execute_HealTarget(OtherActor, HealingAmount);
	}
}
