// Fill out your copyright notice in the Description page of Project Settings.


#include "MainHUD.h"

void AMainHUD::BeginPlay()
{
	Super::BeginPlay();

	if(OptionsWidgetsClass)
	{
		OptionsUserWidget = CreateWidget<UOptionsUserWidget>(GetOwningPlayerController(), OptionsWidgetsClass);
	}
}

void AMainHUD::ToggleOptions()
{
	if(OptionsUserWidget)
	{
		if (OptionsUserWidget->IsInViewport())
		{
			OptionsUserWidget->RemoveFromParent();
			GetOwningPlayerController()->SetShowMouseCursor(false);
			GetOwningPlayerController()->SetInputMode(FInputModeGameOnly());
		}else
		{
			OptionsUserWidget->AddToViewport();
			GetOwningPlayerController()->SetShowMouseCursor(true);
			GetOwningPlayerController()->SetInputMode(FInputModeUIOnly());
		}
	}
}

void AMainHUD::ToggleMenu()
{
	if(MainMenuUserWidget)
	{
		if (MainMenuUserWidget->IsInViewport())
		{
			MainMenuUserWidget->RemoveFromParent();
			GetOwningPlayerController()->SetShowMouseCursor(false);
			GetOwningPlayerController()->SetInputMode(FInputModeGameOnly());
		}else
		{
			MainMenuUserWidget->AddToViewport();
			GetOwningPlayerController()->SetShowMouseCursor(true);
			GetOwningPlayerController()->SetInputMode(FInputModeUIOnly());
		}
	}
}
