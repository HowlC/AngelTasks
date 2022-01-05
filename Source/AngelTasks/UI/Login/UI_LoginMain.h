/**
*
* UI Login Main.
*
* Original author: Howl Chang.
* Current maintainer: Howl Chang.
*
* Copyright EDanDan Studio.
*
* Handle creating client and link to server.
*
***********************************************************************************/
#pragma once

#include "CoreMinimal.h"
#include "../Core/UI_Base.h"
#include "SimpleNetChannelType.h"
#include "UI_Login.h"
#include "UI_LoginMain.generated.h"

class FSimpleChannel;
class UUI_Login;
class UTextBlock;

/**
 * 
 */
UCLASS()
class ANGELTASKS_API UUI_LoginMain : public UUI_Base
{
	GENERATED_BODY()

	/**
	* Intend to show information about this widget. Hide it when connect successful. 
	* Correspond to component name in BP_UI_LoginMain
	***********************************************************************************/
	UPROPERTY(meta = (BindWidget))
	UUserWidget* UI_LinkWidget;

	/**
	* Intend to show information about UI Login. Hide it when connect successful.
	* Correspond to component name in BP_UI_LoginMain
	***********************************************************************************/
	UPROPERTY(meta = (BindWidget))
	UUI_Login* UI_Login;

	/**
	* Show message log after connecting.
	* Correspond to component name in BP_UI_LoginMain
	***********************************************************************************/
	UPROPERTY(meta = (BindWidget))
	UTextBlock* MsgLog;
	
public:
	virtual void NativeConstruct();

	virtual void NativeDestruct();

public:
	/**
	* Send Account and Password to UI_Login for Sign In function.
	***********************************************************************************/
	void SignIn(const FString &, const FString &);

	/**
	* Send Register request to UI_Login for Sign In function.
	***********************************************************************************/
	void Register();

	/**
	* Print log
	***********************************************************************************/
	void PrintLog(const FString& InMsg);

protected:
	/**
	* Bind Game instance to UI. 
	* Execute after construction.
	***********************************************************************************/
	void BindClientRcv();

	/**
	* This function will be activated after server finish sending message to client.
	* Overriden.
	***********************************************************************************/
	virtual void RecvProtocol(uint32 ProtocolNumber, FSimpleChannel* Channel);

	/**
	* Link server to get information. 
	***********************************************************************************/
	UFUNCTION()
	void LinkServerInfo(ESimpleNetErrorType InType, const FString& InMsg);

private:
	FDelegateHandle RecvDelegate;
};
