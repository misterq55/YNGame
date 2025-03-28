#pragma once

#include "YNGame/Module/Interface/IYNController.h"

class FYNBaseController : public IYNController
{
public:
	FYNBaseController();
	virtual ~FYNBaseController();
	
public:
	virtual int32 RollYut() override;
	virtual void Move(const int32 steps) override;
	virtual void ChangeTurn() override;
	virtual void AdvanceStep() override;
	virtual void AddComponent(const FName& name, const TSharedPtr<FYNControllerComponent>& newComponent) override;
	virtual void RemoveComponent(const FName& name) override;
	virtual void Update(float deltaTimes) override;

private:
	TMap<FName, TSharedPtr<FYNControllerComponent>> ControllerComponents;
};
