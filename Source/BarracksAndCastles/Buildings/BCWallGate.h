// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BCBuilding.h"
#include "BCWallGate.generated.h"

/**
 * 
 */
UCLASS()
class BARRACKSANDCASTLES_API ABCWallGate : public ABCBuilding
{
	GENERATED_BODY()

public:

	ABCWallGate();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* GateDoor;
	
};
