// Aleksandr Ostrovskii. Live Long And Prosper.


#include "AnimInstances/ARPGCharacterAnimInstance.h"
#include "Characters/ARPGBaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void UARPGCharacterAnimInstance::NativeInitializeAnimation()
{
	OwningCharacter = Cast<AARPGBaseCharacter>(TryGetPawnOwner());

	if (OwningCharacter)
	{
		OwnerMovementComponent = OwningCharacter->GetCharacterMovement();
	}
}

void UARPGCharacterAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	if (!OwningCharacter || !OwnerMovementComponent)
	{
		return;
	}
	
	GroundSpeed = OwningCharacter->GetVelocity().Size2D();

	bHasAcceleration = OwnerMovementComponent->GetCurrentAcceleration().Size2D() > 0.f;
}
