// Lessons

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WeaponComponent.generated.h"

class ABaseWeapon;



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LESSONS_API UWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UWeaponComponent();

	int32 GetWeaponAmmoData();
	void AddAmmo();
	void Fire();

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	TSubclassOf<ABaseWeapon> WeaponClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	FName WeaponAttachName = "WeaponPoint";

	virtual void BeginPlay() override;

private:
	UPROPERTY()
	ABaseWeapon* CurentWeapon = nullptr;

	void SpawnWeapon();
		

};
