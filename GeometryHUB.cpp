// Lessons


#include "Components/GeometryHUB.h"
#include "Actors/SphereActor.h"
#include "Engine/World.h"
#include "GameFramework/Character.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"


UGeometryHUB::UGeometryHUB()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UGeometryHUB::BeginPlay()
{
	Super::BeginPlay();
	
	DestroyedSpheres = 0;
	Level = 1;
	SpawnGeometry();
}


void UGeometryHUB::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	SpawnAndDestroySphers();
}

void UGeometryHUB::AddKils()
{
	DestroyedSpheres++;
	Digit++;
}

void UGeometryHUB::SpawnGeometry()
{
	UWorld* World = GetWorld();
	if (World)
	{
		ACharacter* Character = Cast<ACharacter>(GetOwner());
		if (!Character) return;

		FVector CharPoint = Character->GetActorLocation();
			for (i = 0; i < 15; i++)
			{
				Point = FVector(CharPoint.X + FMath::RandRange(-2000, 2000), CharPoint.Y + FMath::RandRange(-2000, 2000), 100);
				UGameplayStatics::ApplyRadialDamage(GetWorld(), 10,Point, 250, DestroyShort, {}, nullptr, nullptr, true);

				const FTransform GeometryTransform = FTransform(FRotator::ZeroRotator, FVector(Point.X, Point.Y, Point.Z));
				Geometry = World->SpawnActor<ASphereActor>(GeometryClass, GeometryTransform);
				Geometry->OnDestroy.AddUObject(this, &UGeometryHUB::AddKils); 
				Geometry->DestroyShort.AddUObject(this, &UGeometryHUB::DecrementI);
			}
	}
}

void UGeometryHUB::SpawnAndDestroySphers()
{
	if (Digit % 11 == 10) // Digit - это счетчик, при уничтожении каждой дес€той сферы,все сферы в радиусе уничтожаютс€ и по€вл€ютс€ новыйе.
	{
		ACharacter* Character = Cast<ACharacter>(GetOwner());
		UGameplayStatics::ApplyRadialDamage(GetWorld(), 10, FVector(0.0, 0.0, 400) + Character->GetActorLocation(), 1550, DestroyAll, {}, nullptr, nullptr, true);
		//Character->GetWorldTimerManager().SetTimer(SpawnTimer, this, &UGeometryHUB::SpawnGeometry, TimerBetweenSpawn, false);
		//Character->GetWorldTimerManager().SetTimer(SpawnTimer, this, &UGeometryHUB::DigitPlus, TimerBetweenDigitPlus, false);
		SpawnGeometry();
		Digit++;
		DestroyedSpheres = 0;
		Level++;
	}
}

void UGeometryHUB::DecrementI()
{
	i--;
}




