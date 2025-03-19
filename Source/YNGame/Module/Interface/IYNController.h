#pragma once

class FYNControllerComponent;

class IYNController
{
public:
	virtual int32 RollYut() = 0;
	virtual void Move(const int32 steps) = 0;
	virtual void ChangeTurn() = 0;
	virtual void AdvanceStep() = 0;
	virtual void AddComponent(const FName& name, const TSharedPtr<FYNControllerComponent>& newComponent) = 0;
	virtual void RemoveComponent(const FName& name) = 0;
};