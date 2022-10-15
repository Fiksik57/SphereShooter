

#include "Weapon/BaseWeapon.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/Character.h"
#include "GameFramework/Controller.h"
#include "Kismet/GameplayStatics.h"



DEFINE_LOG_CATEGORY_STATIC(BaseWeaponLog, All,All)

ABaseWeapon::ABaseWeapon()
{
	PrimaryActorTick.bCanEverTick = false;

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("WeaponMesh");
	SetRootComponent(WeaponMesh);

}

void ABaseWeapon::BeginPlay()
{
	Super::BeginPlay();
	
	Bullets = DefaultBulets;

}

void ABaseWeapon::Fire()
{
	if (!GetWorld() || IsAmmoEmty()) return;

	const auto Controller = GetPlayerController();
	if (!Controller)  return;

	FVector ViewLocation;
	FRotator ViewRotation;
	Controller->GetPlayerViewPoint(ViewLocation, ViewRotation);

	const FTransform SocketTransform = WeaponMesh->GetSocketTransform(MuzzleSocketName);
	const FVector TraceStart = ViewLocation;// SocketTransform.GetLocation();
	const FVector ShootDirection = ViewRotation.Vector();//SocketTransform.GetRotation().GetForwardVector();
	const FVector TraceEnd = TraceStart + ShootDirection * TraceMaxDist;

	FHitResult HitResult;
	GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, ECollisionChannel::ECC_Visibility);

	if (HitResult.bBlockingHit)
	{
		MakeDamage(HitResult);
		//DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, 10.0f, 24, FColor::Red, false, 5.0f);
	}

DecreseAmmo();
}

APlayerController* ABaseWeapon::GetPlayerController()
{
	const auto Player = Cast<ACharacter>(GetOwner());
	if (!Player) return nullptr;

	return Player->GetController<APlayerController>();
}
	

void ABaseWeapon::MakeDamage(const FHitResult& HitResult)
{
	const auto DamageActor = HitResult.GetActor();
	const auto HitFromDirection = HitResult.ImpactNormal;
	if (!DamageActor) return;

	UGameplayStatics::ApplyPointDamage(DamageActor, 10, HitFromDirection, HitResult, nullptr, this, nullptr);
}


void ABaseWeapon::DecreseAmmo()
{
	Bullets--;
}

bool ABaseWeapon::IsAmmoEmty() const
{
	return Bullets == 0;
}


void ABaseWeapon::AddAmmo()
{
	Bullets += 10;
}