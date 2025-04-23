#pragma once
#include "YNGame/Module/MVC/Model/YNModel.h"

class FYNTestModel : public FYNModel
{
public:
	FYNTestModel();
	virtual ~FYNTestModel();

public:
	virtual bool LoadBoard() override;
};
