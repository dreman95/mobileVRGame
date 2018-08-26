// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Projectile.h"
#include "VRCharacter.generated.h"


UCLASS()
class MOBILEVRGAME_API AVRCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AVRCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
private:
	void MoveRight(float throttle);
	void MoveForward(float throttle);

	UFUNCTION(BlueprintCallable, Category = Firing)
	void Fire();


private:
	//store a reference to the camera
	class UCameraComponent* camera;
	class USceneComponent* VRRoot;
	float LaunchSpeed = 4000;

	///** Projectile class to spawn */
	//UPROPERTY(EditDefaultsOnly, Category = Projectile)
	//TSubclassOf<AProjectile> ProjectileClass;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* SpawnComp;

	float CurrentTime;                              //Keeps current alive time 

	FVector OurLoc;                                 //Holds our spawn location
	FRotator ourRotation;                           //Holds the rotation of the object 
	
	
	UPROPERTY(EditDefaultsOnly, Category = "Our spawning object")
	TSubclassOf<AProjectile> Projectile;	//Holds the blueprint of the object we want to spawn 		


};
