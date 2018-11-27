// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "BagsProjectGameMode.h"
#include "BagsProjectPlayerController.h"
#include "BagsProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

#include "Blueprint/UserWidget.h"

ABagsProjectGameMode::ABagsProjectGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ABagsProjectPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	MyWidgetInstance = nullptr;
}

void ABagsProjectGameMode::BeginPlay()
{
	//���Widget�����Ƿ���ڣ�����������Ƴ�����
	if (MyWidgetInstance)
	{
		MyWidgetInstance->RemoveFromViewport();
		MyWidgetInstance = nullptr;
	}

	//�����Զ���UMG��class��ͨ�����class����Widget���󣬲���ʾ�ڽ����С�WidgetBlueprint'/Game/UI/BagsWidget.BagsWidget'
	if (UClass* MyWidgetClass = LoadClass<UUserWidget>(NULL, TEXT("WidgetBlueprint'/Game/UI/BagsWidget.BagsWidget_C'")))
	{
		if (APlayerController* PC = GetWorld()->GetFirstPlayerController())
		{
			MyWidgetInstance = CreateWidget<UUserWidget>(PC, MyWidgetClass);
			if (MyWidgetInstance)
			{
				MyWidgetInstance->AddToViewport();
			}
		}
	}
}