/**
*
* UI Base
*
* Original author: Howl Chang.
* Current maintainer: Howl Chang.
*
* Copyright EDanDan Studio.
*
* Itself servers as base for all ui in this project.
* Mainly used to get GameInstance.
*
***********************************************************************************/

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI_Base.generated.h"

class FSimpleChannel;
/**
 * 
 */
UCLASS()
class ANGELTASKS_API UUI_Base : public UUserWidget
{
	GENERATED_BODY()
	
protected:

	/**
	* Get Player Controller through template.
	***********************************************************************************/
	template<class T>
	T* GetPlayerController()
	{
		return GetWorld() != nullptr ? GetWorld()->GetFirstPlayerController<T>() : nullptr;
	}

	/**
	* Get Pawn through template.
	***********************************************************************************/
	template<class T>
	T* GetPawn()
	{
		return GetWorld() != nullptr ? 
			(GetWorld()->GetFirstPlayerController() != nullptr ? 
			GetWorld()->GetFirstPlayerController()->GetPawn<T>() : nullptr) : nullptr;
	}


	/**
	* Get GameInstance through template.
	***********************************************************************************/
	template<class T>
	T* GetGameInstance()
	{
		return GetWorld() != nullptr ? GetWorld()->GetGameInstance<T>() : nullptr;
	}

public:
	/**
	* Allow UI_Login visit UI_LoginMain by this function by SetParents()
	***********************************************************************************/
	template<class T>
	T *GetParents()
	{
		return Cast<T>(ParentWidget);
	}
	void SetParents(UWidget* InWidget) { ParentWidget = InWidget; }

protected:

	/**
	* This function will be activated after server finish sending message to client.
	***********************************************************************************/
	virtual void RecvProtocol(uint32 ProtocolNumber, FSimpleChannel* Channel) {}

protected:
	UPROPERTY()
	UWidget* ParentWidget;

};
