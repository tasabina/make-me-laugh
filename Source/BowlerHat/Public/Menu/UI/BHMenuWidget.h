// Copyright © 2024 Sabina Talipova. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BHMenuWidget.generated.h"

class UButton;

/**
 * 
 */
UCLASS()
class BOWLERHAT_API UBHMenuWidget : public UUserWidget
{
	GENERATED_BODY()

	protected:
		UPROPERTY(meta = (BindWidget))
		UButton* StartGameButton;

		UPROPERTY(meta = (BindWidget))
		UButton* QuitGameButton;

		virtual void NativeOnInitialized() override;

	private:
		UFUNCTION()
		void OnStartGame();

		UFUNCTION()
		void OnQuitGame();
	
};
