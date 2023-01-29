// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "InputActionValue.h"
#include "GameFramework/Character.h"
#include "NativeGameplayTags.h"
#include "GAS_Character.generated.h"

class UBCGameplayAbility;
class UGAS_AbilitySystemComponent;
class UInputMappingContext;
class UInputAction;
class USpringArmComponent;
class UCameraComponent;
class UInputConfig;

UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Move);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Look);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Jump);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Ability_1);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Ability_2);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Ability_3);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Ability_4);



UCLASS()
class BARRACKSANDCASTLES_API AGAS_Character : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGAS_Character();
	
	/** The input config that maps Input Actions to Input Tags*/
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputConfig* InputConfig;
	
	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;
	
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;
	
protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	/** Called for jump input */
	void OnJump(const FInputActionValue& Value);

	/** Called for Ability1 input */
	void Ability1(const FInputActionValue& Value);

	/** Called for Ability2 Ability input */
	void Ability2(const FInputActionValue& Value);

	/** Called for Ability3 Ability input */
	void Ability3(const FInputActionValue& Value);

	/** Called for Ability4 Ability input */
	void Ability4(const FInputActionValue& Value);

	/** Called for pressing and releasing input on the Ability System Component */
	void SendLocalInputToAbilitySystemComponent(bool bIsPressed, int32 InputID);

	//	APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	//	To add Mapping Context
	virtual void BeginPlay() override;
	
	virtual void PossessedBy(AController* NewController) override;
	
	virtual void OnRep_PlayerState() override;
	
	//Give default abilities to Ability System Component
	virtual void InitializeAbilities();
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="Abilities")
	UGAS_AbilitySystemComponent* AbilitySystemComponent;

	//Holds the default abilities of the character
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Abilities")
	TArray<TSubclassOf<UBCGameplayAbility>> DefaultAbilities;

public:	
	
	virtual void Tick(float DeltaSeconds) override;
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	/** Returns CameraBoom subobject **/
	FORCEINLINE USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};