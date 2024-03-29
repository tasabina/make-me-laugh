// Copyright © 2024 Sabina Talipova. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "BHMenuHUD.generated.h"

/**
 * 
 */
UCLASS()
class BOWLERHAT_API ABHMenuHUD : public AHUD
{
	GENERATED_BODY()

	protected:
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
		TSubclassOf<UUserWidget> MenuWidgetClass;

		virtual void BeginPlay() override;
	
};
