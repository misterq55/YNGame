#include "YNTurn.h"

#include "Component/YNTurnStateFSM.h"
#include "YNGame/YNGameDefine.h"

FYNTurn::FYNTurn()
	:StepState(E_YNStepState::None)
{
}

FYNTurn::~FYNTurn()
{
}

void FYNTurn::Initialize()
{
	StepState = E_YNStepState::None;
	TurnStateFSM = MakeShared<FYNTurnStateFSM>();
}

void FYNTurn::ChangeTurn()
{
	TeamOrderIndex++;
	TeamOrderIndex %= MaxTeamCount;

	if (TeamOrders.IsValidIndex(TeamOrderIndex))
	{
		TurnOwnerTeamId = TeamOrders[TeamOrderIndex];
	}
}

void FYNTurn::ChangePiece()
{
	if (TurnOwnerPieceIds.IsValidIndex(TurnOwnerTeamId))
	{
		TurnOwnerPieceIds[TurnOwnerTeamId]++;
		TurnOwnerPieceIds[TurnOwnerTeamId] %= MaxPieceCount;
	}
}

void FYNTurn::SetMaxTeamCount(const int teamCount)
{
	MaxTeamCount = teamCount;
	TurnOwnerPieceIds.Reserve(MaxTeamCount);
}

void FYNTurn::SetMaxPieceCount(const int pieceCount)
{
	MaxPieceCount = pieceCount;
}

void FYNTurn::ChangeStepState(const E_YNStepState& newState)
{
	StepState = newState;
}

void FYNTurn::AdvanceStep()
{
	int32 stepValue = static_cast<int32>(StepState);
	stepValue++;
	stepValue %= static_cast<int32>(E_YNStepState::_Max);

	StepState = static_cast<E_YNStepState>(stepValue);
}

int32 FYNTurn::GetTurnOwnerTeamId() const
{
	return TurnOwnerTeamId;
}

int32 FYNTurn::GetTurnOwnerPieceId() const
{
	if (!TurnOwnerPieceIds.IsValidIndex(TurnOwnerTeamId))
	{
		return -1;
	}
	
	return TurnOwnerPieceIds[TurnOwnerTeamId];
}

E_YNStepState FYNTurn::GetStepState() const
{
	return StepState;
}

void FYNTurn::SetTeamOrder(const TArray<int>& teamOrders)
{
	TeamOrders = teamOrders;
}
