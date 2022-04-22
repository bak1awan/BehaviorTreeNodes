// Shoot Them Up Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "STUCalculateDistance.generated.h"

/**
 *
 */
UCLASS()
class SHOOTTHEMUP_API USTUCalculateDistance : public UBTService
{
    GENERATED_BODY()
public:
    USTUCalculateDistance();

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    FBlackboardKeySelector EnemyActorKey;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    FBlackboardKeySelector DistanceKey;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    float BorderDistance;

    virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
