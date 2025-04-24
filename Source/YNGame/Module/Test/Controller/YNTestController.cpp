#include "YNTestController.h"

FYNTestController::FYNTestController()
{
}

FYNTestController::~FYNTestController()
{
}

int32 FYNTestController::RollYut()
{
	// TODO
	// 임시값
	const int yutValue = (FMath::Rand() % 6) - 1;
	return yutValue;
}
