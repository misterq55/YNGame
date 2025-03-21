#include "YNPieceMovementFSM.h"

FYNPieceMovementFSM::FYNPieceMovementFSM()
{
}

FYNPieceMovementFSM::~FYNPieceMovementFSM()
{
}

void FYNPieceMovementFSM::SetOwnerPiece(const TSharedPtr<FYNPieceModel>& ownerPieceModel)
{
	OwnerPieceModel = ownerPieceModel;
}

void FYNPieceMovementFSM::Move(TArray<int32> path)
{
}
