#include "YNPieceModel.h"

#include "Component/YNPieceMovementFSM.h"

FYNPieceModel::FYNPieceModel()
	: Id(0)
{
}

FYNPieceModel::FYNPieceModel(const int32 id)
	: Id(id)
{
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

void FYNPieceModel::ChangeState(E_YNPieceState newState)
{
	PieceContext.PieceState = newState;
}
