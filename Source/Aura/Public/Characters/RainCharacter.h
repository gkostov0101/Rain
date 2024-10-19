// Copyright Rain

#pragma once

#include "CoreMinimal.h"
#include "Characters/RainCharacterBase.h"
#include "RainCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API ARainCharacter : public ARainCharacterBase
{
	GENERATED_BODY()
	
public:
	ARainCharacter();

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

private:
	void InitAbilityActorInfo();
};
