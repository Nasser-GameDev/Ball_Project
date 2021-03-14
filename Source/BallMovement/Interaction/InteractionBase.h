// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractionBase.generated.h"

UCLASS()
class BALLMOVEMENT_API AInteractionBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractionBase();
	UPROPERTY(EditAnywhere ,BlueprintReadWrite)
	class UStaticMeshComponent* StaticMesh;
	UFUNCTION()
	void WhenTouching(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	virtual void Interact(class  ABall_Charecter_CPP* OverlappingBall);

	UPROPERTY()
	class ABall_Charecter_CPP* OverlappingBallCharecter;
};
