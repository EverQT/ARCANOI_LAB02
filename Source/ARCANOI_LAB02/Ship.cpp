// Fill out your copyright notice in the Description page of Project Settings.


#include "Ship.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AShip::AShip()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SM_Ship = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM_Ship"));		//Create visualizar el puntero
	RootComponent = SM_Ship;														//visualizar la raiz en blueprint

	SM_Ship->SetEnableGravity(false);												//on , of la gravedad
	SM_Ship->SetConstraintMode(EDOFMode::XZPlane);									//trabaje en el plano X y Y
	SM_Ship->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);				//reacion al colisionar
	SM_Ship->SetCollisionProfileName(TEXT("PhysicActor"));							//nombre a la configuracion de colision
	
	FloatingMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("FloatinPawnMovement"));

}

// Called when the game starts or when spawned
void AShip::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AShip::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//InputComponent->BindAxis("MoveR", this, &AShipPlayerController::MoveRight);
	//InputComponent->BindAxis("MoveF", this, &AShipPlayerController::MoveForward);

}

void AShip::Move(float _AxisValue)
{
	AddMovementInput(FVector (_AxisValue, 0.0f, 0.0f), 1.0f, false);				//Agregar objetos de entrada //genera movimiento con el valor que recoge
}

void AShip::MoveA(float _XAxisValue)
{
	AddMovementInput(FVector(_XAxisValue), 1.0f, false);
}

void AShip::MoveB(float _ZAxisValue)
{
	AddMovementInput(FVector(_ZAxisValue), 1.0f, false);
}


//void AShip::MoveRight(float amount)
//{
//	if (Controller && amount) {
//		AddMovementInput(GetActorRightVector(), amount);
//	}
//}

//void AShip::MoveForward(float amount)
//{
//	if (Controller && amount) {
//		AddMovementInput(GetActorForwardVector(), amount);
//	}
//}

