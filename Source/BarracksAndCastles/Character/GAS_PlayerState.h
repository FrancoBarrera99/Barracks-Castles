// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "GAS_AbilitySystemComponent.h"
#include "GameFramework/PlayerState.h"
#include "GAS_PlayerState.generated.h"


/**
 * This player state is created to hold the ASC and the AttributeSet for a Character
 * It could be use both for AI Controlled or Player Controlled Characters
 */
UCLASS()
class BARRACKSANDCASTLES_API AGAS_PlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:

	AGAS_PlayerState(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="Abilities")
	UGAS_AbilitySystemComponent* AbilitySystemComponent;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UPROPERTY()
	class UGAS_CharacterAttributeSet* AttributeSet;
};
