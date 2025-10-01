#include "Trap.h"
#include "PlayerHealthComponent.h"

ATrap::ATrap()
{
	PrimaryActorTick.bCanEverTick = false;

	Box = CreateDefaultSubobject<UBoxComponent>("Box");

	Box->SetupAttachment(RootComponent);
}

void ATrap::BeginPlay()
{
	Super::BeginPlay();

	Box->OnComponentBeginOverlap.AddDynamic(this, &ATrap::OnOverlapBegin);
	Box->OnComponentHit.AddDynamic(this, &ATrap::OnHit);
}

void ATrap::OnOverlapBegin(UPrimitiveComponent* OverlappingComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (UPlayerHealthComponent* PlayerHealthComponent = OtherActor->GetComponentByClass<UPlayerHealthComponent>())
	{
		PlayerHealthComponent->UpdateHealth(DamageToPlayer);
	}
}

void ATrap::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (UPlayerHealthComponent* PlayerHealthComponent = OtherActor->GetComponentByClass<UPlayerHealthComponent>())
	{
		PlayerHealthComponent->UpdateHealth(DamageToPlayer);
	}
}
