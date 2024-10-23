// Copyright Rain


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/RainAbilitySystemComponent.h"
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
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(RainAttributeSet->GetHealthAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnHealthChanged.Broadcast(Data.NewValue);
			}
		);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(RainAttributeSet->GetMaxHealthAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnMaxHealthChanged.Broadcast(Data.NewValue);
			}
		);

	// Mana
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(RainAttributeSet->GetManaAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnManaChanged.Broadcast(Data.NewValue);
			}
		);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(RainAttributeSet->GetMaxManaAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnMaxManaChanged.Broadcast(Data.NewValue);
			}
		);

	Cast<URainAbilitySystemComponent>(AbilitySystemComponent)->EffectAssetTags.AddLambda(
	[this](const FGameplayTagContainer& AssetTags)
		{
			for (const FGameplayTag& Tag : AssetTags)
			{
				// For example, say that Tag = Message.HealthPotion
				// "Message.HealthPotion".MatchesTag("Message") will return True, "Message".MatchesTag("Message.HealthPotion") will return False
				FGameplayTag MessageTag = FGameplayTag::RequestGameplayTag(FName("Message"));
				if (Tag.MatchesTag(MessageTag))
				{
					const FUIWidgetRow* Row = GetDataTableRowByTag<FUIWidgetRow>(MessageWidgetDataTable, Tag);
					MessageWidgetRowDelegate.Broadcast(*Row);
				}
			}
		}
	);
}