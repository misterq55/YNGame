#pragma once

class AYNPieceActor;
struct FYNPieceContext;

class FYNPieceView
{
public:
	FYNPieceView();
	FYNPieceView(const FYNPieceContext& pieceContext); 
	~FYNPieceView();

public:
	void Update(const FYNPieceContext& pieceContext);

private:
	TObjectPtr<AYNPieceActor> PieceActor;
};
