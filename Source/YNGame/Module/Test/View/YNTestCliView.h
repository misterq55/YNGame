#pragma once
#include "YNGame/Module/Interface/IYNView.h"

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
};
