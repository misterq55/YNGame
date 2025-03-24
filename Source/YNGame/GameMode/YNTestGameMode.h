// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "YNGameModeBase.h"
#include "YNTestGameMode.generated.h"

/**
 * 
 */
UCLASS()
class YNGAME_API AYNTestGameMode : public AYNGameModeBase
{
	GENERATED_BODY()

public:
	virtual void StartPlay() override;
};
