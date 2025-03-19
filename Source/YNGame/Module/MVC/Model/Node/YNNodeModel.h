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
	FYNNodeContext& GetNodeContext();

private:
	int32 Id;
	FYNNodeContext NodeContext;
	TArray<int32> NextNodeIds;
};
