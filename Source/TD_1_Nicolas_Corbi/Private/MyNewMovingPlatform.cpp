#include "MyNewMovingPlatform.h"

AMyNewMovingPlatform::AMyNewMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(RootComponent);
}

void AMyNewMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartPosition = Mesh->GetRelativeLocation();

	TimelineProgressEvent.BindUFunction(this, "TimelineProgressFunction");
	ExampleTimeline.AddInterpFloat(TimeCurve, TimelineProgressEvent);

	TimelineEndEvent.BindUFunction(this, "TimelineEndFunction");
	ExampleTimeline.SetTimelineFinishedFunc(TimelineEndEvent);

	ExampleTimeline.PlayFromStart();
}

void AMyNewMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ExampleTimeline.TickTimeline(DeltaTime);
}

void AMyNewMovingPlatform::TimelineProgressFunction(float Value)
{
	Mesh->SetRelativeLocation(StartPosition + Value * Movement);
}

void AMyNewMovingPlatform::TimelineEndFunction()
{
	ExampleTimeline.PlayFromStart();
}
