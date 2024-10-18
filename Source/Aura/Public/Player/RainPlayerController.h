// Copyright Rain

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RainPlayerController.generated.h"

/**
 * 
 */

class UInputMappingContext;

UCLASS()
class AURA_API ARainPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ARainPlayerController();

protected:

	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> RainContext;
};
