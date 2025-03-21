#pragma once

class FYNTurnStateFSM;
enum class E_KTurnState : uint8;

class FYNTurn
{
public:
	FYNTurn();
	~FYNTurn();

public:
	void Initialize();
	void ChangeTurn();
	void ChangeState(const E_KTurnState& newState);
	int32 GetTurnOwnerTeamId() const;
	int32 GetTurnOwnerPieceId() const;

private:
	int32 TurnOwnerTeamId = 0;
	int32 TurnOwnerPieceId = 0;
	E_KTurnState TurnState;
	TSharedPtr<FYNTurnStateFSM> TurnStateFSM;
};
