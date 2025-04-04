#include "YNTurn.h"

#include "Component/YNTurnStateFSM.h"
#include "YNGame/YNGameDefine.h"

FYNTurn::FYNTurn()
	:TurnState(E_KTurnState::None)
{
}

FYNTurn::~FYNTurn()
{
}

void FYNTurn::Initialize()
{
	TurnState = E_KTurnState::None;
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

void FYNTurn::ChangeState(const E_KTurnState& newState)
{
	TurnState = newState;
}

void FYNTurn::AdvanceStep()
{
	int32 turnValue = static_cast<int32>(TurnState);
	turnValue++;
	turnValue %= static_cast<int32>(E_KTurnState::_Max);

	TurnState = static_cast<E_KTurnState>(turnValue);
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
