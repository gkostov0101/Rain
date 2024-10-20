// Copyright Rain


#include "UI/WidgetController/RainWidgetController.h"

void URainWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
}

void URainWidgetController::BroadcastInitialValues()
{
}

void URainWidgetController::BindCallbacksToDependencies()
{
}
