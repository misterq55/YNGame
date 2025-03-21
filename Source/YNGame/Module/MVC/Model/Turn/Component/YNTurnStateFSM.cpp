#include "YNTurnStateFSM.h"

#include "YNGame/Module/MVC/Model/Turn/YNTurn.h"

FYNTurnStateFSM::FYNTurnStateFSM()
{
}

FYNTurnStateFSM::~FYNTurnStateFSM()
{
}

void FYNTurnStateFSM::SetOwnerTurn(const TSharedPtr<FYNTurn>& ownerTurn)
{
	OwnerTurn = ownerTurn;
}

void FYNTurnStateFSM::changeState(const E_KTurnState& newState) const
{
	if (OwnerTurn.IsValid())
	{
		OwnerTurn.Pin()->ChangeState(newState);
	}
}
