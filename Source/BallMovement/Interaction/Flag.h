// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractionBase.h"
#include "Flag.generated.h"

/**
 * 
 */
UCLASS()
class BALLMOVEMENT_API AFlag : public AInteractionBase
{
	GENERATED_BODY()
	public:
	AFlag();
	class URotatingMovementComponent* RotatingMovement;
	virtual void Interact(class  ABall_Charecter_CPP* OverlappingBall) override;
};

