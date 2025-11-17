#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DynaCube.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FExampleDelegate);

UCLASS()
class TD_1_NICOLAS_CORBI_API ADynaCube : public AActor
{
	GENERATED_BODY()
	
protected:
	ADynaCube();
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UStaticMeshComponent> Mesh;

	// Only for Option 1
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UMaterialInterface> ParentMaterial = nullptr;

	UPROPERTY(BlueprintAssignable)
	FExampleDelegate OnExample;

private:
	UFUNCTION()
	void OnCustomEvent();
};
