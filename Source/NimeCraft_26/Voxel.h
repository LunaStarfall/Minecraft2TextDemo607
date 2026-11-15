// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractionInterfact.h"
#include "Voxel.generated.h"

UCLASS()
class NIMECRAFT_26_API AVoxel : public AActor, public IInteractionInterfact
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVoxel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Mesh")
	TObjectPtr<UStaticMeshComponent> BaseVoxelMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Mesh")
	TObjectPtr<UMaterial> BaseVoxelMat;

	UFUNCTION()
	virtual void PlayerInteract() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
