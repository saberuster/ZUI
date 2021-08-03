// Fill out your copyright notice in the Description page of Project Settings.


#include "ZUIWPopup.h"

#include "ZUIButton.h"
#include "ZUINamedSlot.h"
#include "ZUITextBlock.h"

#define LOCTEXT_NAMESPACE "ZUI"

UZUIWPopup::UZUIWPopup(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
}

void UZUIWPopup::SetContent(UWidget* Content)
{
	ContentSlot->SetContent(Content);
}

void UZUIWPopup::SetHeaderText(const FText& InHeaderText)
{
	HeaderTextBlock->SetText(InHeaderText);
}

void UZUIWPopup::ClosePopup()
{
	HandleCloseButtonClicked();
}

void UZUIWPopup::HandleCloseButtonClicked()
{
	OnCloseButtonClickedDelegate.Broadcast();
	
	if (bRemoveOnClose)
	{
		RemoveFromParent();
	}
}

bool UZUIWPopup::Initialize()
{
	bool Return = Super::Initialize();

	if (Return)
	{
		if (CloseButton)
		{
			CloseButton->OnClicked.AddDynamic(this, &UZUIWPopup::HandleCloseButtonClicked);
		}
	}

	return Return;
}

void UZUIWPopup::BeginDestroy()
{
	Super::BeginDestroy();
}

void UZUIWPopup::SynchronizeProperties()
{
	Super::SynchronizeProperties();
}

void UZUIWPopup::OnCreationFromPalette()
{
	if (HeaderTextBlock)
	{
		HeaderTextBlock->SetText(LOCTEXT("DefaultHeaderText", "Default Header"));
	}
}

#undef LOCTEXT_NAMESPACE
