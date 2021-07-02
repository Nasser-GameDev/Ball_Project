// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CoinSpawningSystem.generated.h"

UCLASS()
class BALLMOVEMENT_API ACoinSpawningSystem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACoinSpawningSystem();
	UPROPERTY(EditAnywhere , Category = "Street Properties")
	float Spacing = 600.0f;
	// for spawing our actor 
	UPROPERTY(EditDefaultsOnly , Category = "Spline")
	TSubclassOf<class APickUp> CoinWeAreSpawning;
	// the spline component 
	UPROPERTY(EditAnywhere , BlueprintReadWrite , Category = "Spline")
	class USplineComponent* SplineComponent;
	UPROPERTY(EditAnywhere , BlueprintReadWrite , Category = "Spline")
	UStaticMesh* RenderedPlaceHolderMesh;
	void OnConstruction(const FTransform& Transform)override;
	UPROPERTY(VisibleAnywhere , Category = "Spline")
	TArray<UStaticMeshComponent*>CoinCollection;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
