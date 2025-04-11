#include "YNBaseController.h"

#include "YNGame/Module/Interface/IYNModel.h"
#include "YNGame/Module/Util/Holder/YNMVCHolder.h"

FYNBaseController::FYNBaseController()
{
}

FYNBaseController::~FYNBaseController()
{
}

void FYNBaseController::Initialize()
{
}

int32 FYNBaseController::RollYut()
{
	// TODO
	// 임시값
	const int yutValue = FMath::Rand() % 5;
	return yutValue;
}

void FYNBaseController::Move(const int32 steps)
{
	const auto& model = FYNMVCHolder::GetInstance().GetModel();
	if (!model.IsValid())
	{
		return;
	}

	model->Move(steps);
}

void FYNBaseController::ChangeTurn()
{
	const auto& model = FYNMVCHolder::GetInstance().GetModel();
	if (!model.IsValid())
	{
		return;
	}

	model->ChangeTurn();
}

void FYNBaseController::AdvanceStep()
{
	const auto& model = FYNMVCHolder::GetInstance().GetModel();
	if (!model.IsValid())
	{
		return;
	}

	model->AdvanceStep();
}

void FYNBaseController::AddComponent(const FName& name, const TSharedPtr<FYNControllerComponent>& newComponent)
{
}

void FYNBaseController::RemoveComponent(const FName& name)
{
}

void FYNBaseController::Update(float deltaTimes)
{
	TSharedPtr<IYNModel> model = FYNMVCHolder::GetInstance().GetModel();
	if (!model.IsValid())
	{
		return;
	}

	model->Update(deltaTimes);
}
