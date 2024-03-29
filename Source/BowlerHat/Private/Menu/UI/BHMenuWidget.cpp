// Copyright © 2024 Sabina Talipova. All rights reserved.


#include "Menu/UI/BHMenuWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "BHGameInstance.h"

void UBHMenuWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    if (StartGameButton)
    {
        StartGameButton->OnClicked.AddDynamic(this, &UBHMenuWidget::OnStartGame);
    }

    if (QuitGameButton)
    {
        QuitGameButton->OnClicked.AddDynamic(this, &UBHMenuWidget::OnQuitGame);
    }
}

void UBHMenuWidget::OnStartGame()
{
    if (!GetWorld()) return;
    const auto LMGameInstance = GetWorld()->GetGameInstance<UBHGameInstance>();
    if (!LMGameInstance) return;

    if (LMGameInstance->GetStartupLevelName().IsNone()) return;

    UGameplayStatics::OpenLevel(this, LMGameInstance->GetStartupLevelName());
}

void UBHMenuWidget::OnQuitGame()
{
    UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(), EQuitPreference::Quit, true);
}
