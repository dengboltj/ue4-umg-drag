// Fill out your copyright notice in the Description page of Project Settings.

#include "Item.h"
#include "Components/Image.h"
#include "Engine/Texture2D.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetTree.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "Layout/Geometry.h"
#include "Engine/Engine.h"
#include "WidgetBlueprintLibrary.h"

//UItem::UItem(const FObjectInitializer &  ObjectInitializer) : Super(ObjectInitializer)
//{
//	itemIcon = NULL;
//}

void UItem::SetInputPriority(int Priority)
{
	if (InputComponent)
	{
		InputComponent->Priority = Priority;
	}
}



void UItem::NativeConstruct()
{
	Super::NativeConstruct();
	DragDropOperation = NewObject<UDragDropOperation>();
	//加载图片资源
	if (itemIcon)
	{
		//如果已经加载过，则先销毁掉
		itemIcon->ConditionalBeginDestroy();
		itemIcon = NULL;
	}
	itemIcon = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/image/11.11'"));
	UCanvasPanel* Canvas = Cast<UCanvasPanel>(WidgetTree->RootWidget);
	if (Canvas)
	{
		if (WidgetTree)
		{
			//创建图片对象
			itemImg = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass());

			if (itemImg)
			{
				UPanelSlot* Slot = Canvas->AddChild(itemImg);
				if (UCanvasPanelSlot* cpSlot = Cast<UCanvasPanelSlot>(Slot))
				{
					cpSlot->SetAnchors(FAnchors(0.5f, 0.5f, 0.5f, 0.5f));
					cpSlot->SetPosition(FVector2D (-83.5f, 11.5f));
					cpSlot->SetSize(FVector2D(128, 128));
				}
				itemImg->SetBrushFromTexture(itemIcon, false);
				
			}
		}
	}
	
}

void UItem::NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InDragDropEvent, UDragDropOperation*& OutOperation)
{
	Super::NativeOnDragDetected(InGeometry, InDragDropEvent, OutOperation);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString("DragDetected+++++++++++++++++5"));
	if (DragDropOperation)
	{
		OutOperation = UWidgetBlueprintLibrary::CreateDragDropOperation(OutOperation->StaticClass());
		if (OutOperation)
		{
			UItem* Dragwidget = CreateWidget<UItem>(GetWorld()->GetFirstPlayerController(), this->GetClass());
			Dragwidget->itemImg = itemImg;
			OutOperation->DefaultDragVisual = Dragwidget;
			OutOperation->Payload = this;

			if (itemImg)
			{
				//隐藏
				itemImg->SetVisibility(ESlateVisibility::Hidden);
			}
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString("DragDetected+++++++++++++++5++++"));
		}
	}
}

void UItem::NativeOnDragEnter(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation)
{
	Super::NativeOnDragEnter(InGeometry, InDragDropEvent, InOperation);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Turquoise, FString("NativeOnDragEnter+++++++++++++++++4"));
}


void UItem::NativeOnDragLeave(const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) 
{
	Super::NativeOnDragLeave( InDragDropEvent, InOperation);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, FString("NativeOnDragLeave+++++++++++++++++2"));
}

bool UItem::NativeOnDragOver(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation)
{
	Super::NativeOnDragOver(InGeometry,InDragDropEvent, InOperation);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString("NativeOnDragOver+++++++++++++++++3"));
	return false;
}

bool UItem::NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation)
{
	Super::NativeOnDragOver(InGeometry, InDragDropEvent, InOperation);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString("NativeOnDrop+++++++++++++++++"));
	return false;
}

void UItem::NativeOnDragCancelled(const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation)
{
	Super::NativeOnDragCancelled(InDragDropEvent, InOperation);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Emerald, FString("NativeOnDragCancelled+++++++++++++++++1"));
	if (DragDropOperation)
	{
		InOperation = UWidgetBlueprintLibrary::CreateDragDropOperation(InOperation->StaticClass());
		if (InOperation)
		{
			UItem* Dragwidget = CreateWidget<UItem>(GetWorld()->GetFirstPlayerController(), this->GetClass());
			Dragwidget->itemImg = itemImg;
			InOperation->DefaultDragVisual = Dragwidget;

			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString("DragDetected+++++++++++++++5++++"));
		}
	}

}

FReply UItem::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);
	FEventReply reply = UWidgetBlueprintLibrary::DetectDragIfPressed(InMouseEvent, this, FKey("LeftMouseButton"));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, FString("NativeOnMouseButtonDown+++++++++++++++++10"));
	return reply.NativeReply;
}



