#pragma once

#include "YNGame/Module/MVC/Controller/YNBaseController.h"

class FYNTestController : public FYNBaseController
{
public:
	FYNTestController();
	virtual ~FYNTestController();

public:
	virtual int32 RollYut() override;
};
