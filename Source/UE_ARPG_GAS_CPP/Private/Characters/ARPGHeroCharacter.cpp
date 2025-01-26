// Aleksandr Ostrovskii. Live Long And Prosper.


#include "Characters/ARPGHeroCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputSubsystems.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "Components/Input/ARPGEnhancedInputComponent.h"
#include "ARPGGameplayTags.h"
#include "GAS/ARPGAbilitySystemComponent.h"

#include "ARPGDebugHelper.h"

AARPGHeroCharacter::AARPGHeroCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);
	
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 200.f;
	CameraBoom->SocketOffset = FVector(0.f, 55.f, 65.f);
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 500.f, 0.f);
	GetCharacterMovement()->MaxWalkSpeed = 400.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
}

void AARPGHeroCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (ARPGAbilitySystemComponent && ARPGAttributeSet)
	{
		const FString AbilitySystemInfo = FString::Printf(TEXT("Owner Actor: %s, AvatarActor: %s"), 
			*ARPGAbilitySystemComponent->GetOwnerActor()->GetActorLabel(), *ARPGAbilitySystemComponent->GetAvatarActor()->GetActorLabel());
		Debug::Print(TEXT("GAS component is valid. ") + AbilitySystemInfo, FColor::Green);
		Debug::Print(TEXT("GAS attribute is valid. ") + AbilitySystemInfo, FColor::Green);
	}
}

void AARPGHeroCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	checkf(InputConfigDataAsset, TEXT("Input config data asset is not assigned"));

	ULocalPlayer* LocalPlayer = GetController<APlayerController>()->GetLocalPlayer();
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);
	
	checkf(Subsystem, TEXT("EnhancedInputLocalPlayerSubsystem is Null, binding isn't possible"));

	Subsystem->AddMappingContext(InputConfigDataAsset->DefaultMappingContext, 0);
	UARPGEnhancedInputComponent* ARPGInputComponent = CastChecked<UARPGEnhancedInputComponent>(PlayerInputComponent);
	ARPGInputComponent->BindNativeInputAction(InputConfigDataAsset, ARPGGameplayTags::InputTag_Move, ETriggerEvent::Triggered, this, &ThisClass::Input_Move);
	ARPGInputComponent->BindNativeInputAction(InputConfigDataAsset, ARPGGameplayTags::InputTag_Look, ETriggerEvent::Triggered, this, &ThisClass::Input_Look);

}

void AARPGHeroCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AARPGHeroCharacter::Input_Move(const FInputActionValue& InputActionValue)
{
	const FVector2D MovementVector = InputActionValue.Get<FVector2D>();
	const FRotator MovementRotation(0.f, Controller->GetControlRotation().Yaw, 0.f);

	if (MovementVector.Y != 0.f)
	{
		const FVector ForwardDirection = MovementRotation.RotateVector(FVector::ForwardVector);
		AddMovementInput(ForwardDirection, MovementVector.Y);
	}

	if (MovementVector.X != 0.f)
	{
		const FVector RightDirection = MovementRotation.RotateVector(FVector::RightVector);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void AARPGHeroCharacter::Input_Look(const FInputActionValue& InputActionValue)
{
	const FVector2D LookAxisVector = InputActionValue.Get<FVector2D>();

	if (LookAxisVector.X != 0.f)
	{
		AddControllerYawInput(LookAxisVector.X);
	}

	if (LookAxisVector.Y != 0.f)
	{
		AddControllerPitchInput(LookAxisVector.Y);
	}
}
