// Fill out your copyright notice in the Description page of Project Settings.

#include "VRCharacter.h"
#include "Projectile.h"
#include <Camera/CameraComponent.h>
#include <GameFramework/Actor.h>
#include <Engine/World.h>
#include <Components/StaticMeshComponent.h>






// Sets default values
AVRCharacter::AVRCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

	////spawn projectile at the location of the character
	//const FRotator SpawnRotation = camera->GetComponentRotation();
	//const FVector SpawnLocation = camera->GetComponentLocation();

	//auto Projectile = GetWorld()->SpawnActor<AProjectile>(AProjectile::StaticClass(), SpawnLocation, SpawnRotation);
	//

	//Projectile->LaunchProjectile(LaunchSpeed);

	UWorld* const World = GetWorld();
	World->SpawnActor<AProjectile>(ProjectileClass, SpawnComp->GetSocketLocation(FName("ProjectileSocket")), SpawnComp->GetSocketRotation(FName("ProjectileSocket")));


	if (ProjectileClass != NULL)
	{
		UWorld* const World = GetWorld();
		if (World != NULL)
		{

			const FRotator SpawnRotation = GetControlRotation();
			const FVector SpawnLocation = camera->GetComponentLocation();

			//Set Spawn Collision Handling Override
			FActorSpawnParameters ActorSpawnParams;
			ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

			// spawn the projectile at the muzzle
			World->SpawnActor<AProjectile>(ProjectileClass, SpawnComp->GetSocketLocation(FName("ProjectileSocket")), SpawnComp->GetSocketRotation(FName("ProjectileSocket")));
		}
	}
}

