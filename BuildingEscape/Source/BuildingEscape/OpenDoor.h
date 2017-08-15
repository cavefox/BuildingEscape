// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


private:
	void CloseDoor();
	void OpenDoor();
		
private:
	UPROPERTY(EditAnywhere, category = "OpenDoor(General Settings)")
		float AngleToOpen = 90.0f;

	UPROPERTY(EditAnywhere, category = "OpenDoor(General Settings)")
		class ATriggerVolume*	PressurePlate;

	UPROPERTY(VisibleInstanceOnly, category = "OpenDoor(Visible Instance Only)")
		AActor*		ActorToOpen;

	UPROPERTY(EditAnywhere, category = "OpenDoor(General Settings)")
		float		DoorCloseDelay = 1.2f;

	UPROPERTY()
		AActor*		ActorOwner;

	bool	DoorIsOpened = false;
	float	LastDoorCloseTime = 0.0f;
};
