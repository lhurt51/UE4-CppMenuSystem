// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PuzzlePlatformsGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UPuzzlePlatformsGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	// Constructor
	UPuzzlePlatformsGameInstance(const FObjectInitializer &ObjectInitializer);
	
	// Game Instantes initializer
	virtual void Init();

	UFUNCTION(Exec)
		void Host();

	UFUNCTION(Exec)
		void Join(const FString &Address);

};
