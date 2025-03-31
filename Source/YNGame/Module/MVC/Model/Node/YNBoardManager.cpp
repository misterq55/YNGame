#include "YNBoardManager.h"

#include "YNNodeModel.h"
#include "YNGame/YNGameDefine.h"

FYNBoardManager::FYNBoardManager()
{
}

FYNBoardManager::~FYNBoardManager()
{
}

void FYNBoardManager::AddNode(const FVector& newPos)
{
	TSharedPtr<FYNNodeModel> newNodeModel = MakeShareable(new FYNNodeModel());
	newNodeModel->SetPos(newPos);
	NodeModels[IndexCounter++] = newNodeModel;
}

FYNPathResult FYNBoardManager::FindPath(const int32 startNodeId, const int32 steps)
{
	// TODO 분기 처리 남음
	FYNPathResult pathResult;

	TSharedPtr<FYNNodeModel> currentNodeModel;
	
	for (int32 i = 0; i < steps; ++i)
	{
		const int32 currentNodeId = i == 0 ? startNodeId : currentNodeModel->GetId();

		pathResult.Path.Emplace(currentNodeId);
		
		TSharedPtr<FYNNodeModel>* nextNodeModel = NodeModels.Find(currentNodeModel->GetNextNodeIds()[0]);
	
		if (nextNodeModel == nullptr || !nextNodeModel->IsValid())
		{
			continue;
		}

		currentNodeModel = *nextNodeModel;
	}
	
	return MoveTemp(pathResult);
}

FYNNodeContext& FYNBoardManager::FindNodeContext(const int32 nodeId)
{
	TSharedPtr<FYNNodeModel>* foundNodeModel = NodeModels.Find(nodeId);
	if (foundNodeModel != nullptr && foundNodeModel->IsValid())
	{
		return (*foundNodeModel)->GetNodeContext();
	}

	static FYNNodeContext nullNodeContext;
	return nullNodeContext;
}

TArray<TSharedPtr<FYNNodeModel>> FYNBoardManager::FindNodes(const TArray<int32>& nodeIds)
{
	TArray<TSharedPtr<FYNNodeModel>> nodeModels;

	for (const int32 nodeId : nodeIds)
	{
		if (const TSharedPtr<FYNNodeModel>* foundNodeModel = NodeModels.Find(nodeId))
		{
			nodeModels.Emplace(*foundNodeModel);
		}
	}
	
	return MoveTemp(nodeModels);
}
