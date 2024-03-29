// Copyright © 2024 Sabina Talipova. All rights reserved.


#include "BHGameModeBase.h"
#include "Player/BHPaperCharacter.h"
#include "Player/BHPlayerController.h"
#include "BHMatchState.h"

ABHGameModeBase::ABHGameModeBase()
{
    // Ovveride Default Pawm Class & Player Controller
    DefaultPawnClass = ABHPaperCharacter::StaticClass();
    PlayerControllerClass = ABHPlayerController::StaticClass();
}

void ABHGameModeBase::StartPlay()
{
    Super::StartPlay();
    SetMatchState(EBHMatchState::InProgress);
}

bool ABHGameModeBase::SetPause(APlayerController* PC, FCanUnpause CanUnpauseDelegate)
{
    const auto PauseSet = Super::SetPause(PC, CanUnpauseDelegate);

    if (PauseSet)
    {
        SetMatchState(EBHMatchState::Pause);
    }

    return PauseSet;
}

bool ABHGameModeBase::ClearPause()
{
    const auto PauseCleared = Super::ClearPause();

    if (PauseCleared)
    {
        SetMatchState(EBHMatchState::InProgress);
    }

    return PauseCleared;
}

void ABHGameModeBase::SetNotification(EBHMatchState State)
{
    SetMatchState(State);
}

void ABHGameModeBase::SetMatchState(EBHMatchState State)
{
    if (MatchState == State) return;

    MatchState = State;
    OnMatchStateChanged.Broadcast(MatchState);
}

void ABHGameModeBase::GameOver()
{
    SetMatchState(EBHMatchState::GameOver);
}
