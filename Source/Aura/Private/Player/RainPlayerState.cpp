// Copyright Rain


#include "Player/RainPlayerState.h"

#include "AbilitySystem/RainAbilitySystemComponent.h"
#include "AbilitySystem/RainAttributeSet.h"

ARainPlayerState::ARainPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<URainAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);

	AttributeSet = CreateDefaultSubobject<URainAttributeSet>("AttributeSet");

	NetUpdateFrequency = 100.0f;
}

UAbilitySystemComponent* ARainPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}