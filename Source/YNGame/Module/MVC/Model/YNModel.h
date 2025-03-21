#pragma once
#include "YNGame/Module/Interface/IYNModel.h"

class FYNTeamManager;
class FYNBoardManager;
class FYNTurn;

class FYNModel : public IYNModel
{
public:
	FYNModel();
	virtual ~FYNModel();
	
public:
	virtual void Initialize() override;
	virtual void StartPlay() override;
	virtual void AddNode(const FVector& newPos) override;
	virtual void AddTeams(const int32 teamCount, const int32 pieceCount) override;
	virtual void AdvanceStep() override;
	virtual void ChangeTurn() override;
	virtual void Move(const int32 steps) override;
	virtual bool IsRepeat() override;
	virtual FYNNodeContext& FindNodeContext(const int32 nodeId) override;
	virtual FYNPieceContext& FindPieceContext(const int32 teamId, const int32 pieceId) override;

protected:
	TSharedPtr<FYNBoardManager> BoardMgr;
	TSharedPtr<FYNTeamManager> TeamMgr;
	TSharedPtr<FYNTurn> CurrentTurn;
};
