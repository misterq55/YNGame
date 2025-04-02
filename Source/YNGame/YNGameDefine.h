#pragma once

class FYNPieceModel;
class FYNNodeModel;

enum class E_YNNestingState : uint8
{
	None,
	Leader,
	Nested,
};

enum class E_YNPieceState : uint8
{
	None,
	Idle,
	Moving,
};

enum class E_YNNodeType : uint8
{
	None,
	Start,
	Normal,
	Goal,
};

enum class E_KTurnState : uint8
{
	None,
};

struct FYNNodeContext
{
	FVector Pos = FVector::ZeroVector;
	FRotator Rot = FRotator::ZeroRotator;
	UClass* ViewActorClass = nullptr;
};

struct FYNPieceIndex
{
	int32 TeamIndex = 0;
	int32 PieceIndex = 0;
};

struct FYNPieceContext
{
	FYNPieceIndex Id;
	int32 CurrentNodeId = 0;
	E_YNNestingState NestingState = E_YNNestingState::None;
	E_YNPieceState PieceState = E_YNPieceState::None;
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