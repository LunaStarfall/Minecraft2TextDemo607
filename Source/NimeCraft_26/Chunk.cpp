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
	int GrassStart = 28;
	int DirtStart = 25;
	int layerPrinted = 0;
	//if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Blue, FString::Printf(TEXT("Hello, this is the chunk")));


	for (int k = 0; k < ChunkZ; k++)
	{
		for (int j = 0; j < ChunkY; j++)
		{
			for (int i = 0; i < ChunkX; i++)
			{
				if (layerPrinted > GrassStart)
				{
					Chunk[i][j][k] = GetWorld()->SpawnActor<AGrass>(SpawnLoc, SpawnRot, SpawnParams);
				}
				else if (layerPrinted > DirtStart)
				{
					Chunk[i][j][k] = GetWorld()->SpawnActor<ADirt>(SpawnLoc, SpawnRot, SpawnParams);
				}
				else

					if (layerPrinted > 20)
					{

						if (rand() % 10 == 1)
						{
							Chunk[i][j][k] = GetWorld()->SpawnActor<ACoal>(SpawnLoc, SpawnRot, SpawnParams);
						}
						else if (rand() % 50 == 1)
						{
							Chunk[i][j][k] = GetWorld()->SpawnActor<AIron>(SpawnLoc, SpawnRot, SpawnParams);
						}
						else if (rand() % 500 == 1)
						{
							Chunk[i][j][k] = GetWorld()->SpawnActor<AGold>(SpawnLoc, SpawnRot, SpawnParams);
						}
						else if (rand() % 1000 == 1)
						{
							Chunk[i][j][k] = GetWorld()->SpawnActor<ADiamon>(SpawnLoc, SpawnRot, SpawnParams);
						}
						else
							Chunk[i][j][k] = GetWorld()->SpawnActor<ACobble>(SpawnLoc, SpawnRot, SpawnParams);
					}

					else if (layerPrinted > 10)

					{

						if (rand() % 20 == 1)
						{
							Chunk[i][j][k] = GetWorld()->SpawnActor<ACoal>(SpawnLoc, SpawnRot, SpawnParams);
						}
						else if (rand() % 30 == 1)
						{
							Chunk[i][j][k] = GetWorld()->SpawnActor<AIron>(SpawnLoc, SpawnRot, SpawnParams);
						}
						else if (rand() % 100 == 1)
						{
							Chunk[i][j][k] = GetWorld()->SpawnActor<AGold>(SpawnLoc, SpawnRot, SpawnParams);
						}
						else if (rand() % 500 == 1)
						{
							Chunk[i][j][k] = GetWorld()->SpawnActor<ADiamon>(SpawnLoc, SpawnRot, SpawnParams);
						}
						else
							Chunk[i][j][k] = GetWorld()->SpawnActor<ACobble>(SpawnLoc, SpawnRot, SpawnParams);
					}

					else

					if (rand() % 50 == 1)

					{
						Chunk[i][j][k] = GetWorld()->SpawnActor<ACoal>(SpawnLoc, SpawnRot, SpawnParams);
					}
					else if (rand() % 10 == 1)
					{
						Chunk[i][j][k] = GetWorld()->SpawnActor<AIron>(SpawnLoc, SpawnRot, SpawnParams);
					}
					else if (rand() % 20 == 1)
					{
						Chunk[i][j][k] = GetWorld()->SpawnActor<AGold>(SpawnLoc, SpawnRot, SpawnParams);
					}
					else if (rand() % 50 == 1)
					{
						Chunk[i][j][k] = GetWorld()->SpawnActor<ADiamon>(SpawnLoc, SpawnRot, SpawnParams);
					}
					else
					Chunk[i][j][k] = GetWorld()->SpawnActor<ACobble>(SpawnLoc, SpawnRot, SpawnParams);

				Chunk[i][j][k]->SetActorScale3D(VoxalScale);

				SpawnLoc.X += (BaseVoxalMeasuement *100);

				VoxelCount++;
			}
			SpawnLoc.X -= ChunkX * (BaseVoxalMeasuement * 100);
			SpawnLoc.Y += (BaseVoxalMeasuement*100);
		}
		SpawnLoc.Y -= ChunkY* (BaseVoxalMeasuement * 100);
		SpawnLoc.Z += (BaseVoxalMeasuement * 100);
		layerPrinted++;
	}
	

	/*if (GEngine) GEngine->AddOnScreenDebugMessage(4, 10.f, FColor::Black,
		FString::Printf(TEXT("We have %d number of Voxels"), VoxelCount));*/
}

// Called every frame
void AChunk::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

