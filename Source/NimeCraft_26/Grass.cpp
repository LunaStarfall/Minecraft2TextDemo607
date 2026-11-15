// Fill out your copyright notice in the Description page of Project Settings.


#include "Grass.h"



AGrass::AGrass()
{
	PrimaryActorTick.bCanEverTick = false;

	static ConstructorHelpers::FObjectFinder<UMaterial>GrassMaterial(TEXT("/Game/Voxel/Grass_Mat.Grass_Mat"));

	if (GrassMaterial.Succeeded())
	{
		Grass = GrassMaterial.Object;

		BaseVoxelMesh->SetMaterial(0, Grass);
	}
}
