// Aleksandr Ostrovskii. Live Long And Prosper.

#pragma once

#include "CoreMinimal.h"
#include "Characters/ARPGBaseCharacter.h"
#include "ARPGHeroCharacter.generated.h"

/**
 * 
 */
UCLASS()
class UE_ARPG_GAS_CPP_API AARPGHeroCharacter : public AARPGBaseCharacter
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;
};
