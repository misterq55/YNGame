#pragma once

class FYNControllerComponent;

class IYNController
{
public:
	virtual void Initialize() = 0;
	virtual int32 RollYut() = 0;
	virtual void Move(const int32 steps) = 0;
	virtual void ChangeGameState() = 0;
	virtual void ChangeTurn() = 0;
	virtual void AdvanceStep() = 0;
	virtual void AddComponent(const FName& name, const TSharedPtr<FYNControllerComponent>& newComponent) = 0;
	virtual void RemoveComponent(const FName& name) = 0;
	virtual void Update(float deltaTimes) = 0;
};