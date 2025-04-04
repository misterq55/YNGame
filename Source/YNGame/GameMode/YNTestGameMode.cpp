// Fill out your copyright notice in the Description page of Project Settings.


#include "YNTestGameMode.h"
#include "YNGame/Module/Util/Holder/YNMVCHolder.h"
#include "YNGame/Module/MVC/Model/YNModel.h"
#include "YNGame/Module/MVC/Controller/YNBaseController.h"
#include "YNGame/Module/MVC/View/YNView.h"

void AYNTestGameMode::StartPlay()
{
	Super::StartPlay();

	FYNMVCHolder::GetInstance().SetModel(MakeShareable(new FYNModel()));
	FYNMVCHolder::GetInstance().SetController(MakeShareable(new FYNBaseController));
	FYNMVCHolder::GetInstance().SetView(MakeShareable(new FYNView()));

	const auto& model = FYNMVCHolder::GetInstance().GetModel();
	if (model.IsValid())
	{
		model->Initialize();
	}
	
	const auto& controller = FYNMVCHolder::GetInstance().GetController();
	if (controller.IsValid())
	{
		
	}
	
	const auto& view = FYNMVCHolder::GetInstance().GetView();
}

void AYNTestGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	const TSharedPtr<IYNController> controller = FYNMVCHolder::GetInstance().GetController();
	if (!controller.IsValid())
	{
		return;
	}

	controller->Update(DeltaSeconds);
}
