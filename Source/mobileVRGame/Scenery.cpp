// Fill out your copyright notice in the Description page of Project Settings.

#include "Scenery.h"
#include "Engine.h"

// Sets default values
AScenery::AScenery()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

  this->SetActorTickEnabled(true);
}

// Called when the game starts or when spawned
void AScenery::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void AScenery::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}