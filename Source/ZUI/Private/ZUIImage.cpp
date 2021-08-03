// Fill out your copyright notice in the Description page of Project Settings.


#include "ZUIImage.h"
#include "ZUI.h"

#define LOCTEXT_NAMESPACE "ZUI"

const FText UZUIImage::GetPaletteCategory()
{
	return LOCTEXT("ZUI", ZUI_CATEGORY_TEXT);
}

#undef LOCTEXT_NAMESPACE
