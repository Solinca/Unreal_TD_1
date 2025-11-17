#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <Components/TextBlock.h>
#include <Components/ProgressBar.h>
#include <Components/Button.h>
#include "MyUserWidget.generated.h"

UCLASS()
class TD_1_NICOLAS_CORBI_API UMyUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& Geometry, float DeltaTime) override;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> CustomText = nullptr;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UProgressBar> CustomProgressBar = nullptr;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> CustomButton = nullptr;

private:
	UFUNCTION()
	void OnClickTest();
};
