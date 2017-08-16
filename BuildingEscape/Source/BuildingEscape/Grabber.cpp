// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"
#include "Engine/Engine.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/KismetSystemLibrary.h"

#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	GEngine ->AddOnScreenDebugMessage(-1, 2, FColor::Green, TEXT("I'm Grabber here!"));
	UE_LOG(LogTemp, Warning, TEXT("I'm grabber here!"));
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FVector ownerLocation = GetOwner() ->GetTransform().GetLocation();
	FRotator ownerRotator = GWorld ->GetFirstPlayerController() ->PlayerCameraManager ->GetTransform().GetRotation().Rotator();
	FVector origin = FVector(1, 0, 0);
	origin = GWorld ->GetFirstPlayerController() ->PlayerCameraManager ->GetTransform().TransformVector(origin);

	FVector dir = origin.GetSafeNormal();
	FVector endLoc = ownerLocation + dir * ReachDistanceToDetect;

	UKismetSystemLibrary::DrawDebugLine(GetWorld(), ownerLocation, endLoc, FLinearColor::Red, 0.0f, 2.0f);

}

