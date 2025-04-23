#include "YNBoardManager.h"

#include "YNNodeModel.h"
#include "YNGame/YNGameDefine.h"

FYNBoardManager::FYNBoardManager()
{
}

FYNBoardManager::~FYNBoardManager()
{
}

int32 FYNBoardManager::AddNode(const FVector& newPos)
{
	TSharedPtr<FYNNodeModel> newNodeModel = MakeShared<FYNNodeModel>();
	newNodeModel->SetPos(newPos);

	int32 currentIndex = IndexCounter;
	NodeModels.Emplace(IndexCounter++, newNodeModel);

	return currentIndex;
}

FYNPathResult FYNBoardManager::FindPath(const int32 startNodeId, const int32 steps)
{
	FYNPathResult pathResult;

	int32 prevNodeId = -1;
	int32 currentNodeId = startNodeId;

	// TODO 빽도
	if (steps == -1)
	{
		return MoveTemp(pathResult);
	}
	
	for (int32 i = 0; i < steps; ++i)
	{
		const TSharedPtr<FYNNodeModel>* foundNodeModel = NodeModels.Find(currentNodeId);
	
		if (foundNodeModel == nullptr || !foundNodeModel->IsValid())
		{
			ensureMsgf(false, TEXT("Invalid node ID: %d"), currentNodeId);
			break;
		}

		const TSharedPtr<FYNNodeModel>& currentNodeModel = *foundNodeModel;

		pathResult.Path.Emplace(currentNodeId);

		if (currentNodeModel->GetNodeType() == E_YNNodeType::Goal)
		{
			pathResult.bIsBlocked = true;
			break;
		}
		
		const int32 nextNodeId = currentNodeModel->FindNextNodeId(prevNodeId);
		if (nextNodeId == -1)
		{
			ensureMsgf(false, TEXT("Invalid Next node ID: %d"), currentNodeId);
			break;
		}
		
		prevNodeId = currentNodeId;
		currentNodeId = nextNodeId;
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

TSharedPtr<FYNNodeModel> FYNBoardManager::FindNode(const int32 nodeId)
{
	if (const TSharedPtr<FYNNodeModel>* foundNodeModel = NodeModels.Find(nodeId))
	{
		return (*foundNodeModel);
	}

	return nullptr;
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
