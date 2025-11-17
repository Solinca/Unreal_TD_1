#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

class UMySaveGame;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSaveFinished);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLoadFinished, UMySaveGame*, MySaveGame);


UCLASS()
class TD_1_NICOLAS_CORBI_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void Load();

	UFUNCTION(BlueprintCallable)
	void Save();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Save")
	TObjectPtr<UMySaveGame> CustomSaveGame = nullptr;

	UPROPERTY(BlueprintAssignable)
	FOnLoadFinished OnLoadFinished;

	UPROPERTY(BlueprintAssignable)
	FOnSaveFinished OnSaveFinished;

private:
	UFUNCTION()
	void LoadGameFinished(const FString& SlotName, const int32 UserIndex, USaveGame* LoadedGameData);
	UFUNCTION()
	void SaveGameFinished(const FString& SlotName, const int32 UserIndex, bool Succeed);
};
