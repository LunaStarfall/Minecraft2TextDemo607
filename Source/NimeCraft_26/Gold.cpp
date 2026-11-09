// Fill out your copyright notice in the Description page of Project Settings.


#include "Gold.h"

AGold::AGold()
{
	PrimaryActorTick.bCanEverTick = false;

	static ConstructorHelpers::FObjectFinder<UMaterial>GoldMaterial(TEXT("/Game/Voxel/Gold_Mat.Gold_Mat"));

	if (GoldMaterial.Succeeded())
	{
		Gold = GoldMaterial.Object;

		BaseVoxelMesh->SetMaterial(0, Gold);
	}
}
