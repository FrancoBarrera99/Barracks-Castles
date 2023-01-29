// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "BCGameplayAbility.generated.h"

UENUM(BlueprintType)
enum EAbilityInputID
{
	None			UMETA(DisplayName = "None"),
	Ability1		UMETA(DisplayName = "Ability1"),
	Ability2		UMETA(DisplayName = "Ability2"),
	Ability3		UMETA(DisplayName = "Ability3"),
	Ability4		UMETA(DisplayName = "Ability4"),

};

/**
 * 
 */
UCLASS()
class BARRACKSANDCASTLES_API UBCGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TEnumAsByte<EAbilityInputID> InputID;
};
