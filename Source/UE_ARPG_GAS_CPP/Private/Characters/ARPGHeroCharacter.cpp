// Aleksandr Ostrovskii. Live Long And Prosper.


#include "Characters/ARPGHeroCharacter.h"
#include "ARPGDebugHelper.h"

void AARPGHeroCharacter::BeginPlay()
{
	Super::BeginPlay();
	Debug::Print(TEXT("IT'S ALIVE!!!"));
}
