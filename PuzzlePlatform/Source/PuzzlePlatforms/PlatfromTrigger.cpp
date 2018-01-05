// Fill out your copyright notice in the Description page of Project Settings.

#include "PlatfromTrigger.h"

#include "Components/BoxComponent.h"

#include "MovingPlatform.h"


// Sets default values
APlatfromTrigger::APlatfromTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (!ensure((TriggerVolume = CreateDefaultSubobject<UBoxComponent>(FName("TriggerVolume"))) != nullptr)) return;

	RootComponent = TriggerVolume;

	TriggerVolume->OnComponentBeginOverlap.AddDynamic(this, &APlatfromTrigger::OnOverlapBegin);
	TriggerVolume->OnComponentEndOverlap.AddDynamic(this, &APlatfromTrigger::OnOverlapEnd);
}

// Called when the game starts or when spawned
void APlatfromTrigger::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlatfromTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlatfromTrigger::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	for (AMovingPlatform *Platform : PlatformsToTrigger)
	{
		Platform->AddActiveTrigger();
	}
}

void APlatfromTrigger::OnOverlapEnd(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	for (AMovingPlatform *Platform : PlatformsToTrigger)
	{
		Platform->RemoveActiveTrigger();
	}
}
