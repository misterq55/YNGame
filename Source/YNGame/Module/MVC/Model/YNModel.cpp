#include "YNModel.h"

#include "MoveHandler/YNMoveHandler.h"
#include "YNGame/YNGameDefine.h"
#include "Node/YNBoardManager.h"
#include "Piece/YNTeamManager.h"
#include "Turn/YNTurn.h"

FYNModel::FYNModel()
{
}

FYNModel::~FYNModel()
{
}

void FYNModel::Initialize()
{
	BoardMgr = MakeShareable(new FYNBoardManager());
	TeamMgr = MakeShareable(new FYNTeamManager());
	CurrentTurn = MakeShareable(new FYNTurn());
	MoveHandler = MakeShareable(new FYNMoveHandler());
}

void FYNModel::StartPlay()
{
	// TODO 초기화
}

void FYNModel::AddNode(const FVector& newPos)
{
	if (BoardMgr.IsValid())
	{
		BoardMgr->AddNode(newPos);
	}
}

void FYNModel::AddTeams(const int32 teamCount, const int32 pieceCount)
{
	if (TeamMgr.IsValid())
	{
		for (int32 i = 0; i < teamCount; ++i)
		{
			TeamMgr->AddTeam(i);
			TeamMgr->AddPiece(i, pieceCount);
		}
	}
}

void FYNModel::AddTeam()
{
	
}

void FYNModel::AdvanceStep()
{
	// TODO 턴 관련 처리
}

void FYNModel::ChangeTurn()
{
	// TODO 턴 관련 처리
}

void FYNModel::Move(const int32 steps)
{
	if (!TeamMgr.IsValid())
	{
		return;
	}
	
	if (!BoardMgr.IsValid())
	{
		return;
	}

	if (!CurrentTurn.IsValid())
	{
		return;
	}

	if (!MoveHandler.IsValid())
	{
		return;
	}

	const int32 currentTurnTeamId = CurrentTurn->GetTurnOwnerTeamId();
	const int32 currentPieceId = CurrentTurn->GetTurnOwnerPieceId();
	const int32 startNodeId = TeamMgr->FindStartNodeId(currentTurnTeamId, currentPieceId);
	const FYNPathResult pathResult = BoardMgr->FindPath(startNodeId, steps);

	// 골에 딱 맞게 들어오지 않음
	if (pathResult.bIsBlocked)
	{
		// TODO 골에 딱 맞게 안들어왔을 때 처리
		return;
	}

	const TArray<TSharedPtr<FYNNodeModel>>& nodeModels = BoardMgr->FindNodes(pathResult.Path);
	const TSharedPtr<FYNPieceModel>& pieceModel = TeamMgr->FindPieceModel(currentTurnTeamId, currentPieceId);

	FYNMoveContext moveContext;
	moveContext.PieceModel = pieceModel;
	moveContext.NodeModels = nodeModels;

	MoveHandler->StartMove(MoveTemp(moveContext));
}

bool FYNModel::IsRepeat()
{
	return false;
}

void FYNModel::Update(float deltaTimes)
{
	if (!MoveHandler.IsValid())
	{
		return;
	}

	MoveHandler->Update(deltaTimes);
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

FYNPieceContext& FYNModel::FindPieceContext(const int32 teamId, const int32 pieceId)
{
	if (!TeamMgr.IsValid())
	{
		static FYNPieceContext nullPieceContext;
		return nullPieceContext;
	}

	return TeamMgr->GetPieceContext(teamId, pieceId);
}
