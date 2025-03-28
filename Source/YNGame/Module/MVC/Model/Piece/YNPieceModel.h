#pragma once

#include "YNGame/YNGameDefine.h"

class FYNPieceMovementFSM;
struct FYNPathResult;
struct FYNTeamNode;

class FYNPieceModel
{
public:
	FYNPieceModel();
	FYNPieceModel(const int32 id);
	~FYNPieceModel();

public:
	void Initialize();
	void Move(const FYNPathResult &pathResult);
	int32 GetCurrentNodeId() const;
	FYNPieceContext& GetPieceContext();
	void UpdatePieceView();
	void SetNodeId(const int32 nodeId);
	void ChangeState(E_YNPieceState newState);

private:
	int32 Id;
	FYNPieceContext PieceContext;
	TSharedPtr<FYNPieceMovementFSM> PieceMovementFSM;
};
