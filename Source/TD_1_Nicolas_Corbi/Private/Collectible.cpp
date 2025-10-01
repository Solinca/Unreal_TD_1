#include "Collectible.h"
#include "PlayerHealthComponent.h"

ACollectible::ACollectible()
{
	PrimaryActorTick.bCanEverTick = true;

	Box = CreateDefaultSubobject<UBoxComponent>("Box");

	Box->SetupAttachment(RootComponent);
}

void ACollectible::BeginPlay()
{
	Super::BeginPlay();

	Box->OnComponentBeginOverlap.AddDynamic(this, &ACollectible::OnOverlapBegin);
}

void ACollectible::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SetActorRotation(FRotator(0, GetActorRotation().Yaw + RotationSpeed * GetWorld()->DeltaRealTimeSeconds, 0));
}

void ACollectible::OnOverlapBegin(UPrimitiveComponent* OverlappingComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (UPlayerHealthComponent* PlayerHealthComponent = OtherActor->GetComponentByClass<UPlayerHealthComponent>())
	{
		PlayerHealthComponent->UpdateHealth(HealthRestoredAmount);

		Box->SetVisibility(false, true);
		Box->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
}
