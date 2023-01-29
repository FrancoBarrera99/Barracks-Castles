// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "BarracksAndCastles/TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "GAS_Character.generated.h"

class UGameplayAbility;
class UGAS_AbilitySystemComponent;

UCLASS()
class BARRACKSANDCASTLES_API AGAS_Character : public ATP_ThirdPersonCharacter, public IAbilitySystemInterface
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
	TArray<TSubclassOf<UGameplayAbility>> DefaultAbilities;

public:	
	//	Override
	virtual void Tick(float DeltaSeconds) override;
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;	
};