// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BarracksAndCastles/GUI/UserWidgets/GameplayUserWidget.h"
#include "MainHUD.h"
#include "GameplayHUD.generated.h"

/**
 * 
 */
UCLASS()
class BARRACKSANDCASTLES_API AGameplayHUD : public AMainHUD
{

protected:
	
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<UGameplayUserWidget> GameplayWidgetClass;

private:
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void ToggleGameplayWidget();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Widgets")
	UGameplayUserWidget* GameplayUserWidget;

};
