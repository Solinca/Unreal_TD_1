#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class TD_1_NICOLAS_CORBI_API AMovingPlatform : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY()
	float Timer;
	
protected:
	AMovingPlatform();
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Settings")
	FVector Direction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Settings")
	float Speed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Settings")
	float Duration;
};
