// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Voxel.h"
#include "Iron.generated.h"

/**
 * 
 */
UCLASS()
class NIMECRAFT_26_API AIron : public AVoxel
{
	GENERATED_BODY()
	
private:
	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	TObjectPtr<UMaterial> Iron;


public:

	AIron();
};
