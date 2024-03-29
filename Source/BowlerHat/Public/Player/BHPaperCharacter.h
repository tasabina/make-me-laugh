// Copyright © 2024 Sabina Talipova. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "BHPaperCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

/**
 * 
 */
UCLASS()
class BOWLERHAT_API ABHPaperCharacter : public APaperCharacter
{
	GENERATED_BODY()

	public:
		// Sets default values for this character's properties
		ABHPaperCharacter();

	protected:
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
		USpringArmComponent* SpringArmComponent;

		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
		UCameraComponent* CameraComponent;

		// Called when the game starts or when spawned
		virtual void BeginPlay() override;


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "Movement")
	bool IsRunning() const;

	UFUNCTION(BlueprintCallable, Category = "Movement")
	float GetMovementDirection() const;

private:
	bool ReadyToRun = false;
	bool IsMovingForward = false;

	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);

	void OnStartRunning();
	void OnStopRunning();

	void OnDeath();
	void OnHealthChanged(float Health);
	void OnBankStateChanged(float CoinAmounts);

	//UFUNCTION()
	//void OnGroundLanded(const FHitResult& Hit);
	
};
