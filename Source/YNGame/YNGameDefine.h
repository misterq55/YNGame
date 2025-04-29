#pragma once

class FYNPieceModel;
class FYNNodeModel;

enum class E_YNGameState : uint8
{
	None,
	OrderSelection,
	Game,
	End,
	_Max,
};

enum class E_YNPieceState : uint8
{
	None,
	Unspawned,
	Idle,
	Moving,
	Nested,
	Goal,
	_Max,
};

enum class E_YNNodeType : uint8
{
	None,
	Start,
	Normal,
	Goal,
	_Max,
};

enum class E_YNStepState : uint8
{
	None,
	RollYut,
	MovePiece,
	_Max,
};

struct FYNNodeContext
{
	FVector Pos = FVector::ZeroVector;
	FRotator Rot = FRotator::ZeroRotator;
	UClass* ViewActorClass = nullptr;
};

struct FYNPieceIndex
{
	int32 TeamIndex = -1;
	int32 PieceIndex = -1;
};

struct FYNPieceContext
{
	FYNPieceIndex Id;
	int32 CurrentNodeId = 0;
	E_YNPieceState PieceState = E_YNPieceState::None;
	int32 NestingLeaderIndex = 0;
	int32 NestingCount = 0;
	FVector Pos = FVector::ZeroVector;
	FVector LookAt = FVector::ZeroVector;
};

struct FYNPathResult
{
	TArray<int32> Path;
	bool bIsBlocked = false;
	bool bReachedStep = false;
};

struct FYNMoveContext
{
	TSharedPtr<FYNPieceModel> PieceModel = nullptr;
	TArray<TSharedPtr<FYNNodeModel>> NodeModels;
};

struct FYNDirectionalConnection
{
	int32 FromNodeId = -1;
	int32 ToNodeId = -1;
};