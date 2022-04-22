// Shoot Them Up Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "USTUContinuePatrolDecorator.generated.h"


UCLASS()
class SHOOTTHEMUP_API USTUContinuePatrolDecorator : public UBTDecorator
{
	GENERATED_BODY()
public:
    USTUContinuePatrolDecorator();

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI", meta = (ClampMin = "0.0", ClampMax = "1.0"))
    float Probability;

    virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};
