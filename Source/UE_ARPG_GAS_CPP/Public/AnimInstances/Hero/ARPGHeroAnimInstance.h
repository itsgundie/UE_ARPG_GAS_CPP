// Aleksandr Ostrovskii. Live Long And Prosper.

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/ARPGCharacterAnimInstance.h"
#include "ARPGHeroAnimInstance.generated.h"

class AARPGHeroCharacter;
/**
 * 
 */
UCLASS()
class UE_ARPG_GAS_CPP_API UARPGHeroAnimInstance : public UARPGCharacterAnimInstance
{
	GENERATED_BODY()
	
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|References")
	AARPGHeroCharacter* OwningHeroCharacter;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	bool bShouldEnterRelaxedIdleState;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	float EnterRelaxedIdleStateThreshouldSec = 5.f;

	float IdleElaspedTimeSec;
};
