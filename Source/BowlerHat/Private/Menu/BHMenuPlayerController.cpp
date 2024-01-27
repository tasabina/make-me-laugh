// Copyright © 2024 Sabina Talipova. All rights reserved.


#include "Menu/BHMenuPlayerController.h"

void ABHMenuPlayerController::BeginPlay()
{
    Super::BeginPlay();

    SetInputMode(FInputModeUIOnly());
    bShowMouseCursor = true;
}