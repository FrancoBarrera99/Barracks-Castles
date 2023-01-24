// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "BCBuilding.generated.h"

UENUM(BlueprintType)
enum EBuildingState
{
	None				UMETA(DisplayName = "None"),
	Destroyed			UMETA(DisplayName = "Destroyed"),
	Built				UMETA(DisplayName = "Built"),
};

UCLASS()
class BARRACKSANDCASTLES_API ABCBuilding : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABCBuilding();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void OnConstruction(const FTransform& Transform) override;
	
	UFUNCTION(BlueprintCallable)
	void UpdateBuildingState(EBuildingState NewState);
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UBoxComponent* BoxComponent;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USceneComponent* RootSceneComponent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
	UStaticMeshComponent* BuildingStaticMesh;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	TEnumAsByte<EBuildingState> BuildingState;
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	TArray<UStaticMesh*> StateMeshes;
	
};
