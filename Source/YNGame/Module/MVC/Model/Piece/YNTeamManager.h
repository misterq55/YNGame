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
	void Move(const int32 currentTurnTeamId, const int32 currentTurnPieceId, const FYNPathResult &path);
	void AddPiece(const int32 teamIndex, const int32 pieceCount);
	void AddTeam(const int32 teamIndex);
	int32 FindStartNodeId(const int32 currentTurnTeamId, const int32 currentTurnPieceId) const;
	FYNPieceContext& GetPieceContext(const int32 teamId, const int32 pieceIndex) const;

private:
	int IndexCounter = 0;
	TMap<int32, TSharedPtr<FYNTeamModel>> TeamModels;
};
