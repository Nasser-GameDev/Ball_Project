// Fill out your copyright notice in the Description page of Project Settings.


#include "Flag.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "../Ball_Charecter_CPP.h"

AFlag::AFlag() 
{
    RotatingMovement   = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("Rotating flag"));
    RootComponent = StaticMesh;
    
}
void AFlag::Interact(class  ABall_Charecter_CPP* OverlappingBall) 
{
    Super::Interact(OverlappingBall);
    GEngine->AddOnScreenDebugMessage(0, 10, FColor::Orange, FString::Printf(TEXT("You Reached The end of the level")));
}

