#include "PlayerHealthComponent.h"

UPlayerHealthComponent::UPlayerHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UPlayerHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	Health = MaxHealth;
}

float UPlayerHealthComponent::GetHealth()
{
	return Health;
}

float UPlayerHealthComponent::GetMaxHealth()
{
	return MaxHealth;
}

void UPlayerHealthComponent::UpdateHealth(float DeltaHealth)
{
	Health += DeltaHealth;

	Health = FMath::Clamp(Health, 0.0f, MaxHealth);

	OnHealthChanged.Broadcast(Health, MaxHealth);

	if (Health <= 0.f)
	{
		OnHealthDepleted.Broadcast();
	}
}
