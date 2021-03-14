// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball_Charecter_CPP.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
// Sets default values
ABall_Charecter_CPP::ABall_Charecter_CPP()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	AutoPossessPlayer = EAutoReceiveInput::Player0;
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera "));
	RootComponent = StaticMesh;
	SpringArm->SetupAttachment(StaticMesh);
	CameraComponent->SetupAttachment(SpringArm , USpringArmComponent::SocketName);
	SpringArm->bUsePawnControlRotation = true;
}


// Called every frame

// Called to bind functionality to input
void ABall_Charecter_CPP::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForwardOrBackwords", this, &ABall_Charecter_CPP::MoveForward);
	InputComponent->BindAxis("MoveRightOrLeft", this, &ABall_Charecter_CPP::MoveRight);
	InputComponent->BindAxis("Turn", this, &ABall_Charecter_CPP::TurnFunction);
	InputComponent->BindAxis("LookUp", this, &ABall_Charecter_CPP::LookUpFunction);
}

void ABall_Charecter_CPP::MoveForward(float value) 
{	
	FVector ForceVector = CameraComponent->GetForwardVector();
	FName BoneName = TEXT("None");
	ForceVector.X = ForceVector.X * value * 500.0f;
	ForceVector.Y = ForceVector.Y * value * 500.0f;
	UE_LOG(LogTemp, Warning, TEXT("Force vector is %s") , *ForceVector.ToString());
	StaticMesh->AddForce(ForceVector ,BoneName , true );

}

void ABall_Charecter_CPP::MoveRight(float value) 
{
	FVector ForceVector = CameraComponent->GetRightVector();
	FName BoneName = TEXT("None");
	ForceVector.X = ForceVector.X * value * 500.0f;
	ForceVector.Y = ForceVector.Y * value * 500.0f;
	UE_LOG(LogTemp, Warning, TEXT("Force vector is %s") , *ForceVector.ToString());
	StaticMesh->AddForce(ForceVector ,BoneName , true );
	
}

void ABall_Charecter_CPP::TurnFunction(float value) 
{
	
	// GEngine->AddOnScreenDebugMessage(0, 0.f, FColor::Magenta, FString::Printf(TEXT("value is %f") , value));	
	AddControllerYawInput(value);
}

void ABall_Charecter_CPP::LookUpFunction(float value) 
{
	// GEngine->AddOnScreenDebugMessage(0, 0.f, FColor::Magenta, FString::Printf(TEXT("value is %f") , value));	
	AddControllerPitchInput(value);
}

