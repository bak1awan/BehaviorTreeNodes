// Shoot Them Up Game. All Rights Reserved.

#include "AI/Decorators/STUDistanceToEnemyDecorator.h"
#include "AIController.h"
#include "STUUtils.h"
#include "Components/STUWeaponComponent.h"
#include "Components/STUAIPerceptionComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

USTUDistanceToEnemyDecorator::USTUDistanceToEnemyDecorator()
{
    NodeName = "DistanceToEnemy";
}

bool USTUDistanceToEnemyDecorator::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
    const auto Blackboard = OwnerComp.GetBlackboardComponent();
    if (!Blackboard) return false;

    if (FMath::FRand() < Probability) return true;

    return false;
}
