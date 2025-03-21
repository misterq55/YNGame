#include "YNTeamModel.h"

#include "YNPieceModel.h"

FYNTeamModel::FYNTeamModel()
{
}

FYNTeamModel::~FYNTeamModel()
{
}

void FYNTeamModel::Move(const int32 currentPieceId, const FYNPathResult& path)
{
	if (const TSharedPtr<FYNPieceModel>* foundPieceModel= PieceModels.Find(currentPieceId))
	{
		return (*foundPieceModel)->Move(path);
	}
}

void FYNTeamModel::AddPiece()
{
	TSharedPtr<FYNPieceModel> pieceModel;
	pieceModel->Initialize();
	PieceModels.Emplace(IndexCounter++, pieceModel);
}

int32 FYNTeamModel::FindCurrentNodeId(const int32 currentPieceId) const
{
	if (const TSharedPtr<FYNPieceModel>* foundPieceModel= PieceModels.Find(currentPieceId))
	{
		return (*foundPieceModel)->GetCurrentNodeId();
	}
	
	return 0;
}

FYNPieceContext& FYNTeamModel::FindPieceContext(const int32 currentPieceId)
{
	if (const TSharedPtr<FYNPieceModel>* foundPieceModel= PieceModels.Find(currentPieceId))
	{
		return (*foundPieceModel)->GetPieceContext();
	}

	static FYNPieceContext nullPieceContext;
	return nullPieceContext;
}
