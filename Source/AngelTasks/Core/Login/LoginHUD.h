/**
*
* Login HUD.
*
* Original author: Howl Chang.
* Current maintainer: Howl Chang.
*
* Copyright EDanDan Studio.
*
* Construct UI_LoginMain instance for menu.
*
***********************************************************************************/

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "LoginHUD.generated.h"

class UUI_LoginMain;

/**
 * 
 */
UCLASS()
class ANGELTASKS_API ALoginHUD : public AHUD
{
	GENERATED_BODY()

	/**
	* Prevent garbage collection for container, which contain UI classes
	***********************************************************************************/
	UPROPERTY()
	TSubclassOf<UUI_LoginMain> LoginMainClass;

public:
	ALoginHUD();

	/**
	* Called when the game starts or when spawned
	***********************************************************************************/
	virtual void BeginPlay() override;

private:

	/**
	* Used for widget creating in login menu.
	***********************************************************************************/
	UUI_LoginMain* LoginMain;
	
};
