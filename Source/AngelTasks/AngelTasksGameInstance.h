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
***********************************************************************************/

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "SimpleNetManage.h"
#include "AngelTasksGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class ANGELTASKS_API UAngelTasksGameInstance : public UGameInstance, public FTickableGameObject
{
	GENERATED_BODY()
	
public:
	virtual void Init();
		
	virtual void Tick(float DeltaTime);

	/**
	* Make game instance support Tick function. With help of FTickableGameObject.
	***********************************************************************************/
	virtual TStatId GetStatId() const;

	virtual void Shutdown();

public:
	/**
	* API 1, Create Socket / Client.
	***********************************************************************************/
	void CreateClient(); 

	/**
	* API 2, Link to server.
	***********************************************************************************/
	void LinkServer();

	/**
	* Return client instance for functions in higher layer to use.
	***********************************************************************************/
	FSimpleNetManage* GetClient();

private:
	FSimpleNetManage* Client;
};
