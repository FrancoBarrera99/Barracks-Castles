// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "BarracksAndCastles/Character/GAS_PlayerController.h"
#include "BCGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class BARRACKSANDCASTLES_API UBCGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Input")
	TEnumAsByte<EAbilityInputID> AbilityInputID;
};
