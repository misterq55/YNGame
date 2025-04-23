#pragma once

class FYNPieceModel;
struct FYNPieceContext;
struct FYNPathResult;

class FYNTeamModel
{
public:
	FYNTeamModel();
	FYNTeamModel(const int32 teamIndex);
	~FYNTeamModel();

public:
	void Move(const int32 currentPieceId, const FYNPathResult& path);
	int32 AddPiece();
	int32 FindCurrentNodeId(const int32 currentPieceId) const;
	FYNPieceContext& FindPieceContext(const int32 currentPieceId);
	TSharedPtr<FYNPieceModel> FindPieceModel(const int32 currentPieceId) const;

private:
	int32 Id = 0;
	int32 PieceIndexCounter = 0;
	TMap<int32, TSharedPtr<FYNPieceModel>> PieceModels;
};
