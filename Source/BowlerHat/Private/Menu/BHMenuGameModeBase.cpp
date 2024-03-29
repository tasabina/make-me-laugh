// Copyright © 2024 Sabina Talipova. All rights reserved.


#include "Menu/BHMenuGameModeBase.h"
#include "Menu/BHMenuPlayerController.h"
#include "Menu/UI/BHMenuHUD.h"

ABHMenuGameModeBase::ABHMenuGameModeBase()
{
    PlayerControllerClass = ABHMenuPlayerController::StaticClass();
    HUDClass = ABHMenuHUD::StaticClass();
}

