// Fill out your copyright notice in the Description page of Project Settings.


#include "Coal.h"

ACoal::ACoal()
{
	PrimaryActorTick.bCanEverTick = false;

	static ConstructorHelpers::FObjectFinder<UMaterial>CoalMaterial(TEXT("/Game/Voxel/Coal_mat.Coal_mat"));

	if (CoalMaterial.Succeeded())
	{
		Coal = CoalMaterial.Object;

		BaseVoxelMesh->SetMaterial(0, Coal);
	}
}
