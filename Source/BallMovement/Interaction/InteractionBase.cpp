// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractionBase.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Components/StaticMeshComponent.h" 
#include "../Ball_Charecter_CPP.h"
// Sets default values
AInteractionBase::AInteractionBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	StaticMesh->SetCollisionProfileName(TEXT("Overlap All")); //any actor can overlap with our static mesh
	// AInteractionBase* randomActor = this;
	StaticMesh->OnComponentBeginOverlap.AddDynamic(this, &AInteractionBase::WhenTouching);
}

void AInteractionBase::WhenTouching(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) 
{
	GEngine->AddOnScreenDebugMessage(0, 5, FColor::Magenta, FString::Printf(TEXT("When Touching function being called")));
	if(OtherActor && (OtherActor != this) && OtherComp)
	{
		ABall_Charecter_CPP* OverlappingBall = Cast<ABall_Charecter_CPP>(OtherActor);
		if(OverlappingBall && GetWorld())
		{
			OverlappingBallCharecter = OverlappingBall;
			Interact(OverlappingBall);
		}
		else 
		{
			GEngine->AddOnScreenDebugMessage(0, 1, FColor::Blue, FString::Printf(TEXT("The actor could not be casted to a ball")));
		}
	}
}

void AInteractionBase::Interact(class  ABall_Charecter_CPP* OverlappingBall) 
{
	
	UKismetSystemLibrary::DrawDebugSphere(GetWorld() , OverlappingBall->GetActorLocation() , 10 , 12 , FColor::White , 4 , 2 );
}


	



