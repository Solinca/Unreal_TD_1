#include "MyPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/Character.h"

AMyPlayerController::AMyPlayerController()
{
}

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (!MappingContext)
	{
		return;
	}

	if (ULocalPlayer* localPlayer = Cast<ULocalPlayer>(Player))
	{
		if (TObjectPtr<UEnhancedInputLocalPlayerSubsystem> InputSystem = localPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			InputSystem->AddMappingContext(MappingContext, 0);
		}
	}
}

void AMyPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (TObjectPtr<UEnhancedInputComponent> EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		for (FInputData data : InputDatas)
		{
			EnhancedInputComponent->BindAction(data.Action, data.TriggerType, this, data.FunctionName);
		}
	}
}

void AMyPlayerController::Move(const FInputActionValue& Value)
{
	FVector MovementVector = Value.Get<FVector>();

	FRotator CameraRotation = FRotator(0.f, GetControlRotation().Yaw, 0.f);

	FVector RotatedVector = CameraRotation.RotateVector(MovementVector);

	GetPawn()->AddMovementInput(RotatedVector);
}

void AMyPlayerController::Look(const FInputActionValue& Value)
{
	FVector2D Values = Value.Get<FVector2D>();

	AddYawInput(Values.X * GetWorld()->GetDeltaSeconds() * CameraSensitivity);
	AddPitchInput(Values.Y * GetWorld()->GetDeltaSeconds() * CameraSensitivity);
}

void AMyPlayerController::Jump(const FInputActionValue& Value)
{
	if (ACharacter* MyChara = Cast<ACharacter>(GetPawn()))
	{
		MyChara->Jump();
	}
}

void AMyPlayerController::Dash(const FInputActionValue& value)
{
	if (ACharacter* MyChara = Cast<ACharacter>(GetPawn()))
	{
		MyChara->LaunchCharacter(MyChara->GetActorForwardVector() * LaunchVelocity, false, false);
	}
}
