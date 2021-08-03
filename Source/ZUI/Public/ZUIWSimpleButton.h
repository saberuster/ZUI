// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "ZUIUserWidget.h"
#include "ZUIWSimpleButton.generated.h"

class UZUIButton;
class UZUIImage;
class UZUITextBlock;

/**
 * 
 */
UCLASS()
class ZUI_API UZUIWSimpleButton : public UZUIUserWidget
{
	GENERATED_BODY()
public:
	explicit UZUIWSimpleButton(const FObjectInitializer& ObjectInitializer);
	
protected:

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="ZUI")
	FText DefaultMainLabelText;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="ZUI")
	FSlateBrush DefaultIconBrush;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="ZUI")
	uint8 bIsToggleButton:1;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="ZUI")
	uint8 bIsToggleOn:1;
	
	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	TObjectPtr<UZUITextBlock> MainLabel;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	TObjectPtr<UZUIImage> MainIcon;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	TObjectPtr<UZUIButton> MainButton;

	UPROPERTY(Transient, BlueprintReadWrite, meta=(ExposeOnSpawn="true"))
	TObjectPtr<UObject> ButtonData;
	
public:

	void SetButtonData(UObject* InButtonData);

protected:

	UFUNCTION(BlueprintImplementableEvent)
	void OnButtonClicked(UObject* Data);
	
public:
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnZUIButtonClickedSignature, UObject*, Data);
	
	UPROPERTY(BlueprintAssignable, meta=(DisplayName="On ZUI Clicked"))
	FOnZUIButtonClickedSignature OnZUIButtonClickedDelegate;
	
protected:
	UFUNCTION()
	virtual void HandleButtonClicked();

	virtual void NativeConstruct() override;


public:
	virtual void SynchronizeProperties() override;
protected:
	virtual void NativePreConstruct() override;
public:
	virtual bool Initialize() override;
	virtual void BeginDestroy() override;
};
