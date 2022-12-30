// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS_PlayerState.h"
#include "BarracksAndCastles/Attributes/GAS_CharacterAttributeSet.h"

AGAS_PlayerState::AGAS_PlayerState(const FObjectInitializer& ObjectInitializer)
{
	/* Create ASC */
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	/* Create CharacterAttributeSet */
	AttributeSet = CreateDefaultSubobject<UGAS_CharacterAttributeSet>("AttributeSet");
}

void AGAS_PlayerState::GrantAbility(TSubclassOf<UGameplayAbility> AbilityClass, int32 Level, int32 InputCode)
{
	if(AbilitySystemComponent && HasAuthority() && IsValid(AbilityClass))
	{
		UGameplayAbility* Ability = AbilityClass->GetDefaultObject<UGameplayAbility>();

		if(IsValid(Ability))
		{
			FGameplayAbilitySpec AbilitySpec (
			Ability,
			Level,
			InputCode
			);
		
			AbilitySystemComponent->GiveAbility(AbilitySpec);
		}
	}
}

void AGAS_PlayerState::ActivateAbilitiesByTag(FGameplayTagContainer GameplayTagContainer)
{
	if(AbilitySystemComponent)
	{
		AbilitySystemComponent->TryActivateAbilitiesByTag(GameplayTagContainer);
	}
}
