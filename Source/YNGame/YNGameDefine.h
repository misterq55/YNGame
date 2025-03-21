#pragma once

enum class E_YNNestingState : uint8
{
	None,
	Leader,
	Nested,
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

struct FYNPieceContext
{
	int32 CurrentNodeId = 0;
	E_YNNestingState NestingState = E_YNNestingState::None;
	int32 NestingCount = 0;
};

struct FYNPathResult
{
	TArray<int32> Path;
	bool bIsBlocked = false;
	bool bReachedStep = false;
};