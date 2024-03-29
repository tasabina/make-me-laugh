// Copyright © 2024 Sabina Talipova. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BHMatchState.h"
#include "BHPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BOWLERHAT_API ABHPlayerController : public APlayerController
{
	GENERATED_BODY()

	public:
		ABHPlayerController();

	protected:
		virtual void BeginPlay() override;
		virtual void SetupInputComponent() override;

	private:
		void OnPauseGame();
		void OnMatchStateChanged(EBHMatchState State);
	
};
