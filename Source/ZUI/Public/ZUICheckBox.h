// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CheckBox.h"
#include "ZUICheckBox.generated.h"

/**
 * 
 */
UCLASS()
class ZUI_API UZUICheckBox : public UCheckBox
{
	GENERATED_BODY()
public:
	virtual const FText GetPaletteCategory() override;
};
