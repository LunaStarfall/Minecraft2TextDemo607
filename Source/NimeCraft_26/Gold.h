// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Voxel.h"
#include "Gold.generated.h"

/**
 * 
 */
UCLASS()
class NIMECRAFT_26_API AGold : public AVoxel
{
	GENERATED_BODY()
private:
	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	TObjectPtr<UMaterial> Gold;


public:

	AGold();
};
