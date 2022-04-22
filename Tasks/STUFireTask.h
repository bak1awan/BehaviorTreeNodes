// Shoot Them Up Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "STUFireTask.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTTHEMUP_API USTUFireTask : public UBTTaskNode
{
	GENERATED_BODY()
public:
    USTUFireTask();
    virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);

protected:
};
