// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BCBuilding.h"
#include "GameFramework/Actor.h"
#include "BCKeep.generated.h"

UCLASS()
class BARRACKSANDCASTLES_API ABCKeep : public ABCBuilding
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABCKeep();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
