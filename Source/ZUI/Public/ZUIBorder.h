// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Border.h"
#include "ZUIBorder.generated.h"

/**
 * 
 */
UCLASS()
class ZUI_API UZUIBorder : public UBorder
{
	GENERATED_BODY()

public:
	virtual const FText GetPaletteCategory() override;
};
