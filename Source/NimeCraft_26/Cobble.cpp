// Fill out your copyright notice in the Description page of Project Settings.


#include "Cobble.h"  
ACobble::ACobble()
{
	PrimaryActorTick.bCanEverTick = false;

	static ConstructorHelpers::FObjectFinder<UMaterial>Cobblematerial(TEXT("/Game/Voxel/Cobble_Mat.Cobble_Mat"));

	if (Cobblematerial.Succeeded())
	{
		Cobble = Cobblematerial.Object;

		BaseVoxelMesh->SetMaterial(0, Cobble);
	}
}