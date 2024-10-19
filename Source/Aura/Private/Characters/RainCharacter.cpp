// Copyright Rain


#include "Characters/RainCharacter.h"
#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include <Player/RainPlayerState.h>

ARainCharacter::ARainCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 400.0f, 0.0f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}

void ARainCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	InitAbilityActorInfo();
}

void ARainCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	InitAbilityActorInfo();
}

void ARainCharacter::InitAbilityActorInfo()
{
	ARainPlayerState* RainPlayerState = GetPlayerState<ARainPlayerState>();
	check(RainPlayerState);
	RainPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(RainPlayerState, this);
	AbilitySystemComponent = RainPlayerState->GetAbilitySystemComponent();
	AttributeSet = RainPlayerState->GetAttributeSet();
}
