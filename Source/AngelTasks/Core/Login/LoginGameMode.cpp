/**
*
* Login GameMode.
*
* Original author: Howl Chang.
* Current maintainer: Howl Chang.
*
* Copyright EDanDan Studio.
*
* Specify HUD, DefaultPawnClass and PlayerController for login Menu.
*
***********************************************************************************/


#include "LoginGameMode.h"
#include "LoginHUD.h"
#include "LoginPawn.h"
#include "LoginPlayerController.h"

ALoginGameMode::ALoginGameMode()
{
	HUDClass = ALoginHUD::StaticClass();
	DefaultPawnClass = ALoginPawn::StaticClass();
	PlayerControllerClass = ALoginPlayerController::StaticClass();
}