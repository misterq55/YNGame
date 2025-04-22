// Fill out your copyright notice in the Description page of Project Settings.


#include "YNTestGameMode.h"
#include "YNGame/Module/Util/Holder/YNMVCHolder.h"
#include "YNGame/Module/MVC/Model/YNModel.h"
#include "YNGame/Module/MVC/Controller/YNBaseController.h"
#include "YNGame/Module/MVC/View/YNTestCliView.h"

AYNTestGameMode::AYNTestGameMode()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AYNTestGameMode::StartPlay()
{
	Super::StartPlay();

	FYNMVCHolder& holder = FYNMVCHolder::GetInstance();

	holder.SetModel(MakeShared<FYNModel>());
	holder.SetController(MakeShared<FYNBaseController>());
	holder.SetView(MakeShared<FYNTestCliView>());

	const TSharedPtr<IYNModel> model = holder.GetModel();
	if (!model.IsValid())
	{
		return;
	}
	
	const TSharedPtr<IYNController> controller = holder.GetController();
	if (!controller.IsValid())
	{
		return;
	}
	
	const TSharedPtr<IYNView> view = holder.GetView();
	if (!view.IsValid())
	{
		return;
	}
	
	model->Initialize();
	controller->Initialize();
	view->Initialize();
	
	model->GetOnPieceModelCreateEvent().BindSP(view.ToSharedRef(), &IYNView::CreatePieceView);
	model->GetOnNodeModelCreateEvent().BindSP(view.ToSharedRef(), &IYNView::CreateNodeView);
	model->GetOnPieceModelUpdateEvent().BindSP(view.ToSharedRef(), &IYNView::UpdatePieceView);
	model->GetOnNodeModelUpdateEvent().BindSP(view.ToSharedRef(), &IYNView::UpdateNodeView);

	// TODO
	// 피스와 노드 생성 로직 추가
}

void AYNTestGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	const TSharedPtr<IYNController> controller = FYNMVCHolder::GetInstance().GetController();
	if (!controller.IsValid())
	{
		return;
	}

	// 뷰를 업데이트 하는 로직이 모델의 업데이트안에 있다.
	controller->Update(DeltaSeconds);
}
