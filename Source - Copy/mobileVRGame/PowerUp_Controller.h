// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PowerUp_Parent.h"
#include "PowerUp_Controller.generated.h"

UCLASS()
class MOBILEVRGAME_API APowerUp_Controller : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
  APowerUp_Controller();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	float generateX(float DeltaSeconds);

  float currentTime;

  float xCoord;

  FTransform ourOldSpawnLocation;
  FVector ourLoc;														// Hold our spawn location 

  FRotator ourRotation;												// Hold the rotation of the object 

  UPROPERTY(EditDefaultsOnly, Category = "Our Spawning Object")
    TSubclassOf<APowerUp_Parent> ourSpawningObject;
};
