// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Item.generated.h"


/**
 * 
 */
UCLASS()
class BAGSPROJECT_API UItem : public UUserWidget
{
	GENERATED_BODY()
	
public:

	void SetInputPriority(int Priority);

	//���ڲ�����ק��UMG�ڲ���
	UDragDropOperation * DragDropOperation;
	
protected:

	void NativeConstruct() override;


	 void NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent, UDragDropOperation*& OutOperation) override;
	 void NativeOnDragEnter(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;
	 void NativeOnDragLeave(const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;
	 bool NativeOnDragOver(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;
	 bool NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;
	 void NativeOnDragCancelled(const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;

	 FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;

private:
	//ͼƬ�ز�
	UTexture2D* itemIcon;

	UImage* itemImg;
private:

	//UMG��ͼ��ʵ������������ʾ����Ϸ��Viewport��
	UUserWidget* MyItemWidgetInstance;

	
};
