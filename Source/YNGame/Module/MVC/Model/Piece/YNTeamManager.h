#pragma once

class FYNPieceModel;
class FYNTeamModel;
class FYNTurn;
struct FYNPathResult;
struct FYNPieceContext;

class FYNTeamManager
{
public:
	FYNTeamManager();
	~FYNTeamManager();

public:
	void AddPiece(const int32 teamIndex, const int32 pieceCount)  const;
	void AddTeam(const int32 teamIndex);
	int32 FindStartNodeId(const int32 currentTurnTeamId, const int32 currentTurnPieceId) const;
	FYNPieceContext& GetPieceContext(const int32 teamId, const int32 pieceIndex) const;
	TSharedPtr<FYNPieceModel> FindPieceModel(const int32 teamId, const int32 pieceId) const;
	TSharedPtr<FYNTeamModel> FindTeamModel(const int32 teamId) const;
	bool CheckCurrentPieceNested(const int32 teamId, const int32 pieceId) const;
	
private:
	int IndexCounter = 0;
	TMap<int32, TSharedPtr<FYNTeamModel>> TeamModels;
};
