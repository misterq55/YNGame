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
	float MoveTimer = 0.f;
	int CurrentStepIndex = 1;
};
