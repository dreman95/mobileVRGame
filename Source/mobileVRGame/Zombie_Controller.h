// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Zombie_Parent.h"
#include "Zombie_Controller.generated.h"

UCLASS()
class MOBILEVRGAME_API AZombie_Controller : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AZombie_Controller();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

  UPROPERTY(EditDefaultsOnly, Category = "Our Spawning Object")
    TSubclassOf<AZombie_Parent> ourSpawningObject;

  UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* SM;

  ///*OnHit function is called when the FallingActor hits something - 4.12+ version */
  //UFUNCTION()
  //  void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
  ////void OnHit(AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
  ////void OnHit(AActor* OtherActor, UPrimitiveComponent* OtherComp, UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

  ///*ReceiveHit functions is called when the FallingActor gets hit by something */
  //UFUNCTION()
  //  void ReceiveHit(UPrimitiveComponent* MyComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

  UPROPERTY(VisibleAnywhere)
    class UBoxComponent* MyComp;

  UFUNCTION()
    void OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
