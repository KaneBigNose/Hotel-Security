// Made by LSH

#include "System/HSGameMode.h"
#include "UObject/ConstructorHelpers.h"

AHSGameMode::AHSGameMode()
{
	ConstructorHelpers::FClassFinder<APawn> PlayerPawnBP(TEXT("/Game/Player/Blueprint/BP_HSPlayer.BP_HSPlayer_C"));
	if (PlayerPawnBP.Succeeded())
	{
		DefaultPawnClass = PlayerPawnBP.Class;
	}

	ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBP(TEXT("/Game/Player/Blueprint/BP_HSPlayerController.BP_HSPlayerController_C"));
	if (PlayerControllerBP.Succeeded())
	{
		PlayerControllerClass = PlayerControllerBP.Class;
	}
}