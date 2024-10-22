// Copyright Rain


#include "Characters/RainCharacterBase.h"

ARainCharacterBase::ARainCharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

UAbilitySystemComponent* ARainCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ARainCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARainCharacterBase::InitAbilityActorInfo()
{
}
