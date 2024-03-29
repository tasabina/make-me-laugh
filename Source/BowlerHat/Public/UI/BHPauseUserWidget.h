// Copyright © 2024 Sabina Talipova. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BHPauseUserWidget.generated.h"

class UButton;
/**
 * 
 */
UCLASS()
class BOWLERHAT_API UBHPauseUserWidget : public UUserWidget
{
	GENERATED_BODY()

	public:
		virtual bool Initialize() override;

	protected:
		UPROPERTY(meta = (BindWidget))
		UButton* ClearPauseButton;

	private:
		UFUNCTION()
		void OnClearPause();
	
};
