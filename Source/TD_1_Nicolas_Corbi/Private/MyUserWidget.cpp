#include "MyUserWidget.h"

void UMyUserWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	if (CustomText)
	{
		CustomText->SetText(FText::FromString("Helloooooooooooooooo"));
	}

	if (CustomProgressBar)
	{
		CustomProgressBar->SetPercent(0.7f);
	}
}

void UMyUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (CustomButton)
	{
		CustomButton->OnClicked.AddDynamic(this, &UMyUserWidget::OnClickTest);
	}
}

void UMyUserWidget::NativeTick(const FGeometry& Geometry, float DeltaTime)
{
	Super::NativeTick(Geometry, DeltaTime);
}

void UMyUserWidget::OnClickTest()
{
	if (CustomText)
	{
		CustomText->SetText(FText::FromString("NANI?!?!?"));
	}
}
