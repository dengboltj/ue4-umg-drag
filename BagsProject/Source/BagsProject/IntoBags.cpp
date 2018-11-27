// Fill out your copyright notice in the Description page of Project Settings.

#include "IntoBags.h"
#include "Components/Image.h"
#include "Engine/Texture2D.h"
#include "Components/CanvasPanel.h"
#include "Components/HorizontalBox.h"
#include "Components/HorizontalBoxSlot.h"
#include "Blueprint/WidgetTree.h"
#include "Components/CanvasPanelSlot.h"
#include "Engine/Engine.h"

#include "Item.h"

void UIntoBags::NativeConstruct()
{
	Super::NativeConstruct();

	UCanvasPanel* Canvas = Cast<UCanvasPanel>(WidgetTree->RootWidget);
	if (Canvas)
	{
		/*UButton* MyButton = Canvas->ConstructWidget<UButton>(UButton::StaticClass());
		MyCanvas->AddChild(MyButton);*/

		//获取horizontalBox对象 UWidget* Widget = GetWidgetFromName(FName("HorizontalBox_62"));
		//UHorizontalBox* HorBox = Cast<UHorizontalBox>(GetWidgetFromName(FName("HorizontalBox_62")));

		if (WidgetTree)
		{
			//创建horizontalBox对象
			HorBox = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass());
			if (HorBox)
			{
				Canvas->AddChild(HorBox);
				UPanelSlot* SlotBox = HorBox->Slot;
				if (UCanvasPanelSlot* HorSlotBox = Cast<UCanvasPanelSlot>(SlotBox))
				{
					HorSlotBox->SetSize(FVector2D(702, 306));
					HorSlotBox->SetPosition(FVector2D(44, 20));
					HorSlotBox->SetAnchors(FAnchors(0, 0, 0, 0));
			
				}
				if (UClass* MyWidgetClass = LoadClass<UItem>(NULL, TEXT("WidgetBlueprint'/Game/UI/ItemBP.ItemBP_C'")))
				{
					for (int i = 0; i < 1; i++)
					{
						UItem* Item = WidgetTree->ConstructWidget<UItem>(MyWidgetClass);
						if (Item)
						{
							UPanelSlot* Slot = HorBox->AddChild(Item);
							if (UHorizontalBoxSlot* HorSlot = Cast<UHorizontalBoxSlot>(Slot))
							{
								FSlateChildSize Size(ESlateSizeRule::Type::Fill);
								HorSlot->SetSize(Size);
								HorSlot->SetPadding(0);
								HorSlot->SetHorizontalAlignment(EHorizontalAlignment::HAlign_Center);
								HorSlot->SetVerticalAlignment(EVerticalAlignment::VAlign_Center);

							}

							Item->SetInputPriority(0);

						}
					}
				}

			}
		}
	}

}

bool UIntoBags::NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation)
{
	if (HorBox)
	{
		if (UClass* MyWidgetClass = LoadClass<UItem>(NULL, TEXT("WidgetBlueprint'/Game/UI/ItemBP.ItemBP_C'")))
		{
			UItem* Item = WidgetTree->ConstructWidget<UItem>(MyWidgetClass);
			if (Item)
			{
				UPanelSlot* Slot = HorBox->AddChild(Item);
				if (UHorizontalBoxSlot* HorSlot = Cast<UHorizontalBoxSlot>(Slot))
				{
					FSlateChildSize Size(ESlateSizeRule::Type::Fill);
					HorSlot->SetSize(Size);
					HorSlot->SetPadding(0);
					HorSlot->SetHorizontalAlignment(EHorizontalAlignment::HAlign_Center);
					HorSlot->SetVerticalAlignment(EVerticalAlignment::VAlign_Center);
				}

				Item->SetInputPriority(0);

		    }			
		}
	}
	return true;
}






	////加载图片资源
	//if (itemIcon)
	//{
	//	//如果已经加载过，则先销毁掉
	//	itemIcon->ConditionalBeginDestroy();
	//	itemIcon = NULL;
	//}
	//itemIcon = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/image/0.0'"));

	//UCanvasPanel* Canvas = Cast<UCanvasPanel>(WidgetTree->RootWidget);
	//if (Canvas)
	//{
	//	if (WidgetTree)
	//	{
	//		if (WidgetTree)
	//		{
	//			//创建图片对象
	//			UImage* itemImg = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass());

	//			if (itemImg)
	//			{
	//				UPanelSlot* Slot = Canvas->AddChild(itemImg);
	//				if (UCanvasPanelSlot* cpSlot = Cast<UCanvasPanelSlot>(Slot))
	//				{
	//					cpSlot->SetAnchors(FAnchors(0, 0, 0, 0));
	//					cpSlot->SetPosition(FVector2D(16,24));
	//					cpSlot->SetSize(FVector2D(230, 230));
	//				}
	//				itemImg->SetBrushFromTexture(itemIcon, false);

	//			}
	//		}
	//	}
	//}


