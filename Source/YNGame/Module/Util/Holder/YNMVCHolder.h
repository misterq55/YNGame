#pragma once
#include "YNGame/Module/Util/Singleton/Singleton.h"

class IYNModel;
class IYNView;
class IYNController;

class FYNMVCHolder : public TYNSingleton<FYNMVCHolder>
{
private:
	TSharedPtr<IYNModel> YNModel;
	TSharedPtr<IYNView> YNView;
	TSharedPtr<IYNController> YNController;

public:
	void SetModel(const TSharedPtr<IYNModel>& tnModel);
	void SetView(const TSharedPtr<IYNView>& tnView);
	void SetController(const TSharedPtr<IYNController>& tnController);

	TSharedPtr<IYNModel> GetModel();
	TSharedPtr<IYNView> GetView();
	TSharedPtr<IYNController> GetController();
};