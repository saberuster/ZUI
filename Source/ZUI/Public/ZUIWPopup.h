// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ZUIUserWidget.h"
#include "ZUIWPopup.generated.h"


class UZUIButton;
class UZUITextBlock;
class UZUINamedSlot;
/**
 * 
 */
UCLASS()
class ZUI_API UZUIWPopup : public UZUIUserWidget
{
	GENERATED_BODY()
public:
	
	explicit UZUIWPopup(const FObjectInitializer& ObjectInitializer);
	
protected:

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	TObjectPtr<UZUINamedSlot> ContentSlot;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	TObjectPtr<UZUITextBlock> HeaderTextBlock;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCloseButtonClickedSignature);

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	TObjectPtr<UZUIButton> CloseButton;

	UPROPERTY(EditAnywhere, Category="ZUI")
	uint8 bRemoveOnClose:1;

public:
	
	UPROPERTY(BlueprintAssignable, meta=(DisplayName="CloseButton Clicked"))
	FOnCloseButtonClickedSignature OnCloseButtonClickedDelegate;

	UFUNCTION(BlueprintCallable)
	void SetContent(UWidget* Content);

	UFUNCTION(BlueprintCallable)
	void SetHeaderText(const FText& InHeaderText);

	UFUNCTION(BlueprintCallable)
	void ClosePopup();


	virtual bool Initialize() override;
	virtual void BeginDestroy() override;

	virtual void SynchronizeProperties() override;
	
#if WITH_EDITOR

	virtual void OnCreationFromPalette() override;
	
#endif
	
protected:
	
	UFUNCTION()
	virtual void HandleCloseButtonClicked();
    	
};

