// Fill out your copyright notice in the Description page of Project Settings.

#include "VRCharacter.h"
#include <Camera/CameraComponent.h>
#include "Engine.h"
#include "DrawDebugHelpers.h"
#include "Engine/Engine.h"


// Sets default values
AVRCharacter::AVRCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	camera->SetupAttachment(GetRootComponent());

}

// Called when the game starts or when spawned
void AVRCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVRCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AVRCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("Forward"), this, &AVRCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("Right"), this, &AVRCharacter::MoveRight);

  PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AVRCharacter::Raycast);
  PlayerInputComponent->BindAction("Raycast", IE_Pressed, this, &AVRCharacter::Raycast);


}

void AVRCharacter::MoveRight(float throttle)
{
	AddMovementInput(throttle * camera->GetRightVector());
}

void AVRCharacter::MoveForward(float throttle)
{
	AddMovementInput(throttle * camera->GetForwardVector());
}

void AVRCharacter::Raycast()
{
  FHitResult HitResult;
  //FHitResult* HitResult = new FHitResult();
  FVector StartTrace = camera->GetComponentLocation();
  FVector ForwardVector = camera->GetForwardVector();
  FVector EndTrace = (ForwardVector * 5000.f) + StartTrace;
  FCollisionQueryParams CQP;

  if (GetWorld()->LineTraceSingleByChannel(HitResult, StartTrace, EndTrace, ECC_Visibility, CQP))
  {

    DrawDebugLine(GetWorld(), StartTrace, EndTrace, FColor(255, 0, 0), true, -10.f);

    if (HitResult.GetActor() != NULL)
    {
      //GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Hit: %s"), *HitResult.GetActor()->GetHumanReadableName() ));
      GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Hit: %s"), *HitResult.GetActor()->GetName()));
      //HitResult.GetActor()->GetHumanReadableName()
      HitResult.GetActor()->Destroy();
    }
  }
}