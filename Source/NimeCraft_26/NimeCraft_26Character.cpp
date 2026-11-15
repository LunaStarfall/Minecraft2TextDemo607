// Copyright Epic Games, Inc. All Rights Reserved.

#include "NimeCraft_26Character.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "NimeCraft_26.h"

ANimeCraft_26Character::ANimeCraft_26Character()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);
	
	// Create the first person mesh that will be viewed only by this character's owner
	FirstPersonMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("First Person Mesh"));

	FirstPersonMesh->SetupAttachment(GetMesh());
	FirstPersonMesh->SetOnlyOwnerSee(true);
	FirstPersonMesh->FirstPersonPrimitiveType = EFirstPersonPrimitiveType::FirstPerson;
	FirstPersonMesh->SetCollisionProfileName(FName("NoCollision"));

	// Create the Camera Component	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("First Person Camera"));
	FirstPersonCameraComponent->SetupAttachment(FirstPersonMesh, FName("head"));
	FirstPersonCameraComponent->SetRelativeLocationAndRotation(FVector(-2.8f, 5.89f, 0.0f), FRotator(0.0f, 90.0f, -90.0f));
	FirstPersonCameraComponent->bUsePawnControlRotation = true;
	FirstPersonCameraComponent->bEnableFirstPersonFieldOfView = true;
	FirstPersonCameraComponent->bEnableFirstPersonScale = true;
	FirstPersonCameraComponent->FirstPersonFieldOfView = 70.0f;
	FirstPersonCameraComponent->FirstPersonScale = 0.6f;

	// configure the character comps
	GetMesh()->SetOwnerNoSee(true);
	GetMesh()->FirstPersonPrimitiveType = EFirstPersonPrimitiveType::WorldSpaceRepresentation;

	GetCapsuleComponent()->SetCapsuleSize(34.0f, 96.0f);

	// Configure character movement
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;
	GetCharacterMovement()->AirControl = 0.5f;
}

void ANimeCraft_26Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{	
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ANimeCraft_26Character::DoJumpStart);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ANimeCraft_26Character::DoJumpEnd);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ANimeCraft_26Character::MoveInput);

		// Looking/Aiming
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ANimeCraft_26Character::LookInput);
		EnhancedInputComponent->BindAction(MouseLookAction, ETriggerEvent::Triggered, this, &ANimeCraft_26Character::LookInput);

		// Mining
		EnhancedInputComponent->BindAction(MineAction, ETriggerEvent::Started, this, &ANimeCraft_26Character::DoMineStart);
		EnhancedInputComponent->BindAction(MineAction, ETriggerEvent::Completed, this, &ANimeCraft_26Character::DoMineEnd);
	}
	else
	{
		UE_LOG(LogNimeCraft_26, Error, TEXT("'%s' Failed to find an Enhanced Input Component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}


void ANimeCraft_26Character::MoveInput(const FInputActionValue& Value)
{
	// get the Vector2D move axis
	FVector2D MovementVector = Value.Get<FVector2D>();

	// pass the axis values to the move input
	DoMove(MovementVector.X, MovementVector.Y);

	if (GEngine) GEngine->AddOnScreenDebugMessage(1, 2.f, FColor::Green, FString::Printf(TEXT("I'm Moving!")));
	

}

void ANimeCraft_26Character::LookInput(const FInputActionValue& Value)
{
	// get the Vector2D look axis
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	// pass the axis values to the aim input
	DoAim(LookAxisVector.X, LookAxisVector.Y);

	if (GEngine) GEngine->AddOnScreenDebugMessage(2, 2.f, FColor::Cyan, FString::Printf(TEXT("I'm Looking!")));

}

void ANimeCraft_26Character::DoAim(float Yaw, float Pitch)
{
	if (GetController())
	{
		// pass the rotation inputs
		AddControllerYawInput(Yaw);
		AddControllerPitchInput(Pitch);
	}
}

void ANimeCraft_26Character::DoMove(float Right, float Forward)
{
	if (GetController())
	{
		// pass the move inputs
		AddMovementInput(GetActorRightVector(), Right);
		AddMovementInput(GetActorForwardVector(), Forward);
	}
}

void ANimeCraft_26Character::DoJumpStart()
{
	// pass Jump to the character
	Jump();

	if (GEngine) GEngine->AddOnScreenDebugMessage(3, 2.f, FColor::Magenta, FString::Printf(TEXT("I'm Jumping!")));
}

void ANimeCraft_26Character::DoJumpEnd()
{
	// pass StopJumping to the character
	StopJumping();
}

void ANimeCraft_26Character::DoMineStart()
{
	if (GEngine) GEngine->AddOnScreenDebugMessage(5, 2.f, FColor::Yellow, FString::Printf(TEXT("Mining!")));

	TraceFoward();
}

void ANimeCraft_26Character::DoMineEnd()
{
	//if (GEngine) GEngine->AddOnScreenDebugMessage(5, 2.f, FColor::Red, FString::Printf(TEXT("Stop Mining!")));
}

void ANimeCraft_26Character::TraceFoward()
{
	FVector PlayerLocation;
	FRotator PlayerRotation;

	GetController()->GetPlayerViewPoint(PlayerLocation, PlayerRotation);

	FVector LineTraceStart = PlayerLocation;
	FVector LineTraceEnd = LineTraceStart + (PlayerRotation.Vector() * 400);
	FHitResult HitByLineTrace;
	FCollisionQueryParams LinetraceParams;
	bool bHit;

	bHit = GetWorld()->LineTraceSingleByChannel(HitByLineTrace, LineTraceStart, LineTraceEnd, ECC_Visibility, LinetraceParams);
	
	DrawDebugLine(GetWorld(), LineTraceStart, LineTraceEnd, FColor::Red, false, 2.0f);

	if (bHit)
	{
		if (GEngine) GEngine->AddOnScreenDebugMessage(5, 2.0f, FColor::Red, FString::Printf(TEXT("You hit %s"), *HitByLineTrace.GetActor()->GetName()));

		DrawDebugBox(GetWorld(), HitByLineTrace.ImpactPoint, FVector(5, 5, 5), FColor::Red, false, 2.0f);

		if (HitByLineTrace.GetActor()->GetClass()->ImplementsInterface(UInteractionInterfact::StaticClass()))
		{
			Cast<IInteractionInterfact>(HitByLineTrace.GetActor())->PlayerInteract();
			
		}
	}
}
