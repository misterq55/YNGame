#pragma once
#include "YNGame/YNGameDefine.h"

class FYNPieceModel;
class FYNNodeModel;

class FYNMoveHandler
{
public:
	void StartMove(FYNMoveContext moveContext);
	void Update(float deltaTime);

private:
	TArray<TSharedPtr<FYNNodeModel>> MovePath;
	TSharedPtr<FYNPieceModel> PieceModel;
	TSharedPtr<FYNNodeModel> PrevNodeModel;
	TSharedPtr<FYNNodeModel> NextNodeModel;
	float MoveTimer = 0.f;
	float MoveSpeed = 1.f;
	int CurrentStepIndex = 1;
};
