// Made by LSH

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "HSPlayerController.generated.h"

struct FInputActionValue;
class UInputMappingContext;
class UInputAction;

UCLASS()
class HOTEL_SECURITY_API AHSPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AHSPlayerController();
	
public:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	virtual void SetupInputComponent() override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class AHSPlayer* HSPlayer;

#pragma region Input

protected:
	void MoveTriggered(const FInputActionValue& InputValue);
	void MoveReleased(const FInputActionValue& InputValue);

	void LookTriggered(const FInputActionValue& InputValue);
	void LookReleased(const FInputActionValue& InputValue);

	void InteractStarted(const FInputActionValue& InputValue);

	void SprintTriggered(const FInputActionValue& InputValue);
	void SprintReleased(const FInputActionValue& InputValue);

	void SitDownStarted(const FInputActionValue& InputValue);

	void FlashStarted(const FInputActionValue& InputValue);

	void ZoomTriggered(const FInputActionValue& InputValue);

	void ReportStarted(const FInputActionValue& InputValue);

	void EscapeStarted(const FInputActionValue& InputValue);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputMappingContext* IMCDefault;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* IAMove;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* IALook;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* IAInteract;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* IASprint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* IASitDown;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* IAFlash;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* IAZoom;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* IAReport;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* IAEscape;

#pragma endregion
};