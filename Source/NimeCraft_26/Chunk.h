// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Voxel.h"
#include "Dirt.h"
#include "Grass.h"
#include "Cobble.h"
#include "Coal.h"
#include "Iron.h"
#include "Gold.h"
#include "Diamon.h"
#include "Chunk.generated.h"

constexpr int ChunkX = 20;
constexpr int ChunkY = 20;
constexpr int ChunkZ = 30;





UCLASS()
class NIMECRAFT_26_API AChunk : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChunk();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chunk")
	float BaseVoxalMeasuement = 1.0f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	AVoxel* Chunk[ChunkX][ChunkY][ChunkZ];

	FVector SpawnLoc;
	FRotator SpawnRot;
	FActorSpawnParameters SpawnParams; 

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
