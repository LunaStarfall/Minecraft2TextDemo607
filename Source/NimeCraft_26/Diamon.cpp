// Fill out your copyright notice in the Description page of Project Settings.


#include "Diamon.h"

ADiamon::ADiamon()
{
	PrimaryActorTick.bCanEverTick = false;

	static ConstructorHelpers::FObjectFinder<UMaterial>DiamondMaterial(TEXT("/Game/Voxel/Diamon_Mat.Diamon_Mat"));

	if (DiamondMaterial.Succeeded())
	{
		Diamond = DiamondMaterial.Object;

		BaseVoxelMesh->SetMaterial(0, Diamond);
	}
}
