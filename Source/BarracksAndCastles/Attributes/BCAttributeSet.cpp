// Fill out your copyright notice in the Description page of Project Settings.


#include "BarracksAndCastles/Attributes/BCAttributeSet.h"
#include "Net/UnrealNetwork.h"

void UBCAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UBCAttributeSet, Health, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UBCAttributeSet, HealthRegeneration, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UBCAttributeSet, Mana, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UBCAttributeSet, ManaRegeneration, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UBCAttributeSet, Power, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UBCAttributeSet, AttackSpeed, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UBCAttributeSet, Range, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UBCAttributeSet, Greed, COND_None, REPNOTIFY_Always)

}

void UBCAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBCAttributeSet, Health, OldHealth);
}

void UBCAttributeSet::OnRep_HealthRegeneration(const FGameplayAttributeData& OldHealthRegeneration)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBCAttributeSet, HealthRegeneration, OldHealthRegeneration);
}

void UBCAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBCAttributeSet, Mana, OldMana);
}

void UBCAttributeSet::OnRep_ManaRegeneration(const FGameplayAttributeData& OldManaRegeneration)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBCAttributeSet, ManaRegeneration, OldManaRegeneration);
}

void UBCAttributeSet::OnRep_Power(const FGameplayAttributeData& OldPower)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBCAttributeSet, Power, OldPower);
}

void UBCAttributeSet::OnRep_AttackSpeed(const FGameplayAttributeData& OldAttackSpeed)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBCAttributeSet, AttackSpeed, OldAttackSpeed);
}

void UBCAttributeSet::OnRep_Range(const FGameplayAttributeData& OldRange)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBCAttributeSet, Range, OldRange);
}

void UBCAttributeSet::OnRep_Greed(const FGameplayAttributeData& OldGreed)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBCAttributeSet, Greed, OldGreed)
}