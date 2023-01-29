	// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS_Character.h"
#include "GAS_PlayerState.h"

// Sets default values
AGAS_Character::AGAS_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AGAS_Character::BeginPlay()
{
	Super::BeginPlay();
	InitializeAbilities();
}

void AGAS_Character::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if(!GetPlayerState() || GetLocalRole() != ROLE_Authority)
	{
		return;
	}

	if(Cast<AGAS_PlayerState>(GetPlayerState()))
	{
		AbilitySystemComponent = Cast<AGAS_PlayerState>(GetPlayerState())->AbilitySystemComponent;
		AbilitySystemComponent->InitAbilityActorInfo(GetPlayerState(), this);
	}
}

void AGAS_Character::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	if(Cast<AGAS_PlayerState>(GetPlayerState()))
	{
		AbilitySystemComponent = Cast<AGAS_PlayerState>(GetPlayerState())->AbilitySystemComponent;
		AbilitySystemComponent->InitAbilityActorInfo(GetPlayerState(), this);
	}
}

// Called every frame
void AGAS_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

UAbilitySystemComponent* AGAS_Character::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AGAS_Character::InitializeAbilities()
{
	if(GetLocalRole() != ROLE_Authority)
	{
		return;
	}

	if(AGAS_PlayerState* GASPlayerState = Cast<AGAS_PlayerState>(GetPlayerState()))
	{
		if(UGAS_AbilitySystemComponent* BCAbilitySystemComponent = GASPlayerState->AbilitySystemComponent)
		{
			int32 AbilityIndex = 0;
			for (TSubclassOf<UGameplayAbility>& Ability : DefaultAbilities)
			{
				FGameplayAbilitySpec AbilitySpec (
				Ability,
				1,
				AbilityIndex,
				this
				);
				
				BCAbilitySystemComponent->GiveAbility(AbilitySpec);
				AbilityIndex++;
			}
		}
	}
	
}

