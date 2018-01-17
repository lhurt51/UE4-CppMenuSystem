// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenu.h"

#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Components/EditableTextBox.h"

bool UMainMenu::Initialize()
{
	if (!Super::Initialize()) return false;
	
	if (!ensure(HostButton != nullptr)) return false;
	HostButton->OnClicked.AddDynamic(this, &UMainMenu::HostServer); 

	if (!ensure(JoinMenuButton != nullptr)) return false;
	JoinMenuButton->OnClicked.AddDynamic(this, &UMainMenu::OpenJoinMenu);

	if (!ensure(ExitButton != nullptr)) return false;
	ExitButton->OnClicked.AddDynamic(this, &UMainMenu::ExitPressed);

	if (!ensure(CancelJoinButton != nullptr)) return false;
	CancelJoinButton->OnClicked.AddDynamic(this, &UMainMenu::OpenMainMenu);

	if (!ensure(JoinServerButton != nullptr)) return false;
	JoinServerButton->OnClicked.AddDynamic(this, &UMainMenu::JoinServer);

	return true;
}

void UMainMenu::HostServer()
{
	if (MenuInterface != nullptr) MenuInterface->Host();
}

void UMainMenu::JoinServer()
{
	if (MenuInterface != nullptr)
	{
		if (!ensure(IPAddressInput != nullptr)) return;
		const FString& Address = IPAddressInput->GetText().ToString();
		MenuInterface->Join(Address);
	}
}

void UMainMenu::ExitPressed()
{
	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;
	APlayerController* PlayerController = World->GetFirstPlayerController();

	if (!ensure(PlayerController != nullptr)) return;
	PlayerController->ConsoleCommand("quit");
}

void UMainMenu::OpenMainMenu()
{
	if (!ensure(MenuSwitcher != nullptr) || !ensure(MainMenu != nullptr)) return;
	MenuSwitcher->SetActiveWidget(MainMenu);
}

void UMainMenu::OpenJoinMenu()
{
	if (!ensure(MenuSwitcher != nullptr) || !ensure(JoinMenu != nullptr)) return;
	MenuSwitcher->SetActiveWidget(JoinMenu);
}

