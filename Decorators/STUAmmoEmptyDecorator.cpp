// Shoot Them Up Game. All Rights Reserved.


#include "AI/Decorators/STUAmmoEmptyDecorator.h"
#include "AIController.h"
#include "STUUtils.h"
#include "Components/STUWeaponComponent.h"

USTUAmmoEmptyDecorator::USTUAmmoEmptyDecorator() 
{
    NodeName = "AmmoEmpty";
}

bool USTUAmmoEmptyDecorator::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
    const auto Controller = OwnerComp.GetAIOwner();
    if (!Controller) return false;

    const auto WeaponComponent = STUUtils::GetSTUPlayerComponent<USTUWeaponComponent>(Controller->GetPawn());
    if (!WeaponComponent) return false;

    return WeaponComponent->AllAmmoEmpty();
}
