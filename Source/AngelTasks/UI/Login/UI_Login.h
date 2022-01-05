/**
*
* UI Login.
*
* Original author: Howl Chang.
* Current maintainer: Howl Chang.
*
* Copyright EDanDan Studio.
*
* Transfer data from blueprint to cpp.
*
***********************************************************************************/

#pragma once

#include "CoreMinimal.h"
#include "../Core/UI_Base.h"
#include "UI_Login.generated.h"

class UEditableTextBox;
class UButton;
/**
 * 
 */
UCLASS()
class ANGELTASKS_API UUI_Login : public UUI_Base
{
	GENERATED_BODY()

	/**
	* Expose variables from blueprint to C++. 
	***********************************************************************************/
	UPROPERTY(meta = (BindWidget))
	UEditableTextBox* Account;

	UPROPERTY(meta = (BindWidget))
	UEditableTextBox* Password;

	UPROPERTY(meta = (BindWidget))
	UButton* SignInButton;

	UPROPERTY(meta = (BindWidget))
	UButton* RegisterButton;

public:
	virtual void NativeConstruct();

	virtual void NativeDestruct();

	UFUNCTION()
	void SignIn();

	UFUNCTION()
	void Register();

};
