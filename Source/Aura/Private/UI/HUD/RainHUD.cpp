// Copyright Rain


#include "UI/HUD/RainHUD.h"

#include "UI/Widget/RainUserWidget.h"

void ARainHUD::BeginPlay()
{
	Super::BeginPlay();
	
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	Widget->AddToViewport();
}
