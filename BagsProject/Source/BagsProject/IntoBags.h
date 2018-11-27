// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WidgetBlueprintLibrary.h"
#include "Components/Image.h"
#include "Components/HorizontalBox.h"
#include "IntoBags.generated.h"

/**
 * 
 */
UCLASS()
class BAGSPROJECT_API UIntoBags : public UUserWidget
{
	GENERATED_BODY()

		virtual bool NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;

public:
	

protected:

	void NativeConstruct() override;

	//Í¼Æ¬ËØ²Ä
	UTexture2D* itemIcon;

	UImage* itemImg;

	UHorizontalBox* HorBox;
private:


	
};
