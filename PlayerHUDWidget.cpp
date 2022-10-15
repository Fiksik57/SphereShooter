// Lessons


#include "UI/PlayerHUDWidget.h"
#include "Components/GeometryHUB.h"
#include "Components/WeaponComponent.h"



float UPlayerHUDWidget::GetSpherePercent() const
{
	const auto Player = GetOwningPlayerPawn();
	if (!Player) return 0.0f;

	const auto Component = Player->GetComponentByClass(UGeometryHUB::StaticClass());
	const auto  SphereComponent = Cast<UGeometryHUB>(Component);
	if (!SphereComponent) return 0.0f;

	return SphereComponent->GetSpheres();
}

float UPlayerHUDWidget::GetLevel() const
{
	const auto Player = GetOwningPlayerPawn();
	if (!Player) return 0.0f;

	const auto Component = Player->GetComponentByClass(UGeometryHUB::StaticClass());
	const auto  LevelComponent = Cast<UGeometryHUB>(Component);
	if (!LevelComponent) return 0.0f;

	return LevelComponent->GetLevel();
}

int32 UPlayerHUDWidget::GetWeaponAmmoData() const
{
	const auto Player = GetOwningPlayerPawn();
	if (!Player) return 0.0f;

	const auto Component = Player->GetComponentByClass(UWeaponComponent::StaticClass());
	const auto  WeaponComponent = Cast<UWeaponComponent>(Component);
	if (!WeaponComponent) return 0.0f;

	return WeaponComponent->GetWeaponAmmoData();
}