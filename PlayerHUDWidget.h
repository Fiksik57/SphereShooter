// Lessons

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerHUDWidget.generated.h"

/**
 * 
 */
UCLASS()
class LESSONS_API UPlayerHUDWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "UI")
		float GetSpherePercent() const;
	UFUNCTION(BlueprintCallable, Category = "UI")
		float GetLevel() const;
	UFUNCTION(BlueprintCallable, Category = "UI")
		int32 GetWeaponAmmoData() const;
};
