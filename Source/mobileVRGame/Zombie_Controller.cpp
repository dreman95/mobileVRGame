// Fill out your copyright notice in the Description page of Project Settings.

#include "Zombie_Controller.h"
#include "Engine.h"
#include "Components/BoxComponent.h"


// Sets default values
AZombie_Controller::AZombie_Controller()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

  //Initialize a StaticMeshComponent
  //SM = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeSM"));

  ////Enable physics so the cube will fall
  //SM->SetSimulatePhysics(true);

  //You only need to register the OnHit function
  //SM->OnComponentHit.AddDynamic(this, &AZombie_Controller::OnHit);

  // Use a sphere as a simple collision representation
  MyComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
  //MyComp->SetSimulatePhysics(true);
  MyComp->SetNotifyRigidBodyCollision(true);
  //MyComp->BodyInstance.SetCollisionProfileName("BlockAllDynamic");
  MyComp->OnComponentHit.AddDynamic(this, &AZombie_Controller::OnCompHit);

  // Set as root component
  RootComponent = MyComp;
}

// Called when the game starts or when spawned
void AZombie_Controller::BeginPlay()
{
	Super::BeginPlay();
	
  // Create Spawn params 
  FActorSpawnParameters spawnParams;
  
  // who did the spawn, and we are say this controller did 
  spawnParams.Owner = this;

  // Set the instigator to default 
  spawnParams.Instigator = Instigator;

  // gen a new X, Y 
  FVector location0 = FVector(360., -0., 90.);
  AZombie_Parent* ourNewObject = GetWorld()->SpawnActor<AZombie_Parent>(ourSpawningObject, location0, FRotator::ZeroRotator, spawnParams);



}

// Called every frame
void AZombie_Controller::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AZombie_Controller::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

////FActorHitSignature AZombie_Controller::OnActorHit
////void AFallingActor::OnHit(AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)void AZombie_Controller::OnHit(AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
//void AZombie_Controller::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
//{
//  //GLog->Log(*OtherActor->GetName());
//}
//
//void AZombie_Controller::ReceiveHit(UPrimitiveComponent* MyComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
//{
//  //GLog->Log(*OtherActor->GetName());
//}


void AZombie_Controller::OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
  if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL))
  {
    //if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("I Hit: %s"), *OtherActor->GetName()));
    FString name = *OtherActor->GetName();
    if (name.Contains("Projectile")) {
      if (GEngine)
      GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("I Hit: %s"), *OtherActor->GetName()));

    }
  }
}