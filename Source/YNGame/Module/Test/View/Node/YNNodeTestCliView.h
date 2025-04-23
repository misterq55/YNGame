#pragma once

struct FYNNodeContext;

class FYNNodeTestCliView
{
public:
	FYNNodeTestCliView();
	FYNNodeTestCliView(const FYNNodeContext& nodeContext);
	~FYNNodeTestCliView();

public:
	void Update(const FYNNodeContext& nodeContext);
};
