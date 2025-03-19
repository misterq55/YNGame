#pragma once

enum E_YNNestingState
{
	None,
	Leader,
	Nested,
};

struct FYNNodeContext
{
	FVector Pos;
	FRotator Rot;
	UClass* ViewActorClass = nullptr;
};

struct FYNPieceContext
{
	int32 CurrentNodeId = 0;
	E_YNNestingState NestingState = None;
	int32 NestingCount = 0;
};

struct FYNPathResult
{
	TArray<int32> Path;
	bool bIsBlocked = false;
	bool bReachedStep = false;
};