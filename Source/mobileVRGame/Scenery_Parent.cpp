// Fill out your copyright notice in the Description page of Project Settings.

#include "Scenery_Parent.h"


// Sets default values
AScenery_Parent::AScenery_Parent()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AScenery_Parent::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AScenery_Parent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

