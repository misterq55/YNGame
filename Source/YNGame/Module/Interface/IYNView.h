#pragma once

struct FYNNodeContext;
struct FYNPieceContext;

class IYNView
{
public:
    virtual void CreateNodeView(const int32 nodeId) = 0;
    virtual void CreatePieceView(const int32 teamId, const int32 pieceId) = 0;
    virtual void UpdateNodeView(const int32 nodeId, const FYNNodeContext& nodeContext) = 0;
    virtual void UpdatePieceView(const int32 teamId, const int32 pieceId, const FYNPieceContext& pieceContext) = 0;
};