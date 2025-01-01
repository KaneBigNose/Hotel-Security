// Made by LSH

#include "Player/HSPlayer/HSPlayer.h"
#include "Player/HSPlayer/HSPlayerController.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GAS/HSPlayerGameplayTags.h"

AHSPlayer::AHSPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

	GetMesh()->SetRelativeLocationAndRotation(FVector(0, 0, -93), FRotator(0, -90, 0));

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 150.0f;
	SpringArm->bUsePawnControlRotation = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
	Camera->SetRelativeLocation(FVector(0, 30, 45));
	Camera->bUsePawnControlRotation = true;

	ZoomSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("ZoomSpringArm"));
	ZoomSpringArm->SetupAttachment(RootComponent);
	ZoomSpringArm->TargetArmLength = 150.0f;

	ZoomCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ZoomCamera"));
	ZoomCamera->SetupAttachment(ZoomSpringArm);
	ZoomCamera->SetRelativeLocation(FVector(300, 30, 45));

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);

	GetCharacterMovement()->MaxWalkSpeed = HSPLAYERWALKSPEED;
}

void AHSPlayer::BeginPlay()
{
	Super::BeginPlay();
	
	HSPlayerController = Cast<AHSPlayerController>(GetController());

	Camera->SetActive(true);

	ZoomCamera->SetActive(false);
}

void AHSPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}