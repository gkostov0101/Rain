// Copyright Rain

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "RainHUD.generated.h"

class URainUserWidget;
/**
 * 
 */
UCLASS()
class AURA_API ARainHUD : public AHUD
{
	GENERATED_BODY()

public:

	UPROPERTY()
	TObjectPtr<URainUserWidget> OverlayWidget;

protected:
	virtual void BeginPlay() override;

private:

	UPROPERTY(EditAnywhere)
	TSubclassOf<URainUserWidget> OverlayWidgetClass;
};
