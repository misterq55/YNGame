#include "YNModel.h"

#include "MoveHandler/YNMoveHandler.h"
#include "YNGame/YNGameDefine.h"
#include "Node/YNBoardManager.h"
#include "Node/YNNodeModel.h"
#include "Piece/YNPieceModel.h"
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

	if (TeamMgr.IsValid())
	{
		// TODO 팀 최대 말 수 입력할 수 있도록
	}
	
	if (CurrentTurn.IsValid())
	{
		CurrentTurn->Initialize();
	}

	if (MoveHandler.IsValid())
	{
		auto& moveEndEvent = MoveHandler->GetMoveEndEvent();
		moveEndEvent.BindRaw(this, &FYNModel::OnMoveEnd);
	}
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
	if (!CurrentTurn.IsValid())
	{
		return;
	}

	CurrentTurn->AdvanceStep();
}

void FYNModel::ChangeTurn()
{
	// TODO 턴 관련 처리
	if (!CurrentTurn.IsValid())
	{
		return;
	}

	if (!TeamMgr.IsValid())
	{
		return;
	}

	CurrentTurn->ChangeTurn();
	CurrentTurn->ChangePiece();
	
	const int32 currentTurnTeamId = CurrentTurn->GetTurnOwnerTeamId();
	int32 currentPieceId = CurrentTurn->GetTurnOwnerPieceId();

	// 루프로 현재 사용 가능한 말을 찾는다
	while (TeamMgr->CheckCurrentPieceMovable(currentTurnTeamId, currentPieceId))
	{
		CurrentTurn->ChangePiece();
		currentPieceId = CurrentTurn->GetTurnOwnerPieceId();
	}
}

E_KStepState FYNModel::GetCurrentStepState()
{
	if (!CurrentTurn.IsValid())
	{
		return E_KStepState::None;
	}

	return CurrentTurn->GetStepState();
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
		// 턴을 넘긴다
		ChangeTurn();
		return;
	}

	const TArray<TSharedPtr<FYNNodeModel>>& nodeModels = BoardMgr->FindNodes(pathResult.Path);
	const TSharedPtr<FYNPieceModel>& pieceModel = TeamMgr->FindPieceModel(currentTurnTeamId, currentPieceId);

	FYNMoveContext moveContext;
	moveContext.PieceModel = pieceModel;
	moveContext.NodeModels = nodeModels;

	MoveHandler->StartMove(MoveTemp(moveContext));
}

void FYNModel::OnMoveEnd(const int32 nodeId, const FYNPieceIndex& pieceIndex)
{
	if (!BoardMgr.IsValid())
	{
		return;
	}

	if (!TeamMgr.IsValid())
	{
		return;
	}

	// TODO
	// 게임 룰 담당 클래스 만들어서 추출? 예정
	TArray<TSharedPtr<FYNNodeModel>> nodeModels = BoardMgr->FindNodes({nodeId});

	if (nodeModels.IsEmpty())
	{
		return;
	}
	
	TSharedPtr<FYNNodeModel> nodeModel = nodeModels[0];

	if (!nodeModel.IsValid())
	{
		return;
	}

	const FYNPieceIndex& currentStayingIndex = nodeModel->GetStayingPieceIndex();

	TSharedPtr<FYNPieceModel> curreutStayingPiece = TeamMgr->FindPieceModel(currentStayingIndex.TeamIndex, currentStayingIndex.PieceIndex);

	// 현재 해당 노드에 머무르고 있는 말이 있다
	if (currentStayingIndex.TeamIndex != -1)
	{
		if (currentStayingIndex.TeamIndex == pieceIndex.TeamIndex)
		{
			// 같은 편 말 업기
			curreutStayingPiece->ChangeState(E_YNPieceState::Nested);
		}
		else
		{
			// 상대편 말 잡기
			curreutStayingPiece->ChangeState(E_YNPieceState::Unspawned);

			// TODO
			// 내 턴 한번 더
		}	
	}

	nodeModel->SetStayingPieceIndex(pieceIndex);

	// 골 처리
	if (nodeModel->GetNodeType() == E_YNNodeType::Goal)
	{
		// 말 들어온 팀 득점
		TSharedPtr<FYNPieceModel> curreutMovingPiece = TeamMgr->FindPieceModel(pieceIndex.TeamIndex, pieceIndex.PieceIndex);
		if (curreutMovingPiece.IsValid())
		{
			curreutMovingPiece->ChangeState(E_YNPieceState::Goal);

			// TODO
			// 득점 처리
		}
	}
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

	if (MoveHandler->Update(deltaTimes))
	{
		if (CurrentTurn.IsValid())
		{
			const int32 currentTurnTeamId = CurrentTurn->GetTurnOwnerTeamId();
			const int32 currentPieceId = CurrentTurn->GetTurnOwnerPieceId();
			const FYNPieceContext& pieceContext = FindPieceContext(currentTurnTeamId, currentPieceId);
			OnPieceModelUpdateEvent.ExecuteIfBound(currentTurnTeamId, currentPieceId, pieceContext);
		}
	}
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

FYNPieceModelCreateEvent& FYNModel::GetOnPieceModelCreateEvent()
{
	return OnPieceModelCreateEvent;
}

FYNNodeModelCreateEvent& FYNModel::GetOnNodeModelCreateEvent()
{
	return OnNodeModelCreateEvent;
}

FYNPieceModelUpdateEvent& FYNModel::GetOnPieceModelUpdateEvent()
{
	return OnPieceModelUpdateEvent;
}

FYNNodeModelUpdateEvent& FYNModel::GetOnNodeModelUpdateEvent()
{
	return OnNodeModelUpdateEvent;
}
