// Fill out your copyright notice in the Description page of Project Settings.

#include "InGameMenu.h"

#include "Components/Button.h"


bool UInGameMenu::Initialize()
{
	if (!Super::Initialize()) return false;

	if (!ensure(CancelButton != nullptr)) return false;
	CancelButton->OnClicked.AddDynamic(this, &UInGameMenu::CancelButtonPressed);

	if (!ensure(QuitButton != nullptr)) return false;
	QuitButton->OnClicked.AddDynamic(this, &UInGameMenu::QuitButtonPressed);

	return true;
}

void UInGameMenu::CancelButtonPressed()
{
	TearDown();
}

void UInGameMenu::QuitButtonPressed()
{
	if (MenuInterface != nullptr)
	{
		TearDown();
		MenuInterface->LoadMainMenu();
	}
}