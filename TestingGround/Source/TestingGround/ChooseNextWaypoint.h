// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "ChooseNextWaypoint.generated.h"


/**
 * 
 */
UCLASS()
class TESTINGGROUND_API UChooseNextWaypoint : public UBTTaskNode
{
	GENERATED_BODY()

		virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
public:

protected:
	UPROPERTY(EditAnywhere, Category = "Blackboard")
	struct FBlackboardKeySelector NextIndex;

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	struct FBlackboardKeySelector Waypoint;

};
