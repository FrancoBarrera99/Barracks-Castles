// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS_PlayerState.h"
#include "BarracksAndCastles/Attributes/BCAttributeSet.h"

AGAS_PlayerState::AGAS_PlayerState(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
	/* Create ASC */
	AbilitySystemComponent = CreateDefaultSubobject<UGAS_AbilitySystemComponent>("AbilitySystemComponent");
	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->SetIsReplicated(true);
		AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	}
	
	/* Create AttributeSet */
	AttributeSet = CreateDefaultSubobject<UBCAttributeSet>("AttributeSet");
}

UAbilitySystemComponent* AGAS_PlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
