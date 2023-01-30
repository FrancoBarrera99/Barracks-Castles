// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS_Character.h"
#include "GAS_PlayerState.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "NativeGameplayTags.h"
#include "EnhancedInputSubsystems.h"
#include "BarracksAndCastles/Abilities/BCGameplayAbility.h"
#include "BarracksAndCastles/Input/BCEnhancedInputComponent.h"


//Define Input Tags to bind to Input Actions
UE_DEFINE_GAMEPLAY_TAG(InputTag_Move, "InputTag.Move");
UE_DEFINE_GAMEPLAY_TAG(InputTag_Look, "InputTag.Look");
UE_DEFINE_GAMEPLAY_TAG(InputTag_Jump, "InputTag.Jump");
UE_DEFINE_GAMEPLAY_TAG(InputTag_Ability_1, "InputTag.Ability.1");
UE_DEFINE_GAMEPLAY_TAG(InputTag_Ability_2, "InputTag.Ability.2");
UE_DEFINE_GAMEPLAY_TAG(InputTag_Ability_3, "InputTag.Ability.3");
UE_DEFINE_GAMEPLAY_TAG(InputTag_Ability_4, "InputTag.Ability.4");


// Sets default values
AGAS_Character::AGAS_Character()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	// Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)
}

void AGAS_Character::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	
		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void AGAS_Character::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void AGAS_Character::OnJump(const FInputActionValue& Value)
{
	bool JumpBool = Value.Get<bool>();
	JumpBool ? ACharacter::Jump() : ACharacter::StopJumping();
}

void AGAS_Character::Ability1(const FInputActionValue& Value)
{
	bool bIsPressed = Value.Get<bool>();
	SendLocalInputToAbilitySystemComponent(bIsPressed, EAbilityInputID::Ability1);
}

void AGAS_Character::Ability2(const FInputActionValue& Value)
{
	bool bIsPressed = Value.Get<bool>();
	SendLocalInputToAbilitySystemComponent(bIsPressed, EAbilityInputID::Ability2);
}

void AGAS_Character::Ability3(const FInputActionValue& Value)
{
	bool bIsPressed = Value.Get<bool>();
	SendLocalInputToAbilitySystemComponent(bIsPressed, EAbilityInputID::Ability3);
}

void AGAS_Character::Ability4(const FInputActionValue& Value)
{
	bool bIsPressed = Value.Get<bool>();
	SendLocalInputToAbilitySystemComponent(bIsPressed, EAbilityInputID::Ability4);
}

void AGAS_Character::SendLocalInputToAbilitySystemComponent(bool bIsPressed, int32 InputID)
{
	if(AbilitySystemComponent)
	{
		bIsPressed ? AbilitySystemComponent->PressInputID(InputID) : AbilitySystemComponent->ReleaseInputID(InputID);
	}
}

void AGAS_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}

	// Set up action bindings
	if (UBCEnhancedInputComponent* BCEnhancedInputComponent = CastChecked<UBCEnhancedInputComponent>(PlayerInputComponent))
	{
		//Bind input actions to input tags
		BCEnhancedInputComponent->BindActionByTag(InputConfig, InputTag_Jump, ETriggerEvent::Triggered, this ,&AGAS_Character::OnJump);
		BCEnhancedInputComponent->BindActionByTag(InputConfig, InputTag_Move, ETriggerEvent::Triggered, this, &AGAS_Character::Move);
		BCEnhancedInputComponent->BindActionByTag(InputConfig, InputTag_Look, ETriggerEvent::Triggered, this, &AGAS_Character::Look);
		BCEnhancedInputComponent->BindActionByTag(InputConfig, InputTag_Ability_1, ETriggerEvent::Triggered, this, &AGAS_Character::Ability1);
		BCEnhancedInputComponent->BindActionByTag(InputConfig, InputTag_Ability_2, ETriggerEvent::Triggered, this, &AGAS_Character::Ability2);
		BCEnhancedInputComponent->BindActionByTag(InputConfig, InputTag_Ability_3, ETriggerEvent::Triggered, this, &AGAS_Character::Ability3);
		BCEnhancedInputComponent->BindActionByTag(InputConfig, InputTag_Ability_4, ETriggerEvent::Triggered, this, &AGAS_Character::Ability4);
	}
}

// Called when the game starts or when spawned
void AGAS_Character::BeginPlay()
{
	Super::BeginPlay();
}

void AGAS_Character::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (AGAS_PlayerState* PS = GetPlayerState<AGAS_PlayerState>())
	{
		AbilitySystemComponent = Cast<UGAS_AbilitySystemComponent>(PS->GetAbilitySystemComponent());
		PS->GetAbilitySystemComponent()->InitAbilityActorInfo(GetPlayerState(), this);
	}

	InitializeAbilities();
}

void AGAS_Character::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	if (AGAS_PlayerState* PS = GetPlayerState<AGAS_PlayerState>())
	{
		AbilitySystemComponent = Cast<UGAS_AbilitySystemComponent>(PS->GetAbilitySystemComponent());
		PS->GetAbilitySystemComponent()->InitAbilityActorInfo(GetPlayerState(), this);
	}
}

UAbilitySystemComponent* AGAS_Character::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AGAS_Character::InitializeAbilities()
{
	if (GetLocalRole() != ROLE_Authority)
	{
		return;
	}

	if (AGAS_PlayerState* GASPlayerState = Cast<AGAS_PlayerState>(GetPlayerState()))
	{
		if (UGAS_AbilitySystemComponent* BCAbilitySystemComponent = GASPlayerState->AbilitySystemComponent)
		{
			// Give each Gameplay Ability to the Ability System Component
			for (TSubclassOf<UBCGameplayAbility>& Ability : DefaultAbilities)
			{
				FGameplayAbilitySpec AbilitySpec(
					Ability,
					1,
					Ability.GetDefaultObject()->InputID,
					this
				);

				BCAbilitySystemComponent->GiveAbility(AbilitySpec);
			}
		}
	}
}
