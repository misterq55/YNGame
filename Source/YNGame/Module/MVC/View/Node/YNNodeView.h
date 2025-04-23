#pragma once

class AYNNodeActor;
struct FYNNodeContext;

class FYNNodeView
{
public:
	FYNNodeView();
	FYNNodeView(const FYNNodeContext& nodeContext);
	~FYNNodeView();

public:
	void Update(const FYNNodeContext& nodeContext);

private:
	TObjectPtr<AYNNodeActor> NodeActor;
};
