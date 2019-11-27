// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/PlayerPawn.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"
// Sets default values
APlayerPawn::APlayerPawn(const FObjectInitializer& ObjectInitializer):Super(ObjectInitializer)
{
	StaticMeshComponent = ObjectInitializer.CreateAbstractDefaultSubobject<UStaticMeshComponent>(this, TEXT("StaticMesh"));
	
	if (StaticMeshComponent != nullptr)
	{
		RootComponent = StaticMeshComponent;
	}
	static ConstructorHelpers::FObjectFinder<UStaticMesh>PlayerMeshObj(TEXT("/Game/SM_Player.SM_Player"));

	if (PlayerMeshObj.Succeeded())
	{
		StaticMeshComponent->SetStaticMesh(PlayerMeshObj.Object);
	}
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

FVector APlayerPawn::GetPlayerMoveDirection(float Direction)const
{
	return (FVector(10.0f, 0.0f, 0.0f) * Direction) + GetActorLocation();
}

