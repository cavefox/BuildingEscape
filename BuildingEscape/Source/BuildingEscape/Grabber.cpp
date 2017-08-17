// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"
#include "Engine/Engine.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/KismetSystemLibrary.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Components/InputComponent.h"
#include "EngineUtils.h"

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

	FindPhysicsHandleComponent();
	SetupInputComponent();

}

void UGrabber::Grabbing() {
	UE_LOG(LogTemp, Warning, TEXT("Grab action!!!"));

	GetFirstHitResultFromRay();

}

void UGrabber::Grabdown() {
	UE_LOG(LogTemp, Warning, TEXT("Grab down action!!!"));
}

void UGrabber::FindPhysicsHandleComponent()
{
	// find physics component
	PhysicsHandle = GetOwner() ->FindComponentByClass<UPhysicsHandleComponent>();
	if (PhysicsHandle) {
		UE_LOG(LogTemp, Warning, TEXT("You get the physicshandle correctly!"));
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("%s miss the physicshandle!"), *GetOwner() ->GetName());
	}
}

void UGrabber::SetupInputComponent()
{
	// find input component
	InputComponent = GetOwner() ->FindComponentByClass<UInputComponent>();
	if (InputComponent) {
		UE_LOG(LogTemp, Warning, TEXT("You get the InputComponent correctly!"));

		InputComponent ->BindAction(TEXT("Grab"), IE_Pressed, this, &UGrabber::Grabbing);
		InputComponent ->BindAction(TEXT("Grab"), IE_Released, this, &UGrabber::Grabdown);
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("%s miss the InputComponent!"), *GetOwner() ->GetName());
	}
}

const FHitResult UGrabber::GetFirstHitResultFromRay()
{
	FHitResult hitResult;
	FVector startPos = GetOwner() ->GetActorLocation();
	FVector dir(1.0f, 0.0f, 0.0f);
	dir = GWorld ->GetFirstPlayerController() ->PlayerCameraManager ->GetTransform().TransformVector(dir);
	FVector endPos = startPos + dir * ReachDistanceToDetect;

	UKismetSystemLibrary::DrawDebugLine(GetWorld(), startPos, endPos, FLinearColor::Red, 15.0f, 5.0f);



	//GWorld ->LineTraceSingleByObjectType();



	return hitResult;
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

