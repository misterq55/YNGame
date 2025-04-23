#pragma once

struct FYNPieceContext;

class FYNPieceTestCliView
{
public:
	FYNPieceTestCliView();
	FYNPieceTestCliView(const FYNPieceContext& pieceContext); 
	~FYNPieceTestCliView();

public:
	void Update(const FYNPieceContext& pieceContext);
};
