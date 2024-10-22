// Copyright Rain

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "RainAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API URainAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	void AbilityActorInfoSet();

protected:
	void EffectApplied(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle);
};
