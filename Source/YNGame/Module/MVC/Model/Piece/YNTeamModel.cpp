#include "YNTeamModel.h"

#include "YNPieceModel.h"

FYNTeamModel::FYNTeamModel()
{
}

FYNTeamModel::FYNTeamModel(const int32 teamIndex)
	:Id(teamIndex)
{
}

FYNTeamModel::~FYNTeamModel()
{
}

void FYNTeamModel::Move(const int32 currentPieceId, const FYNPathResult& path)
{
	const TSharedPtr<FYNPieceModel> foundPieceModel = FindPieceModel(currentPieceId);

	if (foundPieceModel.IsValid())
	{
		foundPieceModel->Move(path);
	}
}

void FYNTeamModel::AddPiece()
{
	TSharedPtr<FYNPieceModel> pieceModel = MakeShareable(new FYNPieceModel(Id, PieceIndexCounter));

	if (pieceModel.IsValid())
	{
		pieceModel->Initialize();
		PieceModels.Emplace(PieceIndexCounter++, pieceModel);
	}
}

int32 FYNTeamModel::FindCurrentNodeId(const int32 currentPieceId) const
{
	const TSharedPtr<FYNPieceModel> foundPieceModel = FindPieceModel(currentPieceId);

	if (foundPieceModel.IsValid())
	{
		return foundPieceModel->GetCurrentNodeId();
	}
	
	return 0;
}

FYNPieceContext& FYNTeamModel::FindPieceContext(const int32 currentPieceId)
{
	const TSharedPtr<FYNPieceModel> foundPieceModel = FindPieceModel(currentPieceId);

	if (foundPieceModel.IsValid())
	{
		return foundPieceModel->GetPieceContext();
	}

	static FYNPieceContext nullPieceContext;
	return nullPieceContext;
}

TSharedPtr<FYNPieceModel> FYNTeamModel::FindPieceModel(const int32 currentPieceId) const
{
	if (const TSharedPtr<FYNPieceModel>* foundPieceModel= PieceModels.Find(currentPieceId))
	{
		return *foundPieceModel;
	}

	return nullptr;
}
