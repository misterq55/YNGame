#pragma once
#include "YNGame/Module/Interface/IYNView.h"

class FYNNodeView;
class FYNPieceView;

class FYNView : public IYNView
{
public:
	FYNView();
	virtual ~FYNView();
	
public:
	virtual void CreateNodeView(const int32 nodeId) override;
	virtual void CreatePieceView(const int32 teamId, const int32 pieceId) override;
	virtual void UpdateNodeView(const int32 nodeId, const FYNNodeContext& nodeContext) override;
	virtual void UpdatePieceView(const int32 teamId, const int32 pieceId, const FYNPieceContext& pieceContext) override;

private:
	TMap<int32, TSharedPtr<FYNNodeView>> NodeViews;
	TMap<int32, TMap<int32, TSharedPtr<FYNPieceView>>> PieceViews;
};
