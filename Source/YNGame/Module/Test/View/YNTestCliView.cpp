#include "YNTestCliView.h"

#include "Node/YNNodeTestCliView.h"
#include "Piece/YNPieceTestCliView.h"

FYNTestCliView::FYNTestCliView()
{
}

FYNTestCliView::~FYNTestCliView()
{
}

void FYNTestCliView::Initialize()
{
}

void FYNTestCliView::CreateNodeView(const int32 nodeId, const FYNNodeContext& nodeContext)
{
	TSharedPtr<FYNNodeTestCliView> nodeView = MakeShared<FYNNodeTestCliView>(nodeContext);
	NodeViews.Emplace(nodeId, nodeView);
}

void FYNTestCliView::CreatePieceView(const int32 teamId, const int32 pieceId, const FYNPieceContext& pieceContext)
{
	TMap<int32, TSharedPtr<FYNPieceTestCliView>>& teamMap = PieceViews.FindOrAdd(teamId);
	TSharedPtr<FYNPieceTestCliView> pieceView = MakeShared<FYNPieceTestCliView>(pieceContext);
	teamMap.Emplace(pieceId, pieceView);
}

void FYNTestCliView::UpdateNodeView(const int32 nodeId, const FYNNodeContext& nodeContext)
{
	if (const TSharedPtr<FYNNodeTestCliView>* foundNodeView = NodeViews.Find(nodeId))
	{
		(*foundNodeView)->Update(nodeContext);
	}
}

void FYNTestCliView::UpdatePieceView(const int32 teamId, const int32 pieceId, const FYNPieceContext& pieceContext)
{
	if (const TMap<int32, TSharedPtr<FYNPieceTestCliView>>* foundPieceViewMap = PieceViews.Find(teamId))
	{
		if (const TSharedPtr<FYNPieceTestCliView>* foundPieceView = foundPieceViewMap->Find(pieceId))
		{
			(*foundPieceView)->Update(pieceContext);
		}
	}
}
