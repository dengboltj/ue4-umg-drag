// Fill out your copyright notice in the Description page of Project Settings.

#include "Bags.h"
#include "Components/Image.h"
#include "Engine/Texture2D.h"
#include "Components/CanvasPanel.h"
#include "Components/HorizontalBox.h"
#include "Components/HorizontalBoxSlot.h"
#include "Blueprint/WidgetTree.h"
#include "Components/CanvasPanelSlot.h"

#include "Item.h"
#include "IntoBags.h"

void UBags::NativeConstruct()
{
	Super::NativeConstruct();

	/*auto MyCanvas = WidgetTree->ConstructWidget<UCanvasPanel>(UCanvasPanel::StaticClass());
	if (MyCanvas)
	{
		auto MyButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass());
		MyCanvas->AddChild(MyButton);

		WidgetTree->RootWidget = MyCanvas;
	}*/

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
			UHorizontalBox* HorBox = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass());
			if (HorBox)
			{
				Canvas->AddChild(HorBox);
				UPanelSlot* SlotBox = HorBox->Slot;
				if (UCanvasPanelSlot* HorSlotBox = Cast<UCanvasPanelSlot>(SlotBox))
				{
					HorSlotBox->SetSize(FVector2D(1469, 253));
					HorSlotBox->SetPosition(FVector2D(-806, -398));
					HorSlotBox->SetAnchors(FAnchors(0.5f, 0.5f, 0.5f, 0.5f));

				}
				if (UClass* MyWidgetClass = LoadClass<UItem>(NULL, TEXT("WidgetBlueprint'/Game/UI/ItemBP.ItemBP_C'")))
				{
					for (int i = 0; i < 5; i++)
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
						/*Slot->set*/
					}
				}
				
			}
			if (UClass* BagClass = LoadClass<UIntoBags>(NULL, TEXT("WidgetBlueprint'/Game/UI/bagBP.bagBP_C'")))
			{
				UIntoBags* intoBags = WidgetTree->ConstructWidget<UIntoBags>(BagClass);
				if (intoBags)
				{
					UPanelSlot* Slot = Canvas->AddChild(intoBags);
					if (UCanvasPanelSlot* HorSlot = Cast<UCanvasPanelSlot>(Slot))
					{

						HorSlot->SetSize(FVector2D(1000, 1000));
						HorSlot->SetPosition(FVector2D(764, 684));
						HorSlot->SetAnchors(FAnchors(0, 0, 0, 0));
					}
				}
			}
		}
	}
	

}
