// Copyright © 2024 Sabina Talipova. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BHGoToMenuUserWidget.generated.h"

class UButton;
/**
 * 
 */
UCLASS()
class BOWLERHAT_API UBHGoToMenuUserWidget : public UUserWidget
{
    GENERATED_BODY()

    protected:
        UPROPERTY(meta = (BindWidget))
        UButton* GoToMenuButton;

        virtual void NativeOnInitialized() override;

    private:
        UFUNCTION()
        void OnGoToMenu();
	
};
