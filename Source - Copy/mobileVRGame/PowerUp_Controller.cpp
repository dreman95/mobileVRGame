// Fill out your copyright notice in the Description page of Project Settings.

#include "PowerUp_Controller.h"
#include "Engine.h"

// Sets default values
APowerUp_Controller::APowerUp_Controller()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
  this->SetActorTickEnabled(true);

  currentTime = 0.f;                                      // Set the current time to 0.f seconds, so its not some random number 
  xCoord = 0.f;                                            // set the Xcord we will spawn at to 0.f, so its not some random number

                                                          // Set vector and Rototor to zero 
  ourRotation.ZeroRotator;                                // Set our rotator to 0: 0 roll, 0 pitch, and 0 yaw
  ourLoc.X = 0.f;                                         // set our vector to 0 in the x axis(left and right)
  ourLoc.Y = 100.f;                                       // set our vector to 100 in the y axis(forward and backward)
  ourLoc.Z = 800.f;                                       // set our vector to 800 in the z axis(up and down)
}

// Called when the game starts or when spawned
void APowerUp_Controller::BeginPlay()
{
	Super::BeginPlay();
  GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, TEXT("We are alive"));
}

// Called every frame
void APowerUp_Controller::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
  // take the current time and increment it by 1, and multiply it by the delta time
    currentTime = currentTime + 1 * DeltaTime;

  // debug message to display the current time 
  FString ourString = FString::SanitizeFloat(currentTime);

  // printing the debug message to the game world 
  GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, TEXT("Our Current Time: ") + ourString);

  // if the current time is greater or equal to 2, then do the following...
  if (currentTime >= 2.f)
  {
    // gen a new X 
    xCoord = generateX(DeltaTime);

    // set the x in the location 
    ourLoc.X = xCoord;

    // Create Spawn params 
    FActorSpawnParameters spawnParams;

    // who did the spawn, and we are say this controller did 
    spawnParams.Owner = this;

    // Set the instigator to default 
    spawnParams.Instigator = Instigator;

    // spawn the object now 
    APowerUp_Parent* ourNewObject = GetWorld()->SpawnActor<APowerUp_Parent>(ourSpawningObject, ourLoc, ourRotation, spawnParams);

    // debug 
    GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::White, TEXT("We spawned an object"));

    // currentTime back to 0
    currentTime = 0.f;
  }
}

// This method will generate a new x value to spawn an object into th game world 
float APowerUp_Controller::generateX(float DeltaSeconds)							// -- Generate a new number -- //
{
  // create a variable in memory to pass back a float value for us to use, set it to 0.000000000
  float passBack = 0.f;

  // give it a new number, using the FMath class using the Rand Range method 
  // generates a number between -300 and 300
  passBack = FMath::RandRange(-300, 300);

  // take that number we just generated and add the small number delta seconds is to it
  passBack = passBack + DeltaSeconds;

  // Return the newly generated number back to the tick method 
  return passBack;
}
