// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Image.h"
#include "ZUIImage.generated.h"

/**
 * 
 */
UCLASS()
class ZUI_API UZUIImage : public UImage
{
	GENERATED_BODY()
public:
	virtual const FText GetPaletteCategory() override;
};
