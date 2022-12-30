// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayHUD.h"

void AGameplayHUD::BeginPlay()
{
	Super::BeginPlay();
	
	if (GameplayWidgetClass)
	{
		GameplayUserWidget = CreateWidget<UGameplayUserWidget>(GetOwningPlayerController(), GameplayWidgetClass);
		if(GameplayUserWidget)
		{
			GameplayUserWidget->AddToViewport();
			GetOwningPlayerController()->SetShowMouseCursor(false);
			GetOwningPlayerController()->SetInputMode(FInputModeGameOnly());
		}
	}
}

void AGameplayHUD::ToggleGameplayWidget()
{
	if (GameplayUserWidget)
	{
		if(GameplayUserWidget->IsInViewport())
		{
			GameplayUserWidget->RemoveFromParent();
		}else
		{
			GameplayUserWidget->AddToViewport();
		}
	}
}
