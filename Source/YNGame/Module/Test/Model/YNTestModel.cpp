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

	TArray<TSharedPtr<FYNNodeModel>> nodes;
	
	for (int32 i = 0; i < 3; i++)
	{
		const FVector dir = dirs[i];
		for (int32 j = 0; j < 5; j++)
		{
			const FVector newPos = dir * dist + lastPos;
			const int32 currentIndex = BoardMgr->AddNode(newPos);
			const FYNNodeContext& currentNodeContext = BoardMgr->FindNodeContext(currentIndex);
			TSharedPtr<FYNNodeModel> currentNode = BoardMgr->FindNode(currentIndex);
			if (currentNode.IsValid())
			{
				lastNodeModel = currentNode;
				nodes.Add(currentNode);
			}
			
			lastPos = newPos;

			OnNodeModelCreateEvent.ExecuteIfBound(currentIndex, currentNodeContext);
		}
	}

	lastNodeModel->SetNodeType(E_YNNodeType::Goal);

	const int nodeNum = nodes.Num();
	for (int32 i = 0; i < nodeNum; ++i)
	{
		TSharedPtr<FYNNodeModel> currentNode = nodes[i];
		if (!currentNode.IsValid())
		{
			continue;
		}

		TSharedPtr<FYNNodeModel> prevNode = i - 1 < 0 ?  nodes[nodeNum - 1] : nodes[i - 1];
		if (!prevNode.IsValid())
		{
			continue;
		}

		TSharedPtr<FYNNodeModel> nextNode = i + 1 >= nodeNum ? nodes[0] : nodes[i + 1];
		if (!nextNode.IsValid())
		{
			continue;
		}

		currentNode->ConnectNode(prevNode->GetId(), nextNode->GetId());
	}
	
	return true;
}
