// Fill out your copyright notice in the Description page of Project Settings.


#include "ZUIUserWidget.h"

#define LOCTEXT_NAMESPACE "ZUI"

AGameStateBase* UZUIUserWidget::GetGameState() const
{
	return GetPlayerContext().IsValid() ? GetPlayerContext().GetGameState() : nullptr;
}

const FText UZUIUserWidget::GetPaletteCategory()
{
	return LOCTEXT("ZUI", "ZUI User Widgets");
}

#undef LOCTEXT_NAMESPACE
