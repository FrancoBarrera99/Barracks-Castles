// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GameFramework/Character.h"
#include "GAS_Character.generated.h"

UCLASS()
class BARRACKSANDCASTLES_API AGAS_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGAS_Character();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="Abilities")
	UAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Abilities")
	TArray<TSubclassOf<UGameplayAbility>> DefaultAbilities;
	
	virtual void PossessedBy(AController* NewController) override;

	virtual void OnRep_PlayerState() override;

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	virtual void InitializeDefaultAbilities();

public:	
	// Called every frame
	virtual void Tick(float DeltaSeconds) override;
	
};