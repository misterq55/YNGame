#include "YNTeamManager.h"

FYNTeamManager::FYNTeamManager()
{
}

FYNTeamManager::~FYNTeamManager()
{
}

void FYNTeamManager::Move(const FYNPathResult& path)
{
}

void FYNTeamManager::AddPiece(const int32 teamIndex)
{
}

int32 FYNTeamManager::FindStartNodeId() const
{
	// TODO
	return 0;
}

FYNPieceContext& FYNTeamManager::GetPieceContext(const int32 pieceIndex) const
{
	static FYNPieceContext nullPieceContext;
	return nullPieceContext;
}

TSharedPtr<FYNPieceModel> FYNTeamManager::findCurrentPiece(const int32 teamIndex) const
{
	// TODO
	return TSharedPtr<FYNPieceModel>();
}
