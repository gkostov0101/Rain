// Copyright Rain

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RainUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API URainUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);

public:
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
};
