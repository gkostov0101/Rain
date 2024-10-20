// Copyright Rain

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RainEffectActor.generated.h"

class UGameplayEffect;

UCLASS()
class AURA_API ARainEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ARainEffectActor();

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* Target, TSubclassOf<UGameplayEffect> GameplayEffectClass);

	UPROPERTY(EditAnywhere, Category="Applied Effects")
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;
};
