// Aleksandr Ostrovskii. Live Long And Prosper.


#include "AnimInstances/Hero/ARPGHeroAnimInstance.h"
#include "Characters/ARPGHeroCharacter.h"

void UARPGHeroAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	if (OwningCharacter)
	{
		OwningHeroCharacter = Cast<AARPGHeroCharacter>(OwningCharacter);
	}
}

void UARPGHeroAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);

	if (bHasAcceleration)
	{
		IdleElaspedTimeSec = 0.f;
		bShouldEnterRelaxedIdleState = false;
	}
	else
	{
		IdleElaspedTimeSec += DeltaSeconds;
		bShouldEnterRelaxedIdleState = (IdleElaspedTimeSec >= EnterRelaxedIdleStateThreshouldSec);
	}
}
