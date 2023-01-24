// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayUserWidget.h"

#include "Components/TextBlock.h"
#include "BarracksAndCastles/Attributes/BCAttributeSet.h"

void UGameplayUserWidget::NativeOnInitialized()
{
	PlayerState = GetOwningPlayer()->GetPlayerState<AGAS_PlayerState>();
	
	if(PlayerState)
	{
		AbilitySystemComponent = PlayerState->AbilitySystemComponent;
		if (AbilitySystemComponent)
		{
			AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UBCAttributeSet::GetHealthAttribute()).AddUObject(this, &ThisClass::OnHealthChanged);
			AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UBCAttributeSet::GetManaAttribute()).AddUObject(this, &ThisClass::OnManaChanged);
			AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UBCAttributeSet::GetPowerAttribute()).AddUObject(this, &ThisClass::OnPowerChanged);
			AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UBCAttributeSet::GetAttackSpeedAttribute()).AddUObject(this, &ThisClass::OnAttackSpeedChanged);
			AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UBCAttributeSet::GetRangeAttribute()).AddUObject(this, &ThisClass::OnRangeChanged);
			AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UBCAttributeSet::GetGreedAttribute()).AddUObject(this, &ThisClass::OnGreedChanged);
		}
	}
	Super::NativeOnInitialized();
}

void UGameplayUserWidget::OnHealthChanged(const FOnAttributeChangeData& IncomingData) const
{
	HealthProgressBar->SetPercent(static_cast<int32>(IncomingData.NewValue) / 100);
	HealthTextValue->SetText(FText::FromString(FString::FromInt(IncomingData.NewValue)));
}

void UGameplayUserWidget::OnManaChanged(const FOnAttributeChangeData& IncomingData) const
{
	ManaProgressBar->SetPercent(static_cast<int32>(IncomingData.NewValue) / 100);
	ManaTextValue->SetText(FText::FromString(FString::FromInt(IncomingData.NewValue)));
}

void UGameplayUserWidget::OnPowerChanged(const FOnAttributeChangeData& IncomingData) const
{
	PowerTextValue->SetText(FText::FromString(FString::FromInt(IncomingData.NewValue)));
}

void UGameplayUserWidget::OnAttackSpeedChanged(const FOnAttributeChangeData& IncomingData) const
{
	AttackSpeedTextValue->SetText(FText::FromString(FString::FromInt(IncomingData.NewValue)));
}

void UGameplayUserWidget::OnRangeChanged(const FOnAttributeChangeData& IncomingData) const
{
	RangeTextValue->SetText(FText::FromString(FString::FromInt(IncomingData.NewValue)));
}

void UGameplayUserWidget::OnGreedChanged(const FOnAttributeChangeData& IncomingData) const
{
	GreedTextValue->SetText(FText::FromString(FString::FromInt(IncomingData.NewValue)));
}


