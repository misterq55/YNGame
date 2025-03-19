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
	NodeModels.Emplace(Index++, newNodeModel);
}

FYNPathResult FYNBoardManager::FindPath(const int32 startNodeId, const int32 steps)
{
	// TODO
	return FYNPathResult();
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
