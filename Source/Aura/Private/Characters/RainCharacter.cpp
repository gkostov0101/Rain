// Copyright Rain


#include "Characters/RainCharacter.h"
#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include <Player/RainPlayerState.h>

#include "AbilitySystem/RainAbilitySystemComponent.h"
#include "Player/RainPlayerController.h"
#include "UI/HUD/RainHUD.h"

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

int32 ARainCharacter::GetPlayerLevel()
{
	const ARainPlayerState* AuraPlayerState = GetPlayerState<ARainPlayerState>();
	check(AuraPlayerState);
	return AuraPlayerState->GetPlayerLevel();
}

void ARainCharacter::InitAbilityActorInfo()
{
	ARainPlayerState* RainPlayerState = GetPlayerState<ARainPlayerState>();
	check(RainPlayerState);
	RainPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(RainPlayerState, this);

	Cast<URainAbilitySystemComponent>(RainPlayerState->GetAbilitySystemComponent())->AbilityActorInfoSet();
	
	AbilitySystemComponent = RainPlayerState->GetAbilitySystemComponent();
	AttributeSet = RainPlayerState->GetAttributeSet();

	if (ARainPlayerController* RainPlayerController = Cast<ARainPlayerController>(GetController()))
	{
		if (ARainHUD* RainHUD = Cast<ARainHUD>(RainPlayerController->GetHUD()))
		{
			RainHUD->InitOverlay(RainPlayerController, RainPlayerState, AbilitySystemComponent, AttributeSet);
		}
	}
	InitializeDefaultAttributes();
}
