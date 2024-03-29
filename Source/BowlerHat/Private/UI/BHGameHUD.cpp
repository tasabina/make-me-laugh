// Copyright © 2024 Sabina Talipova. All rights reserved.


#include "UI/BHGameHUD.h"
#include "Engine/Canvas.h"
#include "BHGameModeBase.h"
#include "Blueprint/UserWidget.h"

void ABHGameHUD::DrawHUD()
{
    Super::DrawHUD();
}

void ABHGameHUD::BeginPlay()
{
    Super::BeginPlay();

    GameWidgets.Add(EBHMatchState::InProgress, CreateWidget<UUserWidget>(GetWorld(), PlayerHUDWidgetClass));
    GameWidgets.Add(EBHMatchState::Pause, CreateWidget<UUserWidget>(GetWorld(), PauseWidgetClass));
    GameWidgets.Add(EBHMatchState::GameOver, CreateWidget<UUserWidget>(GetWorld(), GameOverWidgetClass));

    for (auto GameWidgetPair : GameWidgets)
    {
        const auto GameWidget = GameWidgetPair.Value;
        if (!GameWidget) continue;

        GameWidget->AddToViewport();
        GameWidget->SetVisibility(ESlateVisibility::Hidden);
    }

    if (GetWorld())
    {
        const auto GameMode = Cast<ABHGameModeBase>(GetWorld()->GetAuthGameMode());
        if (GameMode)
        {
            GameMode->OnMatchStateChanged.AddUObject(this, &ABHGameHUD::OnMatchStateChanged);
        }
    }

}

void ABHGameHUD::OnMatchStateChanged(EBHMatchState State)
{
    if (CurrentWidget)
    {
        CurrentWidget->SetVisibility(ESlateVisibility::Hidden);
    }

    if (GameWidgets.Contains(State))
    {
        CurrentWidget = GameWidgets[State];
    }

    if (CurrentWidget)
    {
        CurrentWidget->SetVisibility(ESlateVisibility::Visible);
    }

}
