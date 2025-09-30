#include "Trap.h"
#include "PlayerHealthComponent.h"

ATrap::ATrap()
{
	Box = CreateDefaultSubobject<UBoxComponent>("Box");

	Box->SetupAttachment(RootComponent);
}

void ATrap::BeginPlay()
{
	Super::BeginPlay();

	Box->OnComponentBeginOverlap.AddDynamic(this, &ATrap::OnOverlapBegin);
	Box->OnComponentEndOverlap.AddDynamic(this, &ATrap::OnOverlapEnd);
}

void ATrap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATrap::OnOverlapBegin(UPrimitiveComponent* OverlappingComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (UPlayerHealthComponent* PlayerHealthComponent = OtherActor->GetComponentByClass<UPlayerHealthComponent>())
	{
		PlayerHealthComponent->UpdateHealth(-DamageToPlayer);
	}
}

void ATrap::OnOverlapEnd(UPrimitiveComponent* OverlappingComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "Box Exit");
}
