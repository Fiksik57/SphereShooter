// Lessons


#include "Actors/SphereActor.h"
#include "GameFramework/Actor.h"
#include "Dev/DestroyShort.h"
#include "Dev/DestroyAll.h"
#include "Pickup/AmmoPickup.h"



DEFINE_LOG_CATEGORY_STATIC(BaseGeometryLog,All,All)

// Sets default values
ASphereActor::ASphereActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	MeshComponent->SetupAttachment(GetRootComponent());

}

// Called when the game starts or when spawned
void ASphereActor::BeginPlay()
{
	Super::BeginPlay();




	OnTakePointDamage.AddDynamic(this, &ASphereActor::OnTakeAnyDamageHendl);
	OnTakeRadialDamage.AddDynamic(this, &ASphereActor::OnTakeRadialD);
	
}

// Called every frame
void ASphereActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
	
}



void ASphereActor::OnTakeAnyDamageHendl(AActor* DamagedActor, float Damage, class AController* InstigatedBy, FVector HitLocation, class UPrimitiveComponent* FHitComponent, FName BoneName, FVector ShotFromDirection, const class UDamageType* DamageType, AActor* DamageCauser)
{



	OnDestroy.Broadcast();

	SpawnAmmo();
	Destroy();
}

void ASphereActor::OnTakeRadialD(AActor* DamagedActor, float Damage, const UDamageType* DamageType, FVector Origin, FHitResult HitInfo, AController* InstigatedBy, AActor* DamageCauser)
{
	if (DamageType)
	{
		if (DamageType->IsA<UDestroyAll>())
		{
			Destroy();
			UE_LOG(BaseGeometryLog, Display, TEXT("DastryedAll!"));
		}
		else if (DamageType->IsA<UDestroyShort>())
		{
			Destroy();
			UE_LOG(BaseGeometryLog, Display, TEXT("DastryedShort!"));
			DestroyShort.Broadcast();
		}
	}


	

	
}

void ASphereActor::SpawnAmmo()
{
	int32 i = FMath::RandRange(0, 100);
	if(i<35)
	{ 
	UWorld* World = GetWorld();
	if (World)
	{
		//	FVector CharPoint = FVector(FMath::RandRange(-2000, 2000), FMath::RandRange(-2000, 2000), 100);
		FVector CharPoint = GetActorLocation() + FVector(200, 200, -10);
		const FTransform GeometryTransform = FTransform(FRotator::ZeroRotator, CharPoint);
		AAmmoPickup* Ammo = World->SpawnActor<AAmmoPickup>(AmmoPickup, GeometryTransform);
	}
	}
}




