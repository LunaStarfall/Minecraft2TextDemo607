// Fill out your copyright notice in the Description page of Project Settings.


#include "Iron.h"

AIron::AIron()
{
	PrimaryActorTick.bCanEverTick = false;

	static ConstructorHelpers::FObjectFinder<UMaterial>IronMaterial(TEXT("/Game/Voxel/Iron_Mat.Iron_Mat"));

	if (IronMaterial.Succeeded())
	{
		Iron = IronMaterial.Object;

		BaseVoxelMesh->SetMaterial(0, Iron);
	}
}
