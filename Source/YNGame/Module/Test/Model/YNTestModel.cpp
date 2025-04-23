#include "YNTestModel.h"
#include "YNGame/Module/MVC/Model/Node/YNBoardManager.h"
#include "YNGame/Module/MVC/Model/Node/YNNodeModel.h"

FYNTestModel::FYNTestModel()
{
}

FYNTestModel::~FYNTestModel()
{
}

bool FYNTestModel::LoadBoard()
{
	if (!BoardMgr.IsValid())
	{
		return false;
	}

	// 테스트 데이터
	const float dist = 15.f;
	TArray<FVector> dirs ={ FVector(1, 0, 0), FVector(0, 1, 0), FVector(-1, -1, 0)};
	FVector lastPos = FVector::ZeroVector;
	TSharedPtr<FYNNodeModel> lastNodeModel = nullptr;

	for (int32 i = 0; i < 3; i++)
	{
		const FVector dir = dirs[i];
		for (int32 j = 0; j < 5; j++)
		{
			const FVector newPos = dir * dist + lastPos;
			const int32 currentIndex = BoardMgr->AddNode(newPos);
			const FYNNodeContext& currentNodeContext = BoardMgr->FindNodeContext(currentIndex);
			TSharedPtr<FYNNodeModel> currentNode = BoardMgr->FindNode(currentIndex);
			if (lastNodeModel.IsValid() && currentNode.IsValid())
			{
				// lastNodeModel->NextNodeIds.Add(currentIndex);
			}
			
			lastPos = newPos;

			OnNodeModelCreateEvent.ExecuteIfBound(currentIndex, currentNodeContext);

			lastNodeModel = currentNode;
		}
	}
	
	return true;
}
