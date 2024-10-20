// Copyright Rain


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/RainAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const URainAttributeSet* RainAttributeSet = CastChecked<URainAttributeSet>(AttributeSet);

	// Health
	OnHealthChanged.Broadcast(RainAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(RainAttributeSet->GetMaxHealth());

	// Mana
	OnManaChanged.Broadcast(RainAttributeSet->GetMana());
	OnMaxManaChanged.Broadcast(RainAttributeSet->GetMaxMana());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const URainAttributeSet* RainAttributeSet = CastChecked<URainAttributeSet>(AttributeSet);

	// Health
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		RainAttributeSet->GetHealthAttribute()).AddUObject(this, &UOverlayWidgetController::HealthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		RainAttributeSet->GetMaxHealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);

	// Mana
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		RainAttributeSet->GetManaAttribute()).AddUObject(this, &UOverlayWidgetController::ManaChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		RainAttributeSet->GetMaxManaAttribute()).AddUObject(this, &UOverlayWidgetController::MaxManaChanged);
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::ManaChanged(const FOnAttributeChangeData& Data) const
{
	OnManaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxManaChanged.Broadcast(Data.NewValue);
}
