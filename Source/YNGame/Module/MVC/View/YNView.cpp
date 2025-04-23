#include "YNView.h"

#include "Node/YNNodeView.h"
#include "Piece/YNPieceView.h"

FYNView::FYNView()
{
}

FYNView::~FYNView()
{
}

void FYNView::Initialize()
{
}

void FYNView::CreateNodeView(const int32 nodeId, const FYNNodeContext& nodeContext)
{
	TSharedPtr<FYNNodeView> nodeView = MakeShared<FYNNodeView>(nodeContext);
	NodeViews.Emplace(nodeId, nodeView);
}

void FYNView::CreatePieceView(const int32 teamId, const int32 pieceId, const FYNPieceContext& pieceContext)
{
	TMap<int32, TSharedPtr<FYNPieceView>>& teamMap = PieceViews.FindOrAdd(teamId);
	TSharedPtr<FYNPieceView> pieceView = MakeShared<FYNPieceView>();
	teamMap.Emplace(pieceId, pieceView);
}

void FYNView::UpdateNodeView(const int32 nodeId, const FYNNodeContext& nodeContext)
{
	if (const TSharedPtr<FYNNodeView>* foundNodeView = NodeViews.Find(nodeId))
	{
		(*foundNodeView)->Update(nodeContext);
	}
}

void FYNView::UpdatePieceView(const int32 teamId, const int32 pieceId, const FYNPieceContext& pieceContext)
{
	if (const TMap<int32, TSharedPtr<FYNPieceView>>* foundPieceViewMap = PieceViews.Find(teamId))
	{
		if (const TSharedPtr<FYNPieceView>* foundPieceView = foundPieceViewMap->Find(pieceId))
		{
			(*foundPieceView)->Update(pieceContext);
		}
	}
}
