// Aleksandr Ostrovskii. Live Long And Prosper.

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/ARPGBaseAnimInstance.h"
#include "ARPGCharacterAnimInstance.generated.h"

class AARPGBaseCharacter;
class UCharacterMovementComponent;
/**
 * 
 */
UCLASS()
class UE_ARPG_GAS_CPP_API UARPGCharacterAnimInstance : public UARPGBaseAnimInstance
{
	GENERATED_BODY()
	
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY()
	AARPGBaseCharacter* OwningCharacter;

	UPROPERTY()
	UCharacterMovementComponent* OwnerMovementComponent;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	float GroundSpeed;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	bool bHasAcceleration;
};
