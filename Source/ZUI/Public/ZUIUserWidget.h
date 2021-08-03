// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ZUIUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class ZUI_API UZUIUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	
	virtual class AGameStateBase* GetGameState() const;

	template<typename T>
	T* GetGameState(bool bCastChecked = false) const
	{
		if (bCastChecked)
		{
			return CastChecked<T>(GetGameState(), ECastCheckedType::NullAllowed);
		}
		else
		{
			return Cast<T>(GetGameState());
		}
	}

	virtual const FText GetPaletteCategory() override;
};
