// Lessons

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AmmoPickup.generated.h"

class USphereComponent;

UCLASS()
class LESSONS_API AAmmoPickup : public AActor
{
	GENERATED_BODY()
	
public:	
	AAmmoPickup();

protected:
	UPROPERTY(VisibleAnywhere, Category = "Pickup")
		USphereComponent* CollisionComponent;

	virtual void BeginPlay() override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

public:	
	virtual void Tick(float DeltaTime) override;

};
