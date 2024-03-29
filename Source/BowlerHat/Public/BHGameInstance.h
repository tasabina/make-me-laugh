// Copyright © 2024 Sabina Talipova. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "BHGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class BOWLERHAT_API UBHGameInstance : public UGameInstance
{
	GENERATED_BODY()

	public:
		FName GetStartupLevelName() const { return StartupLevelName; }
		FName GetMenuLevelName() const { return MenuLevelName; }

	protected:
		UPROPERTY(EditDefaultsOnly, Category = "Game")
		FName StartupLevelName = NAME_None;

		UPROPERTY(EditDefaultsOnly, Category = "Game")
		FName MenuLevelName = NAME_None;
	
};
