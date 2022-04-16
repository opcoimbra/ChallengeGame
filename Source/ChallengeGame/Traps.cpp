// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/Engine.h"
#include "Traps.h"

// Sets default values
ATraps::ATraps()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TrapMesh = CreateAbstractDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	RootComponent = TrapMesh;

	TrapCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	TrapCollision->SetupAttachment(RootComponent);
	TrapCollision->InitBoxExtent(FVector(100.f, 100.f, 100.f));

	TrapCollision->OnComponentBeginOverlap.AddDynamic(this, &ATraps::OnOverlapBegin);
	TrapCollision->OnComponentEndOverlap.AddDynamic(this, &ATraps::OnOverlapEnd);

}

// Called when the game starts or when spawned
void ATraps::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATraps::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATraps::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Overlaping"));
}

void ATraps::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActro, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("End Overlaping"));
}

