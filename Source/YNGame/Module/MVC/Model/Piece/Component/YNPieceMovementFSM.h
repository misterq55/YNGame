#pragma once

class FYNPieceModel;

class FYNPieceMovementFSM
{
public:
	FYNPieceMovementFSM();
	~FYNPieceMovementFSM();

public:
	void SetOwnerPiece(const TSharedPtr<FYNPieceModel>& ownerPieceModel);
	void Move(TArray<int32> path);

private:
	TWeakPtr<FYNPieceModel> OwnerPieceModel;
};
