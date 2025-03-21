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
}

void FYNTurn::ChangeState(const E_KTurnState& newState)
{
	TurnState = newState;
}

int32 FYNTurn::GetTurnOwnerTeamId() const
{
	return TurnOwnerTeamId;
}

int32 FYNTurn::GetTurnOwnerPieceId() const
{
	return TurnOwnerPieceId;
}
