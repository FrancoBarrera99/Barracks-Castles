// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BarracksAndCastles/GUI/UserWidgets/OptionsUserWidget.h"
#include "BarracksAndCastles/GUI/UserWidgets/MainMenuUserWidget.h"
#include "GameFramework/HUD.h"
#include "MainHUD.generated.h"
/**
 * 
 */
UCLASS(Abstract)
class BARRACKSANDCASTLES_API AMainHUD : public AHUD
{
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<UUserWidget> OptionsWidgetsClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<UUserWidget> MainMenuWidgetsClass;


private:
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintCallable)
	void ToggleOptions();

	UFUNCTION(BlueprintCallable)
	void ToggleMenu();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Widgets")
	UOptionsUserWidget* OptionsUserWidget;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Widgets")
	UMainMenuUserWidget* MainMenuUserWidget;
};
