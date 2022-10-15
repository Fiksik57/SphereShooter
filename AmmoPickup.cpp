// Lessons


#include "Pickup/AmmoPickup.h"
#include "Components/SphereComponent.h"
#include "Components/WeaponComponent.h"


// Sets default values
AAmmoPickup::AAmmoPickup()
{
	PrimaryActorTick.bCanEverTick = true;

	CollisionComponent = CreateDefaultSubobject<USphereComponent>("CollisionComponet");
	CollisionComponent->InitSphereRadius(100.0f);
	CollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	CollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	SetRootComponent(CollisionComponent);


}

void AAmmoPickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAmmoPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void  AAmmoPickup::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	const auto Pawn = Cast <APawn>(OtherActor);
	if (Pawn)
	{
		const auto Component = Pawn->GetComponentByClass(UWeaponComponent::StaticClass());
		const auto  WeaponComponent = Cast<UWeaponComponent>(Component);
		WeaponComponent->AddAmmo();
	}
	Destroy();
}
