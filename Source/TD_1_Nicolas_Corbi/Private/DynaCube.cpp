#include "DynaCube.h"

ADynaCube::ADynaCube()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(RootComponent);
}

void ADynaCube::BeginPlay()
{
	Super::BeginPlay();

	// Option 1
	// UMaterialInstanceDynamic* DynaMat = UMaterialInstanceDynamic::Create(ParentMaterial, this);
	// Mesh->SetMaterial(0, DynaMat);

	// Option 2
	UMaterialInstanceDynamic* DynaMat = Mesh->CreateDynamicMaterialInstance(0, Mesh->GetMaterial(0));

	DynaMat->SetVectorParameterValue("BaseColor", FVector(1, 1, 0));

	OnExample.AddDynamic(this, &ADynaCube::OnCustomEvent);

	OnExample.Broadcast();
}

void ADynaCube::OnCustomEvent()
{
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "On Custom Event");
}
