// Copyright Rain


#include "Player/RainPlayerState.h"

#include "AbilitySystem/RainAbilitySystemComponent.h"
#include "AbilitySystem/RainAttributeSet.h"
#include "Net/UnrealNetwork.h"

ARainPlayerState::ARainPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<URainAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<URainAttributeSet>("AttributeSet");

	NetUpdateFrequency = 100.0f;
}

void ARainPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ARainPlayerState, Level);
}

UAbilitySystemComponent* ARainPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ARainPlayerState::OnRep_Level(int32 OldLevel)
{
}
