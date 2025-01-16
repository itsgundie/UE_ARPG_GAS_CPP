// Aleksandr Ostrovskii. Live Long And Prosper.

#pragma once

#include "CoreMinimal.h"
#include "Characters/ARPGBaseCharacter.h"
#include "ARPGHeroCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

/**
 * 
 */
UCLASS()
class UE_ARPG_GAS_CPP_API AARPGHeroCharacter : public AARPGBaseCharacter
{
	GENERATED_BODY()
public:
	AARPGHeroCharacter();
protected:
	virtual void BeginPlay() override;

private:
#pragma region Components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;
#pragma endregion
};
