// Copyright © 2024 Sabina Talipova. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "BHMatchState.h"
#include "BHGameHUD.generated.h"

/**
 * 
 */
UCLASS()
class BOWLERHAT_API ABHGameHUD : public AHUD
{
    GENERATED_BODY()

    public:
        virtual void DrawHUD() override;

    protected:
        UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
        TSubclassOf<UUserWidget> PlayerHUDWidgetClass;

        UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
        TSubclassOf<UUserWidget> PauseWidgetClass;

        UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
        TSubclassOf<UUserWidget> GameOverWidgetClass;

        virtual void BeginPlay() override;


    private:
        UPROPERTY()
        TMap<EBHMatchState, UUserWidget*> GameWidgets;

        UPROPERTY()
        UUserWidget* CurrentWidget = nullptr;

        void OnMatchStateChanged(EBHMatchState);
	
};
