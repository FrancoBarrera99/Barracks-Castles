// Fill out your copyright notice in the Description page of Project Settings.


#include "BarracksAndCastles/Buildings/BCTower.h"
#include "Components/BoxComponent.h"

ABCTower::ABCTower()
{
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Collision"));
	SphereComponent->SetupAttachment(GetRootComponent());
	SphereComponent->InitSphereRadius(1000.0f);

	BoxComponent->InitBoxExtent(FVector(200,200, 500));
	BoxComponent->SetRelativeLocation(FVector(0,0, 250));
}
