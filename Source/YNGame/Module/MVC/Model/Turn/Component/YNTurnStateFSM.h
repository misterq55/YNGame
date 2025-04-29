#pragma once

class FYNTurn;
enum class E_YNStepState : uint8;

class FYNTurnStateFSM
{
public:
	FYNTurnStateFSM();
	~FYNTurnStateFSM();

public:
	void SetOwnerTurn(const TSharedPtr<FYNTurn>& ownerTurn);

private:
	void changeState(const E_YNStepState& newState) const;

private:
	TWeakPtr<FYNTurn> OwnerTurn;
};
