// Copyright Rain

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RainPlayerController.generated.h"

/**
 * 
 */

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

UCLASS()
class AURA_API ARainPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ARainPlayerController();

protected:

	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> RainContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	void Move(const FInputActionValue& InputActionValue);
};