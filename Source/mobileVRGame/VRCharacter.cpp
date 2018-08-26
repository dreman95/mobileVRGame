// Fill out your copyright notice in the Description page of Project Settings.

#include "VRCharacter.h"
#include <Camera/CameraComponent.h>
#include <GameFramework/Actor.h>
#include <Components/StaticMeshComponent.h>






// Sets default values
AVRCharacter::AVRCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CurrentTime = 0.f;
	xCord = 0.f;

	camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	camera->SetupAttachment(GetRootComponent());

	SpawnComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DestinationMarker"));
	SpawnComp->SetupAttachment(GetRootComponent());

	
	
	


}

// Called when the game starts or when spawned
void AVRCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVRCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//keep track of our current time 
	CurrentTime = CurrentTime + 1 * DeltaTime;

}

// Called to bind functionality to input
void AVRCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("Forward"), this, &AVRCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("Right"), this, &AVRCharacter::MoveRight);
	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &AVRCharacter::Fire);

}

void AVRCharacter::MoveRight(float throttle)
{
	AddMovementInput(throttle * camera->GetRightVector());
}

void AVRCharacter::MoveForward(float throttle)
{
	AddMovementInput(throttle * camera->GetForwardVector());
}

void AVRCharacter::Fire()
{
	UE_LOG(LogTemp, Warning, TEXT("Firing!!!!"));


	

	//create spawn params;
	FActorSpawnParameters SpawnParams;

	//Who does the spawning: we are saying this class does the spawning.
	SpawnParams.Owner = this;

	//Who can do damage to this object: set to default.
	SpawnParams.Instigator = Instigator;
	OurLoc = camera->GetComponentLocation();
	
	//Spawn our object
	AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(ourSpawningObject, OurLoc, camera->GetComponentRotation(), SpawnParams);
	
	FVector NewVelocity = GetActorForwardVector() * 5000.f;
	Projectile->Velocity = FVector();

	}

