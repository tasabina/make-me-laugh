// Copyright © 2024 Sabina Talipova. All rights reserved.


#include "Player/BHPlayerController.h"
#include "BHGameModeBase.h"

ABHPlayerController::ABHPlayerController() {}

void ABHPlayerController::BeginPlay()
{
    Super::BeginPlay();

    if (GetWorld())
    {
        const auto GameMode = Cast<ABHGameModeBase>(GetWorld()->GetAuthGameMode());
        if (GameMode)
        {
            GameMode->OnMatchStateChanged.AddUObject(this, &ABHPlayerController::OnMatchStateChanged);
        }
    }
}


void ABHPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();
    if (!InputComponent) return;

    InputComponent->BindAction("PauseGame", IE_Pressed, this, &ABHPlayerController::OnPauseGame);
}

void ABHPlayerController::OnPauseGame()
{
    if (!GetWorld() || !GetWorld()->GetAuthGameMode()) return;

    GetWorld()->GetAuthGameMode()->SetPause(this);
}

void ABHPlayerController::OnMatchStateChanged(EBHMatchState State)
{
    if (State == EBHMatchState::InProgress)
    {
        SetInputMode(FInputModeGameOnly());
        bShowMouseCursor = false;
    }
    else
    {
        SetInputMode(FInputModeUIOnly());
        bShowMouseCursor = true;
    }
}