// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS_AliveObjectAttributeSet.h"
#include "Net/UnrealNetwork.h"

void UGAS_AliveObjectAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME_CONDITION_NOTIFY(UGAS_AliveObjectAttributeSet, Health, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UGAS_AliveObjectAttributeSet, HealthRegeneration, COND_None, REPNOTIFY_Always)

}

void UGAS_AliveObjectAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGAS_AliveObjectAttributeSet, Health, OldHealth);
}

void UGAS_AliveObjectAttributeSet::OnRep_HealthRegeneration(const FGameplayAttributeData& OldHealthRegeneration)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGAS_AliveObjectAttributeSet, HealthRegeneration, OldHealthRegeneration);
}
