#include "YNPieceModel.h"

#include "Component/YNPieceMovementFSM.h"

FYNPieceModel::FYNPieceModel()
{
}

FYNPieceModel::FYNPieceModel(const int32 teamId, const int32 id)
{
	PieceContext.Id.TeamIndex = teamId;
	PieceContext.Id.PieceIndex = id;
}

FYNPieceModel::~FYNPieceModel()
{
}

void FYNPieceModel::Initialize()
{
	PieceMovementFSM = MakeShareable<FYNPieceMovementFSM>(new FYNPieceMovementFSM());
}

void FYNPieceModel::Move(const FYNPathResult& pathResult)
{
}

int32 FYNPieceModel::GetCurrentNodeId() const
{
	return PieceContext.CurrentNodeId;
}

FYNPieceContext& FYNPieceModel::GetPieceContext()
{
	return PieceContext;
}

void FYNPieceModel::UpdatePieceView()
{
}

void FYNPieceModel::SetNodeId(const int32 nodeId)
{
	PieceContext.CurrentNodeId = nodeId;
}

void FYNPieceModel::ChangeState(const E_YNPieceState newState)
{
	if (PieceContext.PieceState == newState)
	{
		return;
	}
	
	PieceContext.PieceState = newState;
}

void FYNPieceModel::SetPos(const FVector& newPos)
{
	PieceContext.Pos = newPos;
}

FVector& FYNPieceModel::GetPos()
{
	return PieceContext.Pos;
}

void FYNPieceModel::SetLookAt(const FVector& newLookAt)
{
	PieceContext.LookAt = newLookAt;
}

FVector& FYNPieceModel::GetLookAt()
{
	return PieceContext.LookAt;
}

FYNPieceIndex& FYNPieceModel::GetPieceIndex()
{
	return PieceContext.Id;
}
