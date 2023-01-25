// Fill out your copyright notice in the Description page of Project Settings.


#include "BarracksAndCastles/Buildings/BCBuilding.h"
#include "BarracksAndCastles/Attributes/BCAttributeSet.h"
#include "BarracksAndCastles/Character/GAS_AbilitySystemComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
ABCBuilding::ABCBuilding()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	bReplicates = true;
	
	RootSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootSceneComponent"));
	BuildingStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BuildingStaticMesh"));

	SetRootComponent(RootSceneComponent);
	BuildingStaticMesh->SetupAttachment(GetRootComponent());

	//Setup Collider
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	BoxComponent->SetupAttachment(GetRootComponent());
	BoxComponent->InitBoxExtent(FVector(350, 350, 250));
	BoxComponent->SetRelativeLocation(FVector(0,0, 200));
	
	BuildingState = EBuildingState::Destroyed;

	//Gameplay Ability System Setup
	/* Create ASC */
	AbilitySystemComponent = CreateDefaultSubobject<UGAS_AbilitySystemComponent>("AbilitySystemComponent");
	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->SetIsReplicated(true);
		AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	}
	
	/* Create AttributeSet */
	AttributeSet = CreateDefaultSubobject<UBCAttributeSet>("AttributeSet");
	
}

// Called when the game starts or when spawned
void ABCBuilding::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABCBuilding::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABCBuilding::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	UpdateBuildingState(BuildingState);
}

void ABCBuilding::UpdateBuildingState(EBuildingState NewState)
{
	BuildingState = NewState;
	if(StateMeshes.IsValidIndex(NewState))
	{
		UStaticMesh* Asset = StateMeshes[NewState];
		BuildingStaticMesh->SetStaticMesh(Asset);
	}
}

UAbilitySystemComponent* ABCBuilding::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

