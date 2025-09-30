#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Trap.generated.h"

UCLASS()
class TD_1_NICOLAS_CORBI_API ATrap : public AActor
{
	GENERATED_BODY()
	
protected:
	ATrap();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, Category = "Damage")
	float DamageToPlayer;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UBoxComponent> Box = nullptr;

private:
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappingComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappingComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
