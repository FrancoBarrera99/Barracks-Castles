// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GAS_AbilitySystemComponent.h"
#include "GameFramework/PlayerController.h"
#include "GAS_PlayerController.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum EAbilityInputID
{
	None				UMETA(DisplayName = "None"),
	Confirm				UMETA(DisplayName = "Confirm"),
	Cancel				UMETA(DisplayName = "Cancel"),
	Jump				UMETA(DisplayName = "Jump"),
	Sprint				UMETA(DisplayName = "Sprint"),
	Interaction			UMETA(DisplayName = "Interaction"),
	FirstAbility		UMETA(DisplayName = "FirstAbility"),
	SecondAbility		UMETA(DisplayName = "SecondAbility"),
	ThirdAbility		UMETA(DisplayName = "ThirdAbility"),
	FourthAbility		UMETA(DisplayName = "FourthAbility")
};

UCLASS()
class BARRACKSANDCASTLES_API AGAS_PlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	AGAS_PlayerController();

	UPROPERTY(BlueprintReadOnly)
	bool IsInputBound;

	UPROPERTY(BlueprintReadOnly)
	UGAS_AbilitySystemComponent* AbilitySystemComponent;

	void BindASCInput();
	
	//***********************Overrides*****************************
	
	virtual void SetupInputComponent() override;

	virtual void OnRep_PlayerState() override;

	virtual void InitPlayerState() override;
	
};
