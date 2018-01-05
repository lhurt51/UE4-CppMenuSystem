// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:
	AMovingPlatform();

	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
		float Speed = 20.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings", Meta = (MakeEditWidget = true))
		FVector TargetLocation;

	void AddActiveTrigger();

	void RemoveActiveTrigger();

private:
	// Actors start location in global space
	FVector GlobalStartLocation;
	
	// Actors target location in global space
	FVector GlobalTargetLocation;

	// How many active triggers there are
	UPROPERTY(EditAnywhere)
		int ActiveTriggers = 1;

};
