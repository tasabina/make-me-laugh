// Copyright © 2024 Sabina Talipova. All rights reserved.


#include "Menu/UI/BHMenuHUD.h"
#include "Blueprint/UserWidget.h"

void ABHMenuHUD::BeginPlay()
{
    Super::BeginPlay();

    if (MenuWidgetClass)
    {
        const auto MenuWidget = CreateWidget<UUserWidget>(GetWorld(), MenuWidgetClass);

        if (MenuWidget)
        {
            MenuWidget->AddToViewport();
        }
    }
}