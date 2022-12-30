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

	InitializeDefaultAbilities();
	
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

		/* Set Owner and Avatar Actor for ASC */
		AbilitySystemComponent->InitAbilityActorInfo(GetPlayerState(), this);
	}
}

void AGAS_Character::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	if(Cast<AGAS_PlayerState>(GetPlayerState()))
	{
		AbilitySystemComponent = Cast<AGAS_PlayerState>(GetPlayerState())->AbilitySystemComponent;

		/* Set Owner and Avatar Actor for ASC */
		AbilitySystemComponent->InitAbilityActorInfo(GetPlayerState(), this);
	}
}

// Called every frame
void AGAS_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGAS_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AGAS_Character::InitializeDefaultAbilities()
{
	if(GetLocalRole() != ROLE_Authority)
	{
		return;
	}

	AGAS_PlayerState* CharacterPS = Cast<AGAS_PlayerState>(GetPlayerState());
	
	if(CharacterPS->IsValidLowLevel())
	{
		const int size = DefaultAbilities.Num();
		
		for(int i = 0; i < size; i++)
		{
			CharacterPS->GrantAbility(DefaultAbilities[i], 0, i);
		}
	}
	
}

