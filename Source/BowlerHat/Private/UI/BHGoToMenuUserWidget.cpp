// Copyright © 2024 Sabina Talipova. All rights reserved.


#include "UI/BHGoToMenuUserWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "BHGameInstance.h"

void UBHGoToMenuUserWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    if (GoToMenuButton)
    {
        GoToMenuButton->OnClicked.AddDynamic(this, &UBHGoToMenuUserWidget::OnGoToMenu);
    }
}

void UBHGoToMenuUserWidget::OnGoToMenu()
{
    if (!GetWorld())
        return;
    const auto LMGameInstance = GetWorld()->GetGameInstance<UBHGameInstance>();
    if (!LMGameInstance)
        return;

    if (LMGameInstance->GetMenuLevelName().IsNone())
        return;

    UGameplayStatics::OpenLevel(this, LMGameInstance->GetMenuLevelName());
}
