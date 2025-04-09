#include "YNNodeModel.h"

FYNNodeModel::FYNNodeModel()
	: Id(0)
{
}

FYNNodeModel::FYNNodeModel(const int32 id)
	: Id(id)
{
}

FYNNodeModel::~FYNNodeModel()
{
}

void FYNNodeModel::SetPos(const FVector& newPos)
{
	NodeContext.Pos = newPos;
}

FVector& FYNNodeModel::GetPos()
{
	return NodeContext.Pos;
}

FYNNodeContext& FYNNodeModel::GetNodeContext()
{
	return NodeContext;
}

void FYNNodeModel::UpdateNodeView()
{
}

int32 FYNNodeModel::GetId() const
{
	return Id;
}

void FYNNodeModel::SetMovingPieceIndex(const FYNPieceIndex& newPieceIndex)
{
	CurrentMovingPieceIndex = newPieceIndex;
}

FYNPieceIndex& FYNNodeModel::GetMovingPieceIndex()
{
	return CurrentMovingPieceIndex;
}

void FYNNodeModel::SetStayingPieceIndex(const FYNPieceIndex& newPieceIndex)
{
	CurrentStayingPieceIndex = newPieceIndex;
}

FYNPieceIndex& FYNNodeModel::GetStayingPieceIndex()
{
	return CurrentStayingPieceIndex;
}

void FYNNodeModel::ClearMovingPieceIndex()
{
	CurrentMovingPieceIndex.TeamIndex = -1;
	CurrentMovingPieceIndex.PieceIndex = -1;
}

void FYNNodeModel::ClearStayingPieceIndex()
{
	CurrentStayingPieceIndex.TeamIndex = -1;
	CurrentStayingPieceIndex.PieceIndex = -1;
}

TArray<int32>& FYNNodeModel::GetNextNodeIds()
{
	return NextNodeIds;
}

int32 FYNNodeModel::FindNextNodeId(const int32 prevNodeId)
{
	if (prevNodeId == -1 && DirectionalConnections.Num() == 1)
	{
		return ShorcutNodeId != -1 ? ShorcutNodeId : DirectionalConnections[0].ToNodeId;
	}

	for (const auto& directionalConnection : DirectionalConnections)
	{
		if (directionalConnection.FromNodeId == prevNodeId)
		{
			return directionalConnection.ToNodeId;
		}
	}

	return -1;
}

void FYNNodeModel::SetNodeType(const E_YNNodeType& newNodeType)
{
	NodeType = newNodeType;
}

E_YNNodeType FYNNodeModel::GetNodeType() const
{
	return NodeType;
}
