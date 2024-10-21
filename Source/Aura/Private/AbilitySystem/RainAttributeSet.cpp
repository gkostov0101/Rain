// Copyright Rain


#include "AbilitySystem/RainAttributeSet.h"
#include "Net/UnrealNetwork.h"

URainAttributeSet::URainAttributeSet()
{
	InitHealth(50.0f);
	InitMaxHealth(100.0f);

	InitMana(50.0f);
	InitMaxMana(150.0f);
}

void URainAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// Health
	DOREPLIFETIME_CONDITION_NOTIFY(URainAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URainAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);

	// Mana
	DOREPLIFETIME_CONDITION_NOTIFY(URainAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URainAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
}

void URainAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URainAttributeSet, Health, OldHealth);
}

void URainAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URainAttributeSet, MaxHealth, OldMaxHealth);
}

void URainAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URainAttributeSet, Mana, OldMana);
}

void URainAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URainAttributeSet, MaxMana, OldMaxMana);
}