// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "Patroller.h"


EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	auto aiOwner = OwnerComp.GetAIOwner();
	auto BlackBoardComp = OwnerComp.GetBlackboardComponent();
	int index = BlackBoardComp->GetValueAsInt(NextIndex.SelectedKeyName);
	AActor* wayPoint = (AActor*)BlackBoardComp->GetValueAsObject(Waypoint.SelectedKeyName);
	auto pawn = aiOwner->GetPawn();
	auto patroller = pawn->FindComponentByClass<UPatroller>();
	if (ensure(patroller))
	{
		if (patroller->GetPatrolPoints().Num() <= 0)
		{
			UE_LOG(LogTemp, Warning, TEXT("No Waypoints defined for %s"), *pawn->GetName());
			return EBTNodeResult::Failed;
		}

		BlackBoardComp->SetValueAsObject(Waypoint.SelectedKeyName, patroller->GetPatrolPoints()[index]);
		index++;
		BlackBoardComp->SetValueAsInt(NextIndex.SelectedKeyName, index % patroller->GetPatrolPoints().Num());

	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("MIssing Patroller component for %s"), *pawn->GetName());
		return EBTNodeResult::Failed;
	}

	return EBTNodeResult::Succeeded;
}
