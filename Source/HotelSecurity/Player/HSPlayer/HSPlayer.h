// Made by LSH

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameplayTagContainer.h"
#include "HSPlayer.generated.h"

#define HSPLAYERWALKSPEED 150
#define HSPLAYERSPRINTSPEED 400

UCLASS()
class HOTEL_SECURITY_API AHSPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	AHSPlayer();

protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

public:
	FGameplayTagContainer& GetHSPlayerStateContainer() { return HSPlayerStateContainer; }
	class UCameraComponent* GetCameraComponent() { return Camera; }
	class UCameraComponent* GetZoomCameraComponent() { return ZoomCamera; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class AHSPlayerController* HSPlayerController;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USpringArmComponent* ZoomSpringArm;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UCameraComponent* ZoomCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FGameplayTagContainer HSPlayerStateContainer;
};