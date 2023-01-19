// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GAS_AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "BarracksAndCastles/Abilities/BCGameplayAbility.h"
#include "GameFramework/Character.h"
#include "GAS_Character.generated.h"

UCLASS()
class BARRACKSANDCASTLES_API AGAS_Character : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGAS_Character();
	
protected:
	//	Override
	virtual void BeginPlay() override;
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
	
	//Gameplay Ability System
	virtual void InitializeAbilities();
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="Abilities")
	UGAS_AbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Abilities")
	TArray<TSubclassOf<UBCGameplayAbility>> DefaultAbilities;

public:	
	//	Override
	virtual void Tick(float DeltaSeconds) override;
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;	
};