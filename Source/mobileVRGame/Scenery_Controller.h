// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Scenery.h"
#include "Scenery_Controller.generated.h"

//class FActorSpawnParameters;

UCLASS()
class MOBILEVRGAME_API AScenery_Controller : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AScenery_Controller();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

  void addTowers();
  void addTower(FActorSpawnParameters spawnParams, FVector location);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

  UPROPERTY(EditDefaultsOnly, Category = "Our Spawning Object")
    TSubclassOf<AScenery> ourSpawningObject;

	
};
