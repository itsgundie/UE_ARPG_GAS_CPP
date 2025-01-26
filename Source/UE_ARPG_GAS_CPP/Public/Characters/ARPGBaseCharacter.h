// Aleksandr Ostrovskii. Live Long And Prosper.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "ARPGBaseCharacter.generated.h"

class UARPGAbilitySystemComponent;
class UARPGAttributeSet;

UCLASS()
class UE_ARPG_GAS_CPP_API AARPGBaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AARPGBaseCharacter();

	//~ Begin IAbilitySystem Interface.
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const;
	//~ End IAbilitySystem Interface

protected:
	//~ Begin APawn Interface.
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GAS")
	UARPGAbilitySystemComponent* ARPGAbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GAS")
	UARPGAttributeSet* ARPGAttributeSet;

public:
	__forceinline UARPGAbilitySystemComponent* GetARPGAbilitySystemComponent() const { return ARPGAbilitySystemComponent;}
	__forceinline UARPGAttributeSet* GetARPGAttributeSet() const { return ARPGAttributeSet;}
};
