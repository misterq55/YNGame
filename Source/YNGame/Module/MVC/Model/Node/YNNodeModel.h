#pragma once

#include "YNGame/YNGameDefine.h"

class FYNNodeModel
{
public:
	FYNNodeModel();
	FYNNodeModel(const int32 id);
	virtual ~FYNNodeModel();

public:
	void SetPos(const FVector& newPos);
	FVector& GetPos();
	FYNNodeContext& GetNodeContext();
	void UpdateNodeView();
	int32 GetId() const;
	void SetPieceIndex(const FYNPieceIndex& newPieceIndex);
	void ClearPieceIndex();
	TArray<int32>& GetNextNodeIds();

private:
	int32 Id;
	FYNPieceIndex CurrentPieceIndex;
	FYNNodeContext NodeContext;
	TArray<int32> NextNodeIds;
};
