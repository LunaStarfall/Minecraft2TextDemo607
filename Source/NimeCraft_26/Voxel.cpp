// Fill out your copyright notice in the Description page of Project Settings.


#include "Voxel.h"

// Sets default values
AVoxel::AVoxel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	BaseVoxelMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Voxel Mesh"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh>VoxelMesh(TEXT("/Game/Voxel/Base_Voxel_Mesh"));
	static ConstructorHelpers::FObjectFinder<UMaterial>VoxelMat(TEXT("/Game/Voxel/Base_Voxel_Material"));


	if (VoxelMesh.Succeeded())
	{
		BaseVoxelMesh->SetStaticMesh(VoxelMesh.Object);
	}
	if (VoxelMat.Succeeded())
	{
		BaseVoxelMat = VoxelMat.Object;

		BaseVoxelMesh->SetMaterial(0, BaseVoxelMat);
	}


	

}

// Called when the game starts or when spawned
void AVoxel::BeginPlay()
{
	Super::BeginPlay();
	
}

void AVoxel::PlayerInteract()
{
	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Blue, TEXT("Owwm, I have been hit"));

	Destroy();
}

// Called every frame
void AVoxel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

