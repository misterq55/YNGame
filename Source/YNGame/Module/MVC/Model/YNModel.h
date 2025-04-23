#pragma once
#include "YNGame/Module/Interface/IYNModel.h"

class FYNTeamManager;
class FYNBoardManager;
class FYNTurn;
class FYNMoveHandler;

class FYNModel : public IYNModel
{
public:
	FYNModel();
	virtual ~FYNModel();
	
public:
	virtual void Initialize() override;
	virtual void AddNode(const FVector& newPos) override;
	virtual void AddTeams(const int32 teamCount, const int32 pieceCount) override;
	virtual void AddTeam() override;
	virtual void AdvanceStep() override;
	virtual void ChangeTurn() override;
	virtual E_KStepState GetCurrentStepState() override;
	virtual void Move(const int32 steps) override;
	virtual void OnMoveEnd(const int32 nodeId, const FYNPieceIndex& pieceIndex) override;
	virtual bool IsRepeat() override;
	virtual void Update(float deltaTimes) override;
	virtual bool LoadBoard() override;
	virtual FYNNodeContext& FindNodeContext(const int32 nodeId) override;
	virtual FYNPieceContext& FindPieceContext(const int32 teamId, const int32 pieceId) override;
	virtual FYNPieceModelCreateEvent& GetOnPieceModelCreateEvent() override;
	virtual FYNNodeModelCreateEvent& GetOnNodeModelCreateEvent() override;
	virtual FYNPieceModelUpdateEvent& GetOnPieceModelUpdateEvent() override;
	virtual FYNNodeModelUpdateEvent& GetOnNodeModelUpdateEvent() override;

protected:
	TSharedPtr<FYNBoardManager> BoardMgr;
	TSharedPtr<FYNTeamManager> TeamMgr;
	TSharedPtr<FYNTurn> CurrentTurn;
	TSharedPtr<FYNMoveHandler> MoveHandler;
	FYNPieceModelCreateEvent OnPieceModelCreateEvent;
	FYNNodeModelCreateEvent OnNodeModelCreateEvent;
	FYNPieceModelUpdateEvent OnPieceModelUpdateEvent;
	FYNNodeModelUpdateEvent OnNodeModelUpdateEvent;
};


