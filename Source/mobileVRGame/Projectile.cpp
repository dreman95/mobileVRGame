// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "GameFramework/MovementComponent.h"
#include "WorldCollision.h"
#include "DrawDebugHelpers.h"



// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ProjectileObject = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Projectile"));
	ProjectileObject->SetupAttachment(GetRootComponent());

	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	RootComponent = RootComp;

	// Use a sphere as a simple collision representation
	/*CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(5.0f);
	CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");*/

	// Set as root component
	//RootComponent = CollisionComp;

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Projectile Movement"));
	ProjectileMovement->bAutoActivate = false;
	//ProjectileMovement->setupdatedcomponent(collisioncomp);



}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FHitResult HitResult;
	FVector StartTrace = this->GetActorLocation();
	FVector EndTrace = (Velocity * DeltaTime) + StartTrace;
	EndTrace.Z += this->GetActorRotation().Pitch;
	FCollisionQueryParams collisionParams;
	collisionParams.AddIgnoredActor(this);

	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartTrace, EndTrace, ECC_Destructible, collisionParams)) {

		//whenever we hit a wall it draws a box on the screen
		if (HitResult.GetActor()) {
			DrawDebugSolidBox(GetWorld(), HitResult.ImpactPoint, FVector(10.f), FColor::Blue, true);
			
			 
		}else {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Could not get mesh, type is: %s"), *HitResult.GetActor()->StaticClass()->GetFName().ToString()));
		}

		Destroy();

	}
	else {
		BulletExpiry += DeltaTime;

		DrawDebugLine(GetWorld(), StartTrace, EndTrace, FColor(0.f, -BulletExpiry * 80.f, 100.f), true);

		SetActorLocation(EndTrace);

		Velocity += FVector(0.f, 0.f, -200);
	}
	if (BulletExpiry > 3) {
		Destroy();
	}
	

}

void AProjectile::LaunchProjectile(float speed)
{
	UE_LOG(LogTemp, Warning, TEXT("Projectile Firing "));
	ProjectileMovement->SetVelocityInLocalSpace(FVector::ForwardVector * speed);
	ProjectileMovement->Activate();
	
	
	
}

