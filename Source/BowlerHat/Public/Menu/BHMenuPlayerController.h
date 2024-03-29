// Copyright © 2024 Sabina Talipova. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BHMenuPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BOWLERHAT_API ABHMenuPlayerController : public APlayerController
{
	GENERATED_BODY()

	protected:
		virtual void BeginPlay() override;
	
};
