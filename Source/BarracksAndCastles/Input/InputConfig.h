// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTags/Classes/GameplayTagContainer.h"
#include "InputConfig.generated.h"

class UInputAction;
struct FGameplayTag;

/**
 * FTaggedInputAction
 *
 *	Struct used to map an input action to a gameplay input tag.
 */

USTRUCT(BlueprintType)
struct FTaggedInputAction
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	const UInputAction* InputAction = nullptr;

	UPROPERTY(EditDefaultsOnly, Meta = (Categories = "InputTag"))
	FGameplayTag InputTag;
};

UCLASS()
class BARRACKSANDCASTLES_API UInputConfig : public UDataAsset
{
	GENERATED_BODY()

public:

	//Returns the first input action associated whit the given tag
	const UInputAction* FindInputActionForTag(const FGameplayTag& InputTag) const;

	//List of input actions use by the owner. This input actions are mapped to a gameplay tag and must be manually bound.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Meta = (TitleProperty = "InputAction"))
	TArray<FTaggedInputAction> TaggedInputActions;
};
