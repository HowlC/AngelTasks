/**
*
* Login HUD.
*
* Original author: Howl Chang.
* Current maintainer: Howl Chang.
*
* Copyright EDanDan Studio.
*
* Create widget in HUD begin play.
*
***********************************************************************************/



#include "LoginHUD.h"
#include "../../UI/Login/UI_LoginMain.h"

ALoginHUD::ALoginHUD()
{
	static ConstructorHelpers::FClassFinder<UUI_LoginMain> LoginMain_BPClass(TEXT("/Game/UI/Login/BP_UI_LoginMain"));
	LoginMainClass = LoginMain_BPClass.Class;
}

void ALoginHUD::BeginPlay()
{
	Super::BeginPlay();

	if (LoginMainClass)
	{
		LoginMain = CreateWidget<UUI_LoginMain>(GetWorld(), LoginMainClass);
		LoginMain->AddToViewport();
	}
}