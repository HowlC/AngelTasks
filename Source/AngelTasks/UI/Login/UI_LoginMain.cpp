/**
*
* UI Login Main.
*
* Original author: Howl Chang.
* Current maintainer: Howl Chang.
*
* Copyright EDanDan Studio.
*
* Cpp
*
***********************************************************************************/


#include "UI_LoginMain.h"
#include "ThreadManage.h"
#include "UObject/SimpleController.h"
#include "../../AngelTasksGameInstance.h"
#include "Components/TextBlock.h"
#include "UI_Login.h"

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

void UUI_LoginMain::SignIn(const FString& InAccount, const FString& InPassword)
{

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

}

void UUI_LoginMain::LinkServerInfo(ESimpleNetErrorType InType, const FString& InMsg)
{
	if (InType == ESimpleNetErrorType::HAND_SHAKE_SUCCESS)
	{
		UI_LinkWidget->SetVisibility(ESlateVisibility::Collapsed);
	}
}