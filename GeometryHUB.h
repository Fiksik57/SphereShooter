// Lessons

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GeometryHUB.generated.h"



 
class ASphereActor;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LESSONS_API UGeometryHUB : public UActorComponent
{
	GENERATED_BODY()

public:	
	UGeometryHUB();
	
	UFUNCTION(BlueprintCallable, Category = "Spheres")
	float GetSpheres() { return DestroyedSpheres / MaxSpheres; }



protected:

	UPROPERTY(EditAnywhere)
	TSubclassOf<ASphereActor> GeometryClass;
	UPROPERTY(EditAnywhere)
	ASphereActor* Geometry;
	UPROPERTY(EditAnywhere)
	float DestroyedSpheres = 0;
	UPROPERTY(EditAnywhere)
	float MaxSpheres = 10;
	UPROPERTY(EditAnywhere)
	int32 Digit = 0;
	UPROPERTY(EditAnywhere)
	FVector Point;
	UPROPERTY(EditAnywhere)
	float TimerBetweenSpawn = 1.0;
	UPROPERTY(EditAnywhere)
	float TimerBetweenDigitPlus = 1.2;
	UPROPERTY(EditAnywhere)
	int32 i;
	UPROPERTY(EditAnywhere)
	int32 Level;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UDamageType> DestroyAll;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UDamageType> DestroyShort;

	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void AddKils();
	void SpawnGeometry();
	void SpawnAndDestroySphers();
	void DecrementI();
	int32 GetLevel() const { return Level; }

private:
	FTimerHandle SpawnTimer;


		
};
