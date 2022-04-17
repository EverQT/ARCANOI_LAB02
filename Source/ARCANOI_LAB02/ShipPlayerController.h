// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ShipPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ARCANOI_LAB02_API AShipPlayerController : public APlayerController
{
	GENERATED_BODY()

		AShipPlayerController();

	UFUNCTION()
		virtual void SetupInputComponent() override;

protected:

	virtual void BeginPlay() override;
	void Move(float _AxisValue);
	void MoveA(float _XAxisValue);
	void MoveB(float _ZAxisValue);
	//void MoveRight();
	//void MoveForward();

};
