#include "YNTeamManager.h"

#include "YNTeamModel.h"
#include "YNGame/YNGameDefine.h"

FYNTeamManager::FYNTeamManager()
{
}

FYNTeamManager::~FYNTeamManager()
{
}

void FYNTeamManager::Move(const int32 currentTurnTeamId, const int32 currentTurnPieceId, const FYNPathResult& path)
{
	if (const TSharedPtr<FYNTeamModel>* foundTeamModel = TeamModels.Find(currentTurnTeamId))
	{
		return (*foundTeamModel)->Move(currentTurnPieceId, path);
	}
}

void FYNTeamManager::AddPiece(const int32 teamIndex, const int32 pieceCount)
{
	if (const TSharedPtr<FYNTeamModel>* foundTeamModel = TeamModels.Find(teamIndex))
	{
		for (int32 i = 0; i < pieceCount; ++i)
		{
			(*foundTeamModel)->AddPiece();
		}
	}
}

void FYNTeamManager::AddTeam(const int32 teamIndex)
{
	TSharedPtr<FYNTeamModel> TeamModel = MakeShared<FYNTeamModel>();
	TeamModels.Emplace(teamIndex, TeamModel);
}

int32 FYNTeamManager::FindStartNodeId(const int32 currentTurnTeamId, const int32 currentTurnPieceId) const
{
	if (const TSharedPtr<FYNTeamModel>* foundTeamModel = TeamModels.Find(currentTurnTeamId))
	{
		return (*foundTeamModel)->FindCurrentNodeId(currentTurnPieceId);
	}
	
	return 0;
}

FYNPieceContext& FYNTeamManager::GetPieceContext(const int32 teamId, const int32 pieceIndex) const
{
	if (const TSharedPtr<FYNTeamModel>* foundTeamModel = TeamModels.Find(teamId))
	{
		return (*foundTeamModel)->FindPieceContext(pieceIndex);
	}
	
	static FYNPieceContext nullPieceContext;
	return nullPieceContext;
}
