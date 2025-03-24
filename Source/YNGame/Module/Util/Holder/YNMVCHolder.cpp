#include "YNMVCHolder.h"

void FYNMVCHolder::SetModel(const TSharedPtr<IYNModel>& tnModel)
{
	YNModel = tnModel;
}

void FYNMVCHolder::SetView(const TSharedPtr<IYNView>& tnView)
{
	YNView = tnView;
}

void FYNMVCHolder::SetController(const TSharedPtr<IYNController>& tnController)
{
	YNController = tnController;
}

TSharedPtr<IYNModel> FYNMVCHolder::GetModel()
{
	return YNModel;
}

TSharedPtr<IYNView> FYNMVCHolder::GetView()
{
	return YNView;
}

TSharedPtr<IYNController> FYNMVCHolder::GetController()
{
	return YNController;
}
