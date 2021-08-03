// Fill out your copyright notice in the Description page of Project Settings.


#include "ZUIWSimpleButton.h"

#include "ZUIButton.h"
#include "ZUIImage.h"
#include "ZUITextBlock.h"

UZUIWSimpleButton::UZUIWSimpleButton(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	bIsToggleButton = false;
	bIsToggleOn = false;
}

void UZUIWSimpleButton::NativeConstruct()
{
	Super::NativeConstruct();
}

void UZUIWSimpleButton::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	
	if (MainLabel)
	{
		MainLabel->SetText(DefaultMainLabelText);
	}

	if (MainIcon)
	{
		MainIcon->SetBrush(DefaultIconBrush);
	}
	
}

void UZUIWSimpleButton::NativePreConstruct()
{
	Super::NativePreConstruct();
}

bool UZUIWSimpleButton::Initialize()
{
	const bool ParentIsSuccess = Super::Initialize();

	if (!IsDesignTime() && MainButton && ParentIsSuccess)
	{
		MainButton->OnClicked.AddDynamic(this, &UZUIWSimpleButton::HandleButtonClicked);
	}

	return ParentIsSuccess;
}

void UZUIWSimpleButton::BeginDestroy()
{
	if (MainButton)
	{
		MainButton->OnClicked.RemoveAll(this);
	}
	Super::BeginDestroy();
}


void UZUIWSimpleButton::SetButtonData(UObject* InButtonData)
{
	ButtonData = InButtonData;
}

void UZUIWSimpleButton::HandleButtonClicked()
{
	if (bIsToggleButton)
	{
		bIsToggleOn = !bIsToggleOn;
	}
	
	OnButtonClicked(ButtonData);
	OnZUIButtonClickedDelegate.Broadcast(ButtonData);
}

