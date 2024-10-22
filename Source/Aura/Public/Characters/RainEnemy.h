// Copyright Rain

#pragma once

#include "CoreMinimal.h"
#include "Characters/RainCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "RainEnemy.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API ARainEnemy : public ARainCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()
	
public:
	ARainEnemy();

	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;

protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;
};
