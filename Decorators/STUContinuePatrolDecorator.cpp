// Shoot Them Up Game. All Rights Reserved.

#include "AI/Decorators/USTUContinuePatrolDecorator.h"
#include "BehaviorTree/BlackboardComponent.h"

USTUContinuePatrolDecorator::USTUContinuePatrolDecorator()
{
    NodeName = "DistanceToEnemy";
}

bool USTUContinuePatrolDecorator::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
    const auto Blackboard = OwnerComp.GetBlackboardComponent();
    if (!Blackboard) return false;

    if (FMath::FRand() < Probability) return true;

    return false;
}
