// Shoot Them Up Game. All Rights Reserved.

#include "AI/Services/STUCalculateDistance.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

USTUCalculateDistance::USTUCalculateDistance()
{
    NodeName = "CalculateDistance";
}

void USTUCalculateDistance::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    const auto Blackboard = OwnerComp.GetBlackboardComponent();
    const auto Controller = OwnerComp.GetAIOwner();
    const auto Player = Controller->GetPawn();
    const auto EnemyPlayer = Cast<APawn>(Blackboard->GetValueAsObject(EnemyActorKey.SelectedKeyName));
    if (EnemyPlayer)
    {
        const auto ToClose = (Player->GetActorLocation() - EnemyPlayer->GetActorLocation()).Size() <= BorderDistance;
        Blackboard->SetValueAsBool(DistanceKey.SelectedKeyName, ToClose);
    }
    else
    {
        Blackboard->SetValueAsBool(DistanceKey.SelectedKeyName, false);
    }
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}
