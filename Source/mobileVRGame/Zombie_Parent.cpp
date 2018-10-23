// Fill out your copyright notice in the Description page of Project Settings.

#include "Zombie_Parent.h"


// Sets default values
AZombie_Parent::AZombie_Parent()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AZombie_Parent::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AZombie_Parent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AZombie_Parent::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

//void AZombie_Parent::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
//{
//  //GLog->Log(*OtherActor->GetName());
//}
//
//void AZombie_Parent::ReceiveHit(UPrimitiveComponent* MyComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
//{
//  //GLog->Log(*OtherActor->GetName());
//}
