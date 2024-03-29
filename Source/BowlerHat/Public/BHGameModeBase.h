// Copyright © 2024 Sabina Talipova. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BHMatchState.h"
#include "BHGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class BOWLERHAT_API ABHGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	public:
		ABHGameModeBase();

		FOnMatchStateChangedSignature OnMatchStateChanged;

		virtual void StartPlay() override;

		virtual bool SetPause(APlayerController* PC, FCanUnpause CanUnpauseDelegate = FCanUnpause());
		virtual bool ClearPause();

		void SetNotification(EBHMatchState State);

	private:
		EBHMatchState MatchState = EBHMatchState::WaitingToStart;

		void SetMatchState(EBHMatchState State);
		void GameOver();
	
};
