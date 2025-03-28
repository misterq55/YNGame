#include "YNNodeModel.h"

FYNNodeModel::FYNNodeModel()
	: Id(0)
{
}

FYNNodeModel::FYNNodeModel(const int32 id)
	: Id(id)
{
}

FYNNodeModel::~FYNNodeModel()
{
}

void FYNNodeModel::SetPos(const FVector& newPos)
{
	NodeContext.Pos = newPos;
}

FYNNodeContext& FYNNodeModel::GetNodeContext()
{
	return NodeContext;
}

void FYNNodeModel::UpdateNodeView()
{
}

int32 FYNNodeModel::GetId() const
{
	return Id;
}
