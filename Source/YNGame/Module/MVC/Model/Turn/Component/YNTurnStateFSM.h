#pragma once

class FYNTurn;
enum class E_KTurnState : uint8;

class FYNTurnStateFSM
{
public:
	FYNTurnStateFSM();
	~FYNTurnStateFSM();

public:
	void SetOwnerTurn(const TSharedPtr<FYNTurn>& ownerTurn);

private:
	void changeState(const E_KTurnState& newState) const;

private:
	TWeakPtr<FYNTurn> OwnerTurn;
};
