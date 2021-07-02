// Fill out your copyright notice in the Description page of Project Settings.


#include "CoinSpawningSystem.h"
#include "Components/SplineComponent.h"
#include "../Interaction/PickUp.h"
// Sets default values
ACoinSpawningSystem::ACoinSpawningSystem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	SplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("Our spline Component"));
	if(SplineComponent)
	{
		RootComponent = SplineComponent;
	}
}

// Not necessary Unless you are being super nice to your level desginer 
void ACoinSpawningSystem::OnConstruction(const FTransform& Transform) 
{
	// this will be true when the user hasn't assined any mesh within the editor 
	if(RenderedPlaceHolderMesh == nullptr )
	{
		return;
	}
	// We Want to Clear the Coin Array so it only save the place holder meshes from the last run of the construction script 
	CoinCollection.Empty();
	for (int index = 0 ; index <= FGenericPlatformMath::TruncToInt(SplineComponent->GetSplineLength() / Spacing )  ; index++)
	{
		UStaticMeshComponent* PlaceHolderMesh = NewObject<UStaticMeshComponent>(this , UStaticMeshComponent::StaticClass());
		// allowing our mesh coins to move with the spline 
		PlaceHolderMesh->SetMobility(EComponentMobility::Movable);
		// Letting our Engine know that our mesh component is being Created in the construction script 
		PlaceHolderMesh->CreationMethod = EComponentCreationMethod::UserConstructionScript;

		PlaceHolderMesh->RegisterComponentWithWorld(GetWorld());
		// Attaching our mesh to our spline 
		PlaceHolderMesh->AttachToComponent(SplineComponent , FAttachmentTransformRules::KeepRelativeTransform);

		// Gets us the position of our coin withing the mesh 
		FVector CoinLocation = SplineComponent->GetLocationAtDistanceAlongSpline(index * Spacing , ESplineCoordinateSpace::Local);
		FRotator CoinRotation = SplineComponent->GetRotationAtDistanceAlongSpline(index * Spacing , ESplineCoordinateSpace::Local);
		// Varing the loactoin and rotation of each coin based off where it lives within the spline 
		PlaceHolderMesh->SetRelativeLocation(CoinLocation);
		PlaceHolderMesh->SetRelativeRotation(CoinRotation);
		// Rendering our mesh into the level
		PlaceHolderMesh->SetStaticMesh(RenderedPlaceHolderMesh);
		// Adding an element within our array 
		CoinCollection.Emplace(PlaceHolderMesh);
	}
}

// To Spawn our pick up actors 
void ACoinSpawningSystem::BeginPlay()
{
	Super::BeginPlay();
	// Deleting all the place holder meshes that we had stored in our array 
	for (UStaticMeshComponent* MeshCoin : CoinCollection)
	{
		MeshCoin->DestroyComponent();
	}
	for (int index = 0 ; index <=  FGenericPlatformMath::TruncToInt(SplineComponent->GetSplineLength() / Spacing ) ; index++)	
	{
		if(GetWorld())
		{
			FVector CoinLocation = SplineComponent->GetLocationAtDistanceAlongSpline(index * Spacing ,ESplineCoordinateSpace::World );
			FRotator CoinRotation = SplineComponent->GetRotationAtDistanceAlongSpline(index * Spacing ,ESplineCoordinateSpace::World);
			if(CoinWeAreSpawning)
			{
				FActorSpawnParameters SpawnParams;
				GetWorld()->SpawnActor<APickUp>(CoinWeAreSpawning, CoinLocation , CoinRotation , SpawnParams);
			}

		}
	}
}



