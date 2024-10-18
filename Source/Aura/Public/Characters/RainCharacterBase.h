// Copyright Rain

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RainCharacterBase.generated.h"

UCLASS()
class AURA_API ARainCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ARainCharacterBase();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;
};