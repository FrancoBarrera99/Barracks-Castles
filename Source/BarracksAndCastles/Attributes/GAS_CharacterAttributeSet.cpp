// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS_CharacterAttributeSet.h"
#include "Net/UnrealNetwork.h"

void UGAS_CharacterAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME_CONDITION_NOTIFY(UGAS_CharacterAttributeSet, Mana, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UGAS_CharacterAttributeSet, ManaRegeneration, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UGAS_CharacterAttributeSet, Power, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UGAS_CharacterAttributeSet, AttackSpeed, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UGAS_CharacterAttributeSet, Range, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UGAS_CharacterAttributeSet, Greed, COND_None, REPNOTIFY_Always)

}

void UGAS_CharacterAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGAS_CharacterAttributeSet, Mana, OldMana);
}

void UGAS_CharacterAttributeSet::OnRep_ManaRegeneration(const FGameplayAttributeData& OldManaRegeneration)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGAS_CharacterAttributeSet, ManaRegeneration, OldManaRegeneration);
}

void UGAS_CharacterAttributeSet::OnRep_Power(const FGameplayAttributeData& OldPower)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGAS_CharacterAttributeSet, Power, OldPower);
}

void UGAS_CharacterAttributeSet::OnRep_AttackSpeed(const FGameplayAttributeData& OldAttackSpeed)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGAS_CharacterAttributeSet, AttackSpeed, OldAttackSpeed);
}

void UGAS_CharacterAttributeSet::OnRep_Range(const FGameplayAttributeData& OldRange)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGAS_CharacterAttributeSet, Range, OldRange);
}

void UGAS_CharacterAttributeSet::OnRep_Greed(const FGameplayAttributeData& OldGreed)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGAS_CharacterAttributeSet, Greed, OldGreed)
}

