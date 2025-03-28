#include "YNMoveHandler.h"
#include "YNGame/Module/MVC/Model/Piece/YNPieceModel.h"
#include "YNGame/Module/MVC/Model/Node/YNNodeModel.h"

void FYNMoveHandler::StartMove(FYNMoveContext moveContext)
{
	PieceModel = moveContext.PieceModel;
	MovePath = moveContext.NodeModels;
	PrevNodeModel = MovePath[0];
}

void FYNMoveHandler::Update(float deltaTime)
{
	if (!PieceModel.IsValid() || MovePath.IsEmpty())
	{
		return;
	}
	
	MoveTimer += deltaTime;
	if (MoveTimer > 1.f)
	{
		MoveTimer = 0.f;

		if (CurrentStepIndex < MovePath.Num())
		{
			TSharedPtr<FYNNodeModel>& nextModel = MovePath[CurrentStepIndex];

			PieceModel->SetNodeId(nextModel->GetId());
			PieceModel->ChangeState(E_YNPieceState::Moving);
			
			++CurrentStepIndex;
		}
		else
		{
			CurrentStepIndex = 1;
			PieceModel->ChangeState(E_YNPieceState::Idle);
			PieceModel = nullptr;
			MovePath.Empty();
		}
	}
}
