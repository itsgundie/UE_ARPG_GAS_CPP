// Aleksandr Ostrovskii. Live Long And Prosper.


#include "DataAssets/Input/DataAsset_InputConfig.h"

UInputAction* UDataAsset_InputConfig::FindNativeInputActionByTag(const FGameplayTag& InInputTag)
{
	for (const FARPGInputActionConfig& InputActionConfig: NativeInputActions)
	{
		if (InputActionConfig.InputTag == InInputTag && InputActionConfig.InputAction)
			return InputActionConfig.InputAction;
	}
	return nullptr;
}
