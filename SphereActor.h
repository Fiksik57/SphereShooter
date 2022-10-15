// Lessons

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SphereActor.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnDestroy)

class AAmmoPickup;

UCLASS()
class LESSONS_API ASphereActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ASphereActor();



	FOnDestroy OnDestroy;
	FOnDestroy DestroyShort;
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* MeshComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	int32 SpheresDead = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite , Category = "Components")
	TSubclassOf<AAmmoPickup> AmmoPickup;

	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;



private:
	UFUNCTION()
		void OnTakeAnyDamageHendl(AActor* DamagedActor, float Damage, class AController* InstigatedBy, FVector HitLocation, class UPrimitiveComponent* FHitComponent, FName BoneName, FVector ShotFromDirection, const class UDamageType* DamageType, AActor* DamageCauser);
	UFUNCTION()
		void OnTakeRadialD(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, FVector Origin, FHitResult HitInfo, class AController* InstigatedBy, AActor* DamageCauser);
	void SpawnAmmo();

};
