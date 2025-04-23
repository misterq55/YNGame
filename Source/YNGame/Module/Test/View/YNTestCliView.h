#pragma once
#include "YNGame/Module/Interface/IYNView.h"

class FYNNodeTestCliView;
class FYNPieceTestCliView;

class FYNTestCliView : public IYNView
{
public:
	FYNTestCliView();
	virtual ~FYNTestCliView();
	
public:
	virtual void Initialize() override;
	virtual void CreateNodeView(const int32 nodeId, const FYNNodeContext& nodeContext) override;
	virtual void CreatePieceView(const int32 teamId, const int32 pieceId, const FYNPieceContext& pieceContext) override;
	virtual void UpdateNodeView(const int32 nodeId, const FYNNodeContext& nodeContext) override;
	virtual void UpdatePieceView(const int32 teamId, const int32 pieceId, const FYNPieceContext& pieceContext) override;

private:
	TMap<int32, TSharedPtr<FYNNodeTestCliView>> NodeViews;
	TMap<int32, TMap<int32, TSharedPtr<FYNPieceTestCliView>>> PieceViews;
};
