// Copyright Rain


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/RainAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const URainAttributeSet* RainAttributeSet = CastChecked<URainAttributeSet>(AttributeSet);
	
	OnHealthChanged.Broadcast(RainAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(RainAttributeSet->GetMaxHealth());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const URainAttributeSet* RainAttributeSet = CastChecked<URainAttributeSet>(AttributeSet);
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		RainAttributeSet->GetHealthAttribute()).AddUObject(this, &UOverlayWidgetController::HealthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		RainAttributeSet->GetMaxHealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}
