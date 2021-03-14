// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractionBase.h"
#include "Components/TimelineComponent.h"
#include "PickUp.generated.h"
/**
 * 
 */
UCLASS()
class BALLMOVEMENT_API APickUp : public AInteractionBase
{
	GENERATED_BODY()
	public:
	APickUp(); // to create our components
	UPROPERTY(BlueprintReadWrite)
	class URotatingMovementComponent* RotatingMovement;
	virtual void Interact(class  ABall_Charecter_CPP* OverlappingBall) override;
	UPROPERTY(EditAnywhere , BlueprintReadWrite)
	class USphereComponent* MagnaticCollider;
	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UPROPERTY(EditAnywhere , BlueprintReadWrite)
	class UCurveFloat* MagnaticCurveAsset; // gets assginged in the editor 
	class UTimelineComponent* TimeLineComponent; // responsible for starting the timeline 
	FOnTimelineFloat ValuesFromCurve;
	void BeginPlay() override;
	UFUNCTION()
	void TimeLineUpdate(float Percentage);
	class ABall_Charecter_CPP* OverlappingCPPBall;
};
