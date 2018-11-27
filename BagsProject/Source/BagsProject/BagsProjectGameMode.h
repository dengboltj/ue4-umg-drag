// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BagsProjectGameMode.generated.h"

UCLASS(minimalapi)
class ABagsProjectGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ABagsProjectGameMode();

protected:

	virtual void BeginPlay() override;

private:

	//UMG��ͼ��ʵ������������ʾ����Ϸ��Viewport��
	UUserWidget* MyWidgetInstance;
};



