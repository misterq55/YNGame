#include "YNTeamManager.h"

#include "YNTeamModel.h"
#include "YNGame/YNGameDefine.h"

FYNTeamManager::FYNTeamManager()
{
}

FYNTeamManager::~FYNTeamManager()
{
}

void FYNTeamManager::AddPiece(const int32 teamIndex, const int32 pieceCount) const
{
	const TSharedPtr<FYNTeamModel> teamModel = FindTeamModel(teamIndex);
	if (!teamModel.IsValid())
	{
		return;
	}
	
	for (int32 i = 0; i < pieceCount; ++i)
	{
		teamModel->AddPiece();
	}
}

void FYNTeamManager::AddTeam(const int32 teamIndex)
{
	TSharedPtr<FYNTeamModel> TeamModel = MakeShareable(new FYNTeamModel(teamIndex));
	TeamModels.Emplace(teamIndex, TeamModel);
}

int32 FYNTeamManager::FindStartNodeId(const int32 currentTurnTeamId, const int32 currentTurnPieceId) const
{
	const TSharedPtr<FYNTeamModel> teamModel = FindTeamModel(currentTurnTeamId);
	if (teamModel.IsValid())
	{
		return teamModel->FindCurrentNodeId(currentTurnPieceId);
	}
	
	return 0;
}

FYNPieceContext& FYNTeamManager::GetPieceContext(const int32 teamId, const int32 pieceIndex) const
{
	const TSharedPtr<FYNTeamModel> teamModel = FindTeamModel(teamId);
	if (teamModel.IsValid())
	{
		return teamModel->FindPieceContext(pieceIndex);
	}
	
	static FYNPieceContext nullPieceContext;
	return nullPieceContext;
}

TSharedPtr<FYNPieceModel> FYNTeamManager::FindPieceModel(const int32 teamId, const int32 pieceId) const
{
	const TSharedPtr<FYNTeamModel> teamModel = FindTeamModel(teamId);
	if (teamModel.IsValid())
	{
		return teamModel->FindPieceModel(pieceId);
	}

	return nullptr;
}

TSharedPtr<FYNTeamModel> FYNTeamManager::FindTeamModel(const int32 teamId) const
{
	if (const TSharedPtr<FYNTeamModel>* foundTeamModel = TeamModels.Find(teamId))
	{
		return *foundTeamModel;
	}
	
	return nullptr;
}
