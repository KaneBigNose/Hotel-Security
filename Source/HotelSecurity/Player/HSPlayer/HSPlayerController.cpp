// Made by LSH

#include "Player/HSPlayer/HSPlayerController.h"
#include "Player/HSPlayer/HSPlayer.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Kismet/KismetMathLibrary.h"
#include "GAS/HSPlayerGameplayTags.h"
#include "GameFramework/CharacterMovementComponent.h"

AHSPlayerController::AHSPlayerController()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AHSPlayerController::BeginPlay()
{
	Super::BeginPlay();

	HSPlayer = Cast<AHSPlayer>(GetPawn());

	if (auto* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(IMCDefault, 0);
	}
}

void AHSPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHSPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (auto* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(IAMove, ETriggerEvent::Triggered, this, &ThisClass::MoveTriggered);
		EnhancedInputComponent->BindAction(IAMove, ETriggerEvent::Completed, this, &ThisClass::MoveReleased);
		EnhancedInputComponent->BindAction(IAMove, ETriggerEvent::Canceled, this, &ThisClass::MoveReleased);

		EnhancedInputComponent->BindAction(IALook, ETriggerEvent::Triggered, this, &ThisClass::LookTriggered);
		EnhancedInputComponent->BindAction(IALook, ETriggerEvent::Completed, this, &ThisClass::LookReleased);
		EnhancedInputComponent->BindAction(IALook, ETriggerEvent::Canceled, this, &ThisClass::LookReleased);

		EnhancedInputComponent->BindAction(IAInteract, ETriggerEvent::Started, this, &ThisClass::InteractStarted);

		EnhancedInputComponent->BindAction(IASprint, ETriggerEvent::Triggered, this, &ThisClass::SprintTriggered);
		EnhancedInputComponent->BindAction(IASprint, ETriggerEvent::Completed, this, &ThisClass::SprintReleased);
		EnhancedInputComponent->BindAction(IASprint, ETriggerEvent::Canceled, this, &ThisClass::SprintReleased);

		EnhancedInputComponent->BindAction(IASitDown, ETriggerEvent::Started, this, &ThisClass::SitDownStarted);

		EnhancedInputComponent->BindAction(IAFlash, ETriggerEvent::Started, this, &ThisClass::FlashStarted);

		EnhancedInputComponent->BindAction(IAZoom, ETriggerEvent::Triggered, this, &ThisClass::ZoomTriggered);

		EnhancedInputComponent->BindAction(IAReport, ETriggerEvent::Started, this, &ThisClass::ReportStarted);

		EnhancedInputComponent->BindAction(IAEscape, ETriggerEvent::Started, this, &ThisClass::EscapeStarted);
	}
}

void AHSPlayerController::MoveTriggered(const FInputActionValue& InputValue)
{
	if (!HSPlayer)
	{
		return;
	}

	FVector2D MovementVector = InputValue.Get<FVector2D>();

	FRotator Rotator = GetControlRotation();

	if (MovementVector.X != 0)
	{
		HSPlayer->GetHSPlayerStateContainer().AddTag(HSPlayerGameplayTags::HSPlayer_State_Move);
		FVector Direction = UKismetMathLibrary::GetForwardVector(FRotator(0, Rotator.Yaw, 0));
		GetPawn()->AddMovementInput(Direction, MovementVector.X);
	}

	if (MovementVector.Y != 0)
	{
		HSPlayer->GetHSPlayerStateContainer().AddTag(HSPlayerGameplayTags::HSPlayer_State_Move);
		FVector Direction = UKismetMathLibrary::GetRightVector(FRotator(0, Rotator.Yaw, 0));
		GetPawn()->AddMovementInput(Direction, MovementVector.Y);
	}
}

void AHSPlayerController::MoveReleased(const FInputActionValue& InputValue)
{
	HSPlayer->GetHSPlayerStateContainer().RemoveTag(HSPlayerGameplayTags::HSPlayer_State_Move);
}

void AHSPlayerController::LookTriggered(const FInputActionValue& InputValue)
{
	if (!HSPlayer)
	{
		return;
	}

	FVector2D LookAxisVector = InputValue.Get<FVector2D>();

	HSPlayer->GetHSPlayerStateContainer().AddTag(HSPlayerGameplayTags::HSPlayer_State_Look);

	HSPlayer->AddControllerYawInput(LookAxisVector.X);
	HSPlayer->AddControllerPitchInput(LookAxisVector.Y);
}

void AHSPlayerController::LookReleased(const FInputActionValue& InputValue)
{
	HSPlayer->GetHSPlayerStateContainer().RemoveTag(HSPlayerGameplayTags::HSPlayer_State_Look);
}

void AHSPlayerController::InteractStarted(const FInputActionValue& InputValue)
{

}

void AHSPlayerController::SprintTriggered(const FInputActionValue& InputValue)
{
	HSPlayer->GetHSPlayerStateContainer().AddTag(HSPlayerGameplayTags::HSPlayer_State_Sprint);
	HSPlayer->GetCharacterMovement()->MaxWalkSpeed = HSPLAYERSPRINTSPEED;
}

void AHSPlayerController::SprintReleased(const FInputActionValue& InputValue)
{
	HSPlayer->GetHSPlayerStateContainer().RemoveTag(HSPlayerGameplayTags::HSPlayer_State_Sprint);
	HSPlayer->GetCharacterMovement()->MaxWalkSpeed = HSPLAYERWALKSPEED;
}

void AHSPlayerController::SitDownStarted(const FInputActionValue& InputValue)
{
	if (HSPlayer->GetHSPlayerStateContainer().HasTag(HSPlayerGameplayTags::HSPlayer_State_SitDown))
	{
		HSPlayer->GetHSPlayerStateContainer().RemoveTag(HSPlayerGameplayTags::HSPlayer_State_SitDown);
	}
	else
	{
		HSPlayer->GetHSPlayerStateContainer().AddTag(HSPlayerGameplayTags::HSPlayer_State_SitDown);
	}
}

void AHSPlayerController::FlashStarted(const FInputActionValue& InputValue)
{

}

void AHSPlayerController::ZoomTriggered(const FInputActionValue& InputValue)
{

}

void AHSPlayerController::ReportStarted(const FInputActionValue& InputValue)
{

}

void AHSPlayerController::EscapeStarted(const FInputActionValue& InputValue)
{

}