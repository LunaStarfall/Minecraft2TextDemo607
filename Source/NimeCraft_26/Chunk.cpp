// Fill out your copyright notice in the Description page of Project Settings.


#include "Chunk.h"

// Sets default values
AChunk::AChunk()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpawnLoc = FVector(0, 0, 50);
	SpawnRot = FRotator::ZeroRotator;
	SpawnParams.OverrideLevel = GetLevel();

	

}

// Called when the game starts or when spawned
void AChunk::BeginPlay()
{
	Super::BeginPlay();

	FVector VoxalScale = FVector(BaseVoxalMeasuement, BaseVoxalMeasuement, BaseVoxalMeasuement);

	int VoxelCount = 0;
	int GrassStart = ChunkZ - 2;
	int DirtStart = ChunkZ/3;
	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Blue, FString::Printf(TEXT("Hello, this is the chunk")));


	for (int k = 0; k < ChunkZ; k++)
	{
		for (int j = 0; j < ChunkY; j++)
		{
			for (int i = 0; i < ChunkX; i++)
			{
				Chunk[i][j][k] = GetWorld()->SpawnActor<AVoxel>(SpawnLoc, SpawnRot, SpawnParams);

				Chunk[i][j][k]->SetActorScale3D(VoxalScale);

				SpawnLoc.X += (BaseVoxalMeasuement *100);

				VoxelCount++;
			}
			SpawnLoc.X -= ChunkX * (BaseVoxalMeasuement * 100);
			SpawnLoc.Y += (BaseVoxalMeasuement*100);
		}
		SpawnLoc.Y -= ChunkY* (BaseVoxalMeasuement * 100);
		SpawnLoc.Z += (BaseVoxalMeasuement * 100);
	}
	

	if (GEngine) GEngine->AddOnScreenDebugMessage(4, 10.f, FColor::Black,
		FString::Printf(TEXT("We have %d number of Voxels"), VoxelCount));
}

// Called every frame
void AChunk::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

