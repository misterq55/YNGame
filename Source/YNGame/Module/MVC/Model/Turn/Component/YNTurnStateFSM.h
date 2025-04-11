#pragma once

class FYNTurn;
enum class E_KStepState : uint8;

class FYNTurnStateFSM
{
public:
	FYNTurnStateFSM();
	~FYNTurnStateFSM();

public:
	void SetOwnerTurn(const TSharedPtr<FYNTurn>& ownerTurn);

private:
	void changeState(const E_KStepState& newState) const;

private:
	TWeakPtr<FYNTurn> OwnerTurn;
};
