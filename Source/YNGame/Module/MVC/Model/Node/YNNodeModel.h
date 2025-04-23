#pragma once

#include "YNGame/YNGameDefine.h"

class FYNNodeModel
{
public:
	FYNNodeModel();
	FYNNodeModel(const int32 id);
	virtual ~FYNNodeModel();

public:
	void SetPos(const FVector& newPos);
	FVector& GetPos();
	FYNNodeContext& GetNodeContext();
	void UpdateNodeView();
	int32 GetId() const;
	void SetMovingPieceIndex(const FYNPieceIndex& newPieceIndex);
	FYNPieceIndex& GetMovingPieceIndex();
	void SetStayingPieceIndex(const FYNPieceIndex& newPieceIndex);
	FYNPieceIndex& GetStayingPieceIndex();
	void ClearMovingPieceIndex();
	void ClearStayingPieceIndex();
	TArray<int32>& GetNextNodeIds();
	int32 FindNextNodeId(const int32 prevNodeId);
	void SetNodeType(const E_YNNodeType& newNodeType);
	E_YNNodeType GetNodeType() const;
	// void ConnectNode();

private:
	int32 Id;
	FYNPieceIndex CurrentMovingPieceIndex;
	FYNPieceIndex CurrentStayingPieceIndex;
	FYNNodeContext NodeContext;
	TArray<int32> NextNodeIds;
	TArray<FYNDirectionalConnection> DirectionalConnections;
	int32 ShorcutNodeId = -1;
	E_YNNodeType NodeType = E_YNNodeType::None;
};
