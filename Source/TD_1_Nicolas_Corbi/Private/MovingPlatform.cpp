#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Timer += GetWorld()->DeltaRealTimeSeconds;

	if (Timer >= Duration)
	{
		Timer = 0.f;

		Direction *= -1;
	}

	SetActorLocation(GetActorLocation() + Direction * Speed * DeltaTime);
}

