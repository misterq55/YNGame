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
	void ChangePiece();
	void SetMaxTeamCount(const int teamCount);
	void SetMaxPieceCount(const int pieceCount);
	void ChangeState(const E_KTurnState& newState);
	void AdvanceStep();
	int32 GetTurnOwnerTeamId() const;
	int32 GetTurnOwnerPieceId() const;

private:
	int32 TurnOwnerTeamId = 0;
	TArray<int32> TurnOwnerPieceIds;
	int32 MaxTeamCount = 0;
	int32 MaxPieceCount = 0;
	E_KTurnState TurnState;
	TSharedPtr<FYNTurnStateFSM> TurnStateFSM;
};
