// Lessons

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseWeapon.generated.h"

class USkeletalMeshComponent;




UCLASS()
class LESSONS_API ABaseWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseWeapon();

	int32 GetAmmoData() { return Bullets; }

	void AddAmmo();

	void Fire();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USkeletalMeshComponent* WeaponMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	FName MuzzleSocketName = "MuzzleFlashSocket";
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	float TraceMaxDist = 5000.0f;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	float Damage = 10.0f;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	int32 Bullets = 0;

	virtual void BeginPlay() override;

	APlayerController* GetPlayerController();

	void MakeDamage(const FHitResult& HitResult);
	void DecreseAmmo();
	bool IsAmmoEmty() const;


private:
	int32 DefaultBulets = 30;
};
