// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Ball_Charecter_CPP.generated.h"

UCLASS()
class BALLMOVEMENT_API ABall_Charecter_CPP : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABall_Charecter_CPP();
	UStaticMeshComponent* GetStaticMesh(){return StaticMesh;}
	UPROPERTY(EditAnywhere , BlueprintReadWrite)
	class UStaticMeshComponent* StaticMesh;
	UPROPERTY(EditAnywhere , BlueprintReadWrite)
	class USpringArmComponent* SpringArm;
	UPROPERTY(EditAnywhere , BlueprintReadWrite)
	class UCameraComponent* CameraComponent;
public:	
// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void MoveForward(float value);
	void MoveRight(float value);
	void TurnFunction(float value);
	void LookUpFunction(float value);
};
