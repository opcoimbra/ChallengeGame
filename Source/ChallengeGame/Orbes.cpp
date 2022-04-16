// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/Engine.h"
#include "Orbes.h"

// Sets default values
AOrbes::AOrbes()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	OrbMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	RootComponent = OrbMesh;

	OrbCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	OrbCollision->SetupAttachment(RootComponent);
	OrbCollision->SetSphereRadius(100.f);
	OrbCollision->OnComponentBeginOverlap.AddDynamic(this, &AOrbes::OnOverlapBegin);


}

void AOrbes::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) 
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Overlaping"));
}

