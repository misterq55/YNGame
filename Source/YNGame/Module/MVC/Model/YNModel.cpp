#include "YNModel.h"
#include "YNGame/YNGameDefine.h"
#include "Node/YNBoardManager.h"

FYNModel::FYNModel()
{
}

FYNModel::~FYNModel()
{
}

void FYNModel::Initialize()
{
	BoardMgr = MakeShareable(new FYNBoardManager());
}

void FYNModel::StartPlay()
{
}

void FYNModel::AddNode(const FVector& newPos)
{
	if (BoardMgr.IsValid())
	{
		BoardMgr->AddNode(newPos);
	}
}

void FYNModel::AddTeams(const int32 teamCount)
{
}

void FYNModel::AdvanceStep()
{
}

void FYNModel::ChangeTurn()
{
}

void FYNModel::Move(const int32 steps)
{
}

bool FYNModel::IsRepeat()
{
	return false;
}

FYNNodeContext& FYNModel::FindNodeContext(const int32 nodeId)
{
	if (!BoardMgr.IsValid())
	{
		static FYNNodeContext nullNodeContext;
		return nullNodeContext;
	}
	
	return BoardMgr->FindNodeContext(nodeId);
}

static FYNPieceContext tempPieceContext;
FYNPieceContext& FYNModel::FindPieceContext(const int32 pieceId)
{
	return tempPieceContext;
}
