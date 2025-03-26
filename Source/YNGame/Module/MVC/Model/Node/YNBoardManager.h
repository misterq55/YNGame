#pragma once

class FYNNodeModel;
struct FYNPathResult;
struct FYNNodeContext;

class FYNBoardManager
{
public:
	FYNBoardManager();
	virtual ~FYNBoardManager();

public:
	void AddNode(const FVector& newPos);
	FYNPathResult FindPath(const int32 startNodeId, const int32 steps);
	FYNNodeContext& FindNodeContext(const int32 nodeId);
	TArray<TSharedPtr<FYNNodeModel>> FindNodes(const TArray<int32>& nodeIds);
	
private:
	TMap<int32, TSharedPtr<FYNNodeModel>> NodeModels;
	int IndexCounter = 0;
};
