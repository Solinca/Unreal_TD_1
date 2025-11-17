#include "MyGameInstance.h"
#include "MySaveGame.h"
#include "Kismet/GameplayStatics.h"

void UMyGameInstance::Load()
{
	if (UGameplayStatics::DoesSaveGameExist("Slot", 0))
	{
		// Load not async
		// CustomSaveGame = Cast<UMySaveGame>(UGameplayStatics::LoadGameFromSlot("Slot", 0));

		FAsyncLoadGameFromSlotDelegate LoadDelegate;

		LoadDelegate.BindUObject(this, &UMyGameInstance::LoadGameFinished);

		UGameplayStatics::AsyncLoadGameFromSlot("Slot", 0, LoadDelegate);
	}
	else
	{
		CustomSaveGame = Cast<UMySaveGame>(UGameplayStatics::CreateSaveGameObject(UMySaveGame::StaticClass()));
	}
}

void UMyGameInstance::Save()
{
	// Save not async
	// UGameplayStatics::SaveGameToSlot(CustomSaveGame, "Slot", 0);

	FAsyncSaveGameToSlotDelegate SaveDelegate;

	SaveDelegate.BindUObject(this, &UMyGameInstance::SaveGameFinished);

	UGameplayStatics::AsyncSaveGameToSlot(CustomSaveGame, "Slot", 0, SaveDelegate);
}

void UMyGameInstance::LoadGameFinished(const FString& SlotName, const int32 UserIndex, USaveGame* LoadedGameData)
{
	CustomSaveGame = Cast<UMySaveGame>(LoadedGameData);

	OnLoadFinished.Broadcast(CustomSaveGame);

	//GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "Load Finished");
}

void UMyGameInstance::SaveGameFinished(const FString& SlotName, const int32 UserIndex, bool Succeed)
{
	OnSaveFinished.Broadcast();
}
