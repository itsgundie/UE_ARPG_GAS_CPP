// Aleksandr Ostrovskii. Live Long And Prosper.


#include "Characters/ARPGBaseCharacter.h"

// Sets default values
AARPGBaseCharacter::AARPGBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetMesh()->bReceivesDecals = false;
}