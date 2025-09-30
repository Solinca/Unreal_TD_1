#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerHealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHealthDepletedSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHealthChangedSignature, float, NewHealth, float, MaxHealth);


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TD_1_NICOLAS_CORBI_API UPlayerHealthComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	UPlayerHealthComponent();
	virtual void BeginPlay() override;

	UPROPERTY()
	float Health;

	UPROPERTY(EditDefaultsOnly, Category = "Health")
	float MaxHealth;

public:
	UPROPERTY(BlueprintAssignable, Category = "Health")
	FOnHealthChangedSignature OnHealthChanged;

	UPROPERTY(BlueprintAssignable, Category = "Health")
	FOnHealthDepletedSignature OnHealthDepleted;

	UFUNCTION(BlueprintCallable)
	float GetHealth();

	UFUNCTION(BlueprintCallable)
	float GetMaxHealth();

	UFUNCTION(BlueprintCallable)
	void UpdateHealth(float DeltaHealth);
};
