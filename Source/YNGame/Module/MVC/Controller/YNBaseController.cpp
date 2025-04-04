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
	return 0;
}

void FYNBaseController::Move(const int32 steps)
{
}

void FYNBaseController::ChangeTurn()
{
}

void FYNBaseController::AdvanceStep()
{
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
