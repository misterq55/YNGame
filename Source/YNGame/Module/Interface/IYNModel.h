#pragma once

struct FYNNodeContext;
struct FYNPieceContext;

class IYNModel
{
public:
	virtual void Initialize() = 0;
	virtual void AddNode(const FVector& newPos) = 0;
	virtual void AddTeams(const int32 teamCount, const int32 pieceCount) = 0;
	virtual void AddTeam() = 0;
	virtual void AdvanceStep() = 0;
	virtual void ChangeTurn() = 0;
	virtual void Move(const int32 steps) = 0;
	virtual bool IsRepeat() = 0;
	virtual void Update(float deltaTimes) = 0;
	virtual FYNNodeContext& FindNodeContext(const int32 nodeId) = 0;
	virtual FYNPieceContext& FindPieceContext(const int32 teamId, const int32 pieceId) = 0;
};