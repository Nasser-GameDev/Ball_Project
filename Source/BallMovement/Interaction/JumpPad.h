// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractionBase.h"
#include "JumpPad.generated.h"

/**
 * 
 */
UCLASS()
class BALLMOVEMENT_API AJumpPad : public AInteractionBase
{
	GENERATED_BODY()
	public:
	virtual void Interact(class  ABall_Charecter_CPP* OverlappingBall) override;
};
