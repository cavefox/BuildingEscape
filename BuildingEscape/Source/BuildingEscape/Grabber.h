// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void Grabbing();
	virtual void Grabdown();

private:
	UPROPERTY(EditAnywhere, category="Grabber(general settings)")
	float ReachDistanceToDetect = 100;

	UPROPERTY()
	class UPhysicsHandleComponent*	PhysicsHandle = nullptr;

	UPROPERTY()
	class UInputComponent* InputComponent = nullptr;

	void FindPhysicsHandleComponent();
	void SetupInputComponent();

	const FHitResult GetFirstHitResultFromRay();
};
