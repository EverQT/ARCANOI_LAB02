// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Ship.generated.h"

class UFloatingPawnMovement;

UCLASS()
class ARCANOI_LAB02_API AShip : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AShip();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)		//visible editar en el blueprint
		UStaticMeshComponent* SM_Ship;					//Compnentes para crear la mascara para vestir al actor //SM manejar modelos estaticos

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UFloatingPawnMovement* FloatingMovement;		//como se va mover

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void Move(float _AxisValue);				//virtual clases hijas puedan modificar

	virtual void MoveA(float _XAxisValue);

	virtual void MoveB(float _ZAxisValue);

	//void MoveRight(float amount);
	//void MoveForward(float amount);

};
