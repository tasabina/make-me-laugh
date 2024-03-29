// Copyright © 2024 Sabina Talipova. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BHMatchState.h"
#include "BHGameOverUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class BOWLERHAT_API UBHGameOverUserWidget : public UUserWidget
{
	GENERATED_BODY()

	private:
		void OnMatchStateChanged(EBHMatchState State);
	
};
