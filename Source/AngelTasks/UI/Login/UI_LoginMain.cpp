/**
*
* UI Login Main.
*
* Original author: Howl Chang.
* Current maintainer: Howl Chang.
*
* Copyright EDanDan Studio.
*
* 发包执行类。
* Cpp
*
***********************************************************************************/


#include "UI_LoginMain.h"
#include "ThreadManage.h"
#include "UObject/SimpleController.h"
#include "Components/TextBlock.h"
#include "UI_Login.h"
#include "Protocol/LoginProtocol.h"
#include "../../AngelTasksMacroType.h"
#include "AngelTasksType.h"

void UUI_LoginMain::NativeConstruct()
{
	Super::NativeConstruct();

	// Allow UI_login to visit self.
	UI_Login->SetParents(this);

	// Create client AND LinkServer
	if (UAngelTasksGameInstance* InGameInstance = GetGameInstance<UAngelTasksGameInstance>())
	{
		InGameInstance->CreateClient();
		if (InGameInstance->GetClient())
		{
			InGameInstance->GetClient()->NetManageMsgDelegate.BindUObject(this,&UUI_LoginMain::LinkServerInfo);

			InGameInstance->LinkServer();

			BindClientRcv();
		}	
	}
}

void UUI_LoginMain::NativeDestruct()
{
	Super::NativeDestruct();

	// Unbind delegate when destruct
	if (UAngelTasksGameInstance* InGameInstance = GetGameInstance<UAngelTasksGameInstance>())
	{
		if (InGameInstance->GetClient() && InGameInstance->GetClient()->GetController())
		{
			InGameInstance->GetClient()->GetController()->RecvDelegate.Remove(RecvDelegate);
		}
	}
}

// CANNOT add "const" before "FString", or account and password info will not be transferred properly
void UUI_LoginMain::SignIn(FString& InAccount, FString& InPassword)
{
	// 发包，Send Account and Password to login server
	// 通过GameInstance调用该宏，暂不考虑加密（可在配置文件加密02A_05 03:15）
	// Defined in "AngelTasksMacroType.h"
	SEND_DATA(SP_LoginRequests, InAccount, InPassword);

}

void UUI_LoginMain::Register()
{

}

void UUI_LoginMain::PrintLog(const FString& InMsg)
{
	// Play animation

	MsgLog->SetText(FText::FromString(InMsg));
}

void UUI_LoginMain::BindClientRcv()
{
	if (UAngelTasksGameInstance* InGameInstance = GetGameInstance<UAngelTasksGameInstance>())
	{
		if (InGameInstance->GetClient() && InGameInstance->GetClient()->GetController())
		{
			RecvDelegate = InGameInstance->GetClient()->GetController()->RecvDelegate.AddLambda(
			[&](uint32 ProtocolNumber, FSimpleChannel* Channel)
			{
				this->RecvProtocol(ProtocolNumber, Channel);
				
			});
		}
		else
		{
			// If client is empty, retry binding after 0.5 secs.
			GThread::Get()->GetCoroutines().BindLambda(0.5f, [&]() {BindClientRcv(); });
		}
	}
	else
	{
		// If game instance is not ready, retry binding after 0.5 secs.
		GThread::Get()->GetCoroutines().BindLambda(0.5f, [&]() {BindClientRcv(); });
	}
}

void UUI_LoginMain::RecvProtocol(uint32 ProtocolNumber, FSimpleChannel* Channel)
{
	// Call back
	switch (ProtocolNumber)
	{
		// If receives login request
		case SP_LoginResponses: 
		{
			FString String;
			ELoginType Type = ELoginType::LOGIN_DB_SERVER_ERROR;

			// Get account info from client
			SIMPLE_PROTOCOLS_RECEIVE(SP_LoginResponses, Type, String);

			switch (Type)
			{
			case LOGIN_DB_SERVER_ERROR:
				PrintLog(TEXT("Server error."));
				break;
			case LOGIN_SUCCESS:
				PrintLog(TEXT("Login successfully."));
				break;
			case LOGIN_ACCOUNT_WRONG:
				PrintLog(TEXT("Account does not exist."));
				break;
			case LOGIN_WRONG_PASSWORD:
				PrintLog(TEXT("Wrong password."));
				break;
			}

			break;
		}
	}

}

void UUI_LoginMain::LinkServerInfo(ESimpleNetErrorType InType, const FString& InMsg)
{
	if (InType == ESimpleNetErrorType::HAND_SHAKE_SUCCESS)
	{
		UI_LinkWidget->SetVisibility(ESlateVisibility::Collapsed);
	}
}