// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS_PlayerController.h"
#include "GAS_PlayerState.h"


AGAS_PlayerController::AGAS_PlayerController()
{
	IsInputBound = false;
}

void AGAS_PlayerController::BindASCInput()
{
	if(AbilitySystemComponent && !IsInputBound && InputComponent)
	{
		//UE_LOG(LogTemp, Warning, TEXT("%s : Input Bound"), *FString(UEnum::GetValueAsString(GetWorld()->GetNetMode())));
		AbilitySystemComponent->BindAbilityActivationToInputComponent(InputComponent, FGameplayAbilityInputBinds(FString("ConfirmTarget"), FString("CancelTarget"), FString("EAbilityInputID"), static_cast<int32>(EAbilityInputID::Confirm), static_cast<int32>(EAbilityInputID::Cancel)));
		IsInputBound = true;
	}
}

void AGAS_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	BindASCInput();
}

void AGAS_PlayerController::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	
	if (GetPlayerState<AGAS_PlayerState>())
	{
		AbilitySystemComponent = GetPlayerState<AGAS_PlayerState>()->AbilitySystemComponent;
	}
	
	BindASCInput();
}

void AGAS_PlayerController::InitPlayerState()
{
	Super::InitPlayerState();
	
	if(GetPlayerState<AGAS_PlayerState>())
	{
		AbilitySystemComponent = GetPlayerState<AGAS_PlayerState>()->AbilitySystemComponent;
	}
	
	if(GetWorld()->GetNetMode() < NM_Client) {OnRep_PlayerState();}
}