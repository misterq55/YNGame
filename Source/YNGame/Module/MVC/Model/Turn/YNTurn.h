#pragma once

class FYNTurnStateFSM;
enum class E_YNStepState : uint8;

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
	void ChangeStepState(const E_YNStepState& newState);
	void AdvanceStep();
	int32 GetTurnOwnerTeamId() const;
	int32 GetTurnOwnerPieceId() const;
	E_YNStepState GetStepState() const;
	void SetTeamOrder(const TArray<int>& teamOrders);

private:
	TArray<int32> TeamOrders;
	int32 TeamOrderIndex = 0;
	int32 TurnOwnerTeamId = 0;
	TArray<int32> TurnOwnerPieceIds;
	int32 MaxTeamCount = 0;
	int32 MaxPieceCount = 0;
	E_YNStepState StepState;
	TSharedPtr<FYNTurnStateFSM> TurnStateFSM;
};
