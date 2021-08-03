// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SizeBox.h"
#include "ZUISizeBox.generated.h"

/**
 * 
 */
UCLASS()
class ZUI_API UZUISizeBox : public USizeBox
{
	GENERATED_BODY()
public:
	virtual const FText GetPaletteCategory() override;
};
