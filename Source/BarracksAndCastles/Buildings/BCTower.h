// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BCBuilding.h"
#include "Components/SphereComponent.h"
#include "BCTower.generated.h"

/**
 * 
 */
UCLASS()
class BARRACKSANDCASTLES_API ABCTower : public ABCBuilding
{
	GENERATED_BODY()

public:

	ABCTower();

	UPROPERTY(EditDefaultsOnly)
	USphereComponent* SphereComponent;
	
};
