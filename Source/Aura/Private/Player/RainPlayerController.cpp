// Copyright Rain


#include "Player/RainPlayerController.h"
#include "EnhancedInputSubsystems.h"

ARainPlayerController::ARainPlayerController()
{
	bReplicates = true;
}

void ARainPlayerController::BeginPlay()
{
	Super::BeginPlay();

	check(RainContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(RainContext, 0);

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}