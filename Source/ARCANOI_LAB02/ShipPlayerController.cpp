// Fill out your copyright notice in the Description page of Project Settings.


#include "ShipPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"
#include "Ship.h"

AShipPlayerController::AShipPlayerController()
{
}


void AShipPlayerController::BeginPlay()
{

	TArray<AActor*> CameraActors;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), CameraActors);

	FViewTargetTransitionParams Params;
	SetViewTarget(CameraActors[0], Params);

}


void AShipPlayerController::SetupInputComponent()
{

	Super::SetupInputComponent();
	EnableInput(this);

	InputComponent->BindAxis("Move", this, &AShipPlayerController::Move);
	InputComponent->BindAxis("MoveA", this, &AShipPlayerController::MoveA);
	InputComponent->BindAxis("MoveB", this, &AShipPlayerController::MoveB);

	//InputComponent->BindAxis("MoveR", this, &AShipPlayerController::MoveRight);
	//InputComponent->BindAxis("MoveF", this, &AShipPlayerController::MoveForward);

}

void AShipPlayerController::Move(float _AxisValue)
{
	auto MyPawn = Cast<AShip>(GetPawn());
	if (MyPawn) {
		MyPawn->Move(_AxisValue);
	}
}

void AShipPlayerController::MoveA(float _XAxisValue)
{
	auto MyPawn = Cast<AShip>(GetPawn());
	if (MyPawn) {
		MyPawn->MoveA(_XAxisValue);
	}
}

void AShipPlayerController::MoveB(float _ZAxisValue)
{
	auto MyPawn = Cast<AShip>(GetPawn());
	if (MyPawn) {
		MyPawn->MoveB(_ZAxisValue);
	}
}

//void AShipPlayerController::MoveRight()
//{
//}

//void AShipPlayerController::MoveForward()
//{
//}