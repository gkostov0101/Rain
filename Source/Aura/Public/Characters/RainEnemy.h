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

	virtual int32 GetPlayerLevel() override;

protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Class Defaults")
	int32 Level = 1;
};
