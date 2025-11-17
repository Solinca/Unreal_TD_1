#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Components/TimelineComponent.h>
#include "MyNewMovingPlatform.generated.h"

UCLASS()
class TD_1_NICOLAS_CORBI_API AMyNewMovingPlatform : public AActor
{
	GENERATED_BODY()
	
protected:
	AMyNewMovingPlatform();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Timeline")
	TObjectPtr<UCurveFloat> TimeCurve = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UStaticMeshComponent> Mesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Settings")
	FVector Movement;

private:
	FTimeline ExampleTimeline = FTimeline();
	FOnTimelineFloat TimelineProgressEvent{};
	FOnTimelineEvent TimelineEndEvent{};

	FVector StartPosition;

	UFUNCTION()
	void TimelineProgressFunction(float Value);

	UFUNCTION()
	void TimelineEndFunction();
};
