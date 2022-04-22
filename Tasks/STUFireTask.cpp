// Shoot Them Up Game. All Rights Reserved.

#include "AI/Tasks/STUFireTask.h"
#include "Components/STUAIPerceptionComponent.h"
#include "Components/STUWeaponComponent.h"
#include "AIController.h"
#include "AI/STUAIController.h"
#include "STUUtils.h"

DEFINE_LOG_CATEGORY_STATIC(FireTaskLog, All, All);

USTUFireTask::USTUFireTask()
{
    NodeName = "FireTask";
}

EBTNodeResult::Type USTUFireTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    const auto Controller = Cast<ASTUAIController>(OwnerComp.GetAIOwner());
    const auto Player = Controller->GetPawn();

    if (!Controller || !Player) return EBTNodeResult::Failed;

    const auto WeaponComponent = STUUtils::GetSTUPlayerComponent<USTUWeaponComponent>(Player);
    if (!WeaponComponent) return EBTNodeResult::Failed;
    WeaponComponent->StopFire();

    const auto EnemyPlayer = Controller->GetFocusOnActor();
    if (!EnemyPlayer) return EBTNodeResult::Failed;

    if (EnemyPlayer) WeaponComponent->StartFire();
    WeaponComponent->StopFire();

    return EBTNodeResult::Succeeded;
}
