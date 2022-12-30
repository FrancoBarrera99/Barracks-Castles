// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "BarracksAndCastles/Character/GAS_PlayerState.h"
#include "GameplayUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class BARRACKSANDCASTLES_API UGameplayUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual void NativeOnInitialized() override;

	AGAS_PlayerState* PlayerState;

	UAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UProgressBar* HealthProgressBar;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UProgressBar* ManaProgressBar;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* HealthTextValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* ManaTextValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* PowerTextValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* AttackSpeedTextValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* RangeTextValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* MagnetTextValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* GreedTextValue;
	
	void OnHealthChanged(const FOnAttributeChangeData& IncomingData) const;
	
	void OnManaChanged(const FOnAttributeChangeData& IncomingData) const;

	void OnPowerChanged(const FOnAttributeChangeData& IncomingData) const;

	void OnAttackSpeedChanged(const FOnAttributeChangeData& IncomingData) const;

	void OnRangeChanged(const FOnAttributeChangeData& IncomingData) const;

	void OnGreedChanged(const FOnAttributeChangeData& IncomingData) const;
};
