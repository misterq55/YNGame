#pragma once
#include "YNGame/YNGameDefine.h"

DECLARE_DELEGATE_TwoParams(FYNOnMoveEndEvent, const int32, const FYNPieceIndex&);

class FYNPieceModel;
class FYNNodeModel;

class FYNMoveHandler
{
public:
	void StartMove(const FYNMoveContext& moveContext);
	void Update(float deltaTime);

	FYNOnMoveEndEvent& GetMoveEndEvent() { return MoveEndEvent; }
	
private:
	TArray<TSharedPtr<FYNNodeModel>> MovePath;
	TSharedPtr<FYNPieceModel> PieceModel;
	TSharedPtr<FYNNodeModel> PrevNodeModel;
	TSharedPtr<FYNNodeModel> NextNodeModel;
	float MoveTimer = 0.f;
	float MoveSpeed = 1.f;
	int CurrentStepIndex = 1;
	FYNOnMoveEndEvent MoveEndEvent;
};
