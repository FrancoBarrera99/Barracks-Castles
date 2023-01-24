// Fill out your copyright notice in the Description page of Project Settings.


#include "BarracksAndCastles/Buildings/BCWallGate.h"

ABCWallGate::ABCWallGate()
{
	GateDoor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GateDoor"));
	GateDoor->SetupAttachment(BuildingStaticMesh);

}
