// Fill out your copyright notice in the Description page of Project Settings.


#include "ZUICheckBox.h"
#include "ZUI.h"


#define LOCTEXT_NAMESPACE "ZUI"

const FText UZUICheckBox::GetPaletteCategory()
{
	return LOCTEXT("ZUI", ZUI_CATEGORY_TEXT);
}

#undef LOCTEXT_NAMESPACE
