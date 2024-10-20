// Copyright Rain


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/RainAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const URainAttributeSet* RainAttributeSet = CastChecked<URainAttributeSet>(AttributeSet);
	
	OnHealthChanged.Broadcast(RainAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(RainAttributeSet->GetMaxHealth());
}
