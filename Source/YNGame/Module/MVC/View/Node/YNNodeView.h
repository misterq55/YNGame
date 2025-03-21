#pragma once

class AYNNodeActor;
struct FYNNodeContext;

class FYNNodeView
{
public:
	FYNNodeView();
	~FYNNodeView();

public:
	void Update(const FYNNodeContext& nodeContext);

private:
	TObjectPtr<AYNNodeActor> NodeActor;
};
