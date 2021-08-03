// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "ZUIButton.generated.h"

/**
 * 
 */
UCLASS()
class ZUI_API UZUIButton : public UButton
{
	GENERATED_BODY()
public:
	virtual const FText GetPaletteCategory() override;
};
