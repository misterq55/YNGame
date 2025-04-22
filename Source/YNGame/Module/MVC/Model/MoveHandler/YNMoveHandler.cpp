#include "YNMoveHandler.h"
#include "YNGame/Module/MVC/Model/Piece/YNPieceModel.h"
#include "YNGame/Module/MVC/Model/Node/YNNodeModel.h"

void FYNMoveHandler::StartMove(const FYNMoveContext& moveContext)
{
	PieceModel = moveContext.PieceModel;
	MovePath = moveContext.NodeModels;

	if (MovePath.Num() < 2)
	{
		return;
	}

	CurrentStepIndex = 1;
	PrevNodeModel = MovePath[0];
	NextNodeModel = MovePath[1];

	PrevNodeModel->ClearStayingPieceIndex();
	PrevNodeModel->SetMovingPieceIndex(PieceModel->GetPieceIndex());
}

bool FYNMoveHandler::Update(float deltaTime)
{
	if (!PieceModel.IsValid() || MovePath.IsEmpty())
	{
		return false;
	}

	MoveTimer += deltaTime * MoveSpeed;

	const FVector newPos = FMath::Lerp(PrevNodeModel->GetPos(), NextNodeModel->GetPos(), MoveTimer);
	PieceModel->SetPos(newPos);
	PieceModel->ChangeState(E_YNPieceState::Moving);

	const FVector lookAtDir = (NextNodeModel->GetPos() - PrevNodeModel->GetPos()).GetSafeNormal();
	PieceModel->SetLookAt(lookAtDir);
	
	if (MoveTimer >= 1.f)
	{
		MoveTimer = 0.f;

		PrevNodeModel->ClearMovingPieceIndex();
		NextNodeModel->SetMovingPieceIndex(PieceModel->GetPieceIndex());
		PieceModel->SetNodeId(NextNodeModel->GetId());
		PieceModel->ChangeState(E_YNPieceState::Idle);
		
		if (CurrentStepIndex < MovePath.Num() - 1)
		{
			PrevNodeModel = NextNodeModel;
			NextNodeModel = MovePath[++CurrentStepIndex];
		}
		else
		{
			const int32 nodeId = NextNodeModel->GetId();
			const FYNPieceIndex& pieceIndex = PieceModel->GetPieceIndex();
			
			CurrentStepIndex = 1;
			PieceModel = nullptr;
			MovePath.Empty();

			MoveEndEvent.ExecuteIfBound(nodeId, pieceIndex);
		}
	}

	return true;
}
