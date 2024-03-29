// Copyright © 2024 Sabina Talipova. All rights reserved.


#include "UI/BHPauseUserWidget.h"
#include "Gameframework/GameModeBase.h"
#include "Components/Button.h"

bool UBHPauseUserWidget::Initialize()
{
    const auto InitStatus = Super::Initialize();

    if (ClearPauseButton)
    {
        ClearPauseButton->OnClicked.AddDynamic(this, &UBHPauseUserWidget::OnClearPause);
    }

    return InitStatus;
}

void UBHPauseUserWidget::OnClearPause()
{
    if (!GetWorld() || !GetWorld()->GetAuthGameMode()) return;

    GetWorld()->GetAuthGameMode()->ClearPause();
}

