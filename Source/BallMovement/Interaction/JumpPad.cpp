// Fill out your copyright notice in the Description page of Project Settings.


#include "JumpPad.h"

#include "../Ball_Charecter_CPP.h"

void AJumpPad::Interact(class  ABall_Charecter_CPP* OverlappingBall) 
{
   Super::Interact(OverlappingBall); // doing this so it draws spheres on the point of interaction
    GEngine->AddOnScreenDebugMessage(0, 0.f, FColor::Blue, FString::Printf(TEXT("Jump Pad interact beign called")));
   float BallHeight = 1300.f; // how much force gets applied in the upward direction
   FVector ForceVector(0 , 0 , BallHeight);
   FName RandomBone = FName("None");
   OverlappingBall->GetStaticMesh()->AddImpulse(ForceVector , RandomBone , true);
}
