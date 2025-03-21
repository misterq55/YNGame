#pragma once
#include "YNNodeModel.h"

class FYNPieceModel;
struct FYNPathResult;
struct FYNPieceContext;

class FYNTeamManager
{
public:
	FYNTeamManager();
	~FYNTeamManager();

public:
	void Move(const FYNPathResult &path);
	void AddPiece(const int32 teamIndex);
	int32 FindStartNodeId() const;
	FYNPieceContext& GetPieceContext(const int32 pieceIndex) const;

private:
	TSharedPtr<FYNPieceModel> findCurrentPiece(const int32 teamIndex) const;
};
