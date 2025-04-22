#pragma once

enum class E_KStepState : uint8;
struct FYNNodeContext;
struct FYNPieceContext;
struct FYNPieceIndex;
DECLARE_DELEGATE_TwoParams(FYNPieceModelCreateEvent, const int32, const int32)
DECLARE_DELEGATE_OneParam(FYNNodeModelCreateEvent, const int32)
DECLARE_DELEGATE_ThreeParams(FYNPieceModelUpdateEvent, const int32, const int32, const FYNPieceContext&)
DECLARE_DELEGATE_TwoParams(FYNNodeModelUpdateEvent, const int32, const FYNNodeContext&)

class IYNModel
{
public:
	virtual void Initialize() = 0;
	virtual void AddNode(const FVector& newPos) = 0;
	virtual void AddTeams(const int32 teamCount, const int32 pieceCount) = 0;
	virtual void AddTeam() = 0;
	virtual void AdvanceStep() = 0;
	virtual void ChangeTurn() = 0;
	virtual E_KStepState GetCurrentStepState() = 0;
	virtual void Move(const int32 steps) = 0;
	virtual void OnMoveEnd(const int32 nodeId, const FYNPieceIndex& pieceIndex) = 0;
	virtual bool IsRepeat() = 0;
	virtual void Update(float deltaTimes) = 0;
	virtual FYNNodeContext& FindNodeContext(const int32 nodeId) = 0;
	virtual FYNPieceContext& FindPieceContext(const int32 teamId, const int32 pieceId) = 0;
	virtual FYNPieceModelCreateEvent& GetOnPieceModelCreateEvent() = 0;
	virtual FYNNodeModelCreateEvent& GetOnNodeModelCreateEvent() = 0;
	virtual FYNPieceModelUpdateEvent& GetOnPieceModelUpdateEvent() = 0;
	virtual FYNNodeModelUpdateEvent& GetOnNodeModelUpdateEvent() = 0;
};