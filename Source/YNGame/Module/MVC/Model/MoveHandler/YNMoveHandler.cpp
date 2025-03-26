#include "YNMoveHandler.h"
#include "YNGame/Module/MVC/Model/Piece/YNPieceModel.h"
#include "YNGame/Module/MVC/Model/Node/YNNodeModel.h"

void FYNMoveHandler::MovePiece(FYNMoveContext moveContext)
{
	TSharedPtr<FYNPieceModel> piece = moveContext.PieceModel;
	TArray<TSharedPtr<FYNNodeModel>> nodes = moveContext.NodeModels;

	for (TSharedPtr<FYNNodeModel> node : nodes)
	{
		if (!node.IsValid())
		{
			continue;
		}
	}
}
