// Fill out your copyright notice in the Description page of Project Settings.

#include "Scenery_Controller.h"
#include "Engine.h"

// Sets default values
AScenery_Controller::AScenery_Controller()
{
  // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
  PrimaryActorTick.bCanEverTick = true;

  this->SetActorTickEnabled(true);
}

// Called when the game starts or when spawned
void AScenery_Controller::BeginPlay()
{
  Super::BeginPlay();

  ////GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, TEXT("We are alive"));

  //// Create Spawn params 
  //FActorSpawnParameters spawnParams;

  //// who did the spawn, and we are say this controller did 
  //spawnParams.Owner = this;

  //// Set the instigator to default 
  //spawnParams.Instigator = Instigator;

  //// gen a new X, Y 
  ////FVector location = FVector(FMath::RandRange(-300, 300), FMath::RandRange(-300, 300), 0.);
  //FVector location0 = FVector(360., -100., 90.);
  //AScenery* ourNewObject = GetWorld()->SpawnActor<AScenery>(ourSpawningObject, location0, FRotator::ZeroRotator, spawnParams);

  //FVector location1 = FVector(370., -110., 190.);
  //ourNewObject = GetWorld()->SpawnActor<AScenery>(ourSpawningObject, location1, FRotator::ZeroRotator, spawnParams);

  //FVector location2 = FVector(350., -90., 290.);
  //ourNewObject = GetWorld()->SpawnActor<AScenery>(ourSpawningObject, location2, FRotator::ZeroRotator, spawnParams);

  addTowers();
}

void AScenery_Controller::addTowers()
{
  // Create Spawn params 
  FActorSpawnParameters spawnParams;

  // who did the spawn, and we are say this controller did 
  spawnParams.Owner = this;

  // Set the instigator to default 
  spawnParams.Instigator = Instigator;

  for (int i = -10; i < 10; i++)
  {
    if (i == 0) i++;
    for (int j = -10; j < 10; j++)
    {
      if (j == 0 || i == 0) continue;

      int offX = FMath::RandRange(-50, 50);
      int offY = FMath::RandRange(-50, 50);
      int h = FMath::Abs(FMath::RandRange(-3, 3) + FMath::RandRange(-3, 3)) / 2;
      for (size_t k = 0; k < h; k++)
      {
        FVector location = FVector(offX + i * 200., offY + j * 200., 100 + k * 200.);
        //location = FVector(0., 0., 100.);
        addTower(spawnParams, location);
      }
    }
  }
}

void AScenery_Controller::addTower(FActorSpawnParameters spawnParams, FVector location)
{
  AScenery_Parent* ourNewObject = GetWorld()->SpawnActor<AScenery_Parent>(ourSpawningObject, location, FRotator::ZeroRotator, spawnParams);
}

// Called every frame
void AScenery_Controller::Tick(float DeltaTime)
{
  Super::Tick(DeltaTime);

}