#include "YNTurn.h"

#include "Component/YNTurnStateFSM.h"
#include "YNGame/YNGameDefine.h"

FYNTurn::FYNTurn()
	:StepState(E_KStepState::None)
{
}

FYNTurn::~FYNTurn()
{
}

void FYNTurn::Initialize()
{
	StepState = E_KStepState::None;
	TurnStateFSM = MakeShareable(new FYNTurnStateFSM());
}

void FYNTurn::ChangeTurn()
{
	TurnOwnerTeamId++;
	TurnOwnerTeamId %= MaxTeamCount;
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

void FYNTurn::ChangeStepState(const E_KStepState& newState)
{
	StepState = newState;
}

void FYNTurn::AdvanceStep()
{
	int32 stepValue = static_cast<int32>(StepState);
	stepValue++;
	stepValue %= static_cast<int32>(E_KStepState::_Max);

	StepState = static_cast<E_KStepState>(stepValue);
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

E_KStepState FYNTurn::GetStepState() const
{
	return StepState;
}
