// Fill out your copyright notice in the Description page of Project Settings.


#include "PickUp.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "Components/SphereComponent.h"
#include "Components/TimelineComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "../Ball_Charecter_CPP.h"
APickUp::APickUp() 
{
    RootComponent = StaticMesh;
    RotatingMovement = CreateDefaultSubobject<URotatingMovementComponent>(TEXT(" Rotating Coin"));
    MagnaticCollider = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere to detect if the ball is close to our actor "));
    MagnaticCollider->InitSphereRadius(400.0f);
    MagnaticCollider->OnComponentBeginOverlap.AddDynamic(this, &APickUp::OnOverlapBegin);
    MagnaticCollider->SetupAttachment(StaticMesh);
    TimeLineComponent = CreateDefaultSubobject<UTimelineComponent>(TEXT(" gives us the ability to start our timeline "));
}

void APickUp::Interact(class  ABall_Charecter_CPP* OverlappingBall) 
{
   Super::Interact(OverlappingBall);
   Destroy();
}

void APickUp::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) 
{
    GEngine->AddOnScreenDebugMessage(0, 5, FColor::Magenta, FString::Printf(TEXT("Overlapping with Sphere")));
	if(OtherActor && (OtherActor != this) && OtherComp)
	{
		ABall_Charecter_CPP* OverlappingBall = Cast<ABall_Charecter_CPP>(OtherActor);
		if(OverlappingBall && GetWorld())
		{
            OverlappingCPPBall = OverlappingBall;
            TimeLineComponent->PlayFromStart(); // starting timeline
		}
	}
}

void APickUp::BeginPlay() 
{
   Super::BeginPlay();
   // if this is defined that means it was assigned in the editor
   if(MagnaticCurveAsset)
   {
       ValuesFromCurve.BindUFunction(this , FName("TimeLineUpdate"));
        TimeLineComponent->AddInterpFloat(MagnaticCurveAsset , ValuesFromCurve , FName("Alpha"));
        TimeLineComponent->SetLooping(true);
        TimeLineComponent->SetIgnoreTimeDilation(true);
   }
}

void APickUp::TimeLineUpdate(float Percentage) 
{
    if(OverlappingCPPBall)
    {
        FVector NewLocation = FMath::Lerp(GetActorLocation() , OverlappingCPPBall->GetActorLocation() , Percentage);
        SetActorLocation(NewLocation);
    }
}

