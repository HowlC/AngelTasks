/**
*
* GameInstance acommodates all network functions.
*
* Original author: Howl Chang.
* Current maintainer: Howl Chang.
*
* Copyright EDanDan Studio.
*
* Include 2 main APIs:
* 1> Create Socket
* 2> Link to Server
* Expect server provide error info if connectiing action fail.
* 
* Cpp
*
***********************************************************************************/


#include "AngelTasksGameInstance.h"
#include "Global/SimpleNetGlobalInfo.h"
#include "ThreadManage.h"

void UAngelTasksGameInstance::Init()
{
	Super::Init();
}

void UAngelTasksGameInstance::Tick(float DeltaTime)
{
	// Execute Tick function of Client
	if (Client)
	{
		Client->Tick(DeltaTime);
		// Loop binding UI to gameinstance until success
		GThread::Get()->Tick(DeltaTime);
	}
}

TStatId UAngelTasksGameInstance::GetStatId() const
{
	return TStatId();
}

void UAngelTasksGameInstance::Shutdown()
{
	Super::Shutdown();

	if (Client)
	{
		FSimpleNetManage::Destroy(Client);
		GThread::Destroy();
	}
}

void UAngelTasksGameInstance::CreateClient()
{
	// Initialization, specify server port, ip etc. for client
	FSimpleNetGlobalInfo::Get()->Init();

	// Create client object
	Client = FSimpleNetManage::CreateManage(ESimpleNetLinkState::LINKSTATE_CONNET, ESimpleSocketType::SIMPLESOCKETTYPE_TCP);
}

void UAngelTasksGameInstance::LinkServer()
{
	if (Client)
	{
		// If not configed, it reads default value from Configuration sheet.
		if (!Client->Init())
		{
			delete Client;
			Client = NULL;
		}
	}
}

FSimpleNetManage* UAngelTasksGameInstance::GetClient()
{
	return Client;
}
