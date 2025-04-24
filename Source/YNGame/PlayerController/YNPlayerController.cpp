// Fill out your copyright notice in the Description page of Project Settings.


#include "YNPlayerController.h"

#include "YNGame/YNGameDefine.h"
#include "YNGame/Module/Interface/IYNController.h"
#include "YNGame/Module/Interface/IYNModel.h"
#include "YNGame/Module/Util/Holder/YNMVCHolder.h"

void AYNPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

bool AYNPlayerController::ProcessConsoleExec(const TCHAR* Cmd, FOutputDevice& Ar, UObject* Executor)
{
	FString CommandString = FString(Cmd);
	
	const auto& controller = FYNMVCHolder::GetInstance().GetController();
	if (!controller.IsValid())
	{
		return false;
	}

	const auto& model = FYNMVCHolder::GetInstance().GetModel();
	if (!model.IsValid())
	{
		return false;
	}

	if (model->GetCurrentStepState() == E_KStepState::RollYut)
	{
		if (CommandString == TEXT("RollYut"))
		{
			controller->RollYut();
		}
	}
	
	return true;
}
