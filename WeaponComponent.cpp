// Lessons


#include "Components/WeaponComponent.h"
#include "Weapon/BaseWeapon.h"
#include "GameFramework/Character.h"

UWeaponComponent::UWeaponComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


void UWeaponComponent::BeginPlay()
{
	Super::BeginPlay();
	SpawnWeapon();
}


void UWeaponComponent::SpawnWeapon()
{
	if (!GetWorld()) return;
	ACharacter* Character = Cast<ACharacter>(GetOwner());
	if (!Character) return;

	CurentWeapon = GetWorld()->SpawnActor<ABaseWeapon>(WeaponClass);
	if (!CurentWeapon) return;
	
	FAttachmentTransformRules AttachmentRools(EAttachmentRule::SnapToTarget, false);
	CurentWeapon->AttachToComponent(Character->GetMesh(), AttachmentRools, WeaponAttachName);
	CurentWeapon->SetOwner(Character);
	
}

void UWeaponComponent::Fire()
{
	if (!CurentWeapon) return;
	CurentWeapon->Fire();
}

int32  UWeaponComponent::GetWeaponAmmoData()
{
	if (CurentWeapon)
	{
		int32 AmmoData = CurentWeapon->GetAmmoData();
		return AmmoData;
	}
	return false;
}

void UWeaponComponent::AddAmmo()
{
	CurentWeapon->AddAmmo();
}