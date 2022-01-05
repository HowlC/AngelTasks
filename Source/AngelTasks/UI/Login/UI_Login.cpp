// Fill out your copyright notice in the Description page of Project Settings.


#include "UI_Login.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "UI_LoginMain.h"

void UUI_Login::SignIn()
{
	// 反向获取
	if (UUI_LoginMain* InLoginMain = GetParents<UUI_LoginMain>())
	{
		FString AccountString = Account->GetText().ToString();
		FString PasswordString = Password->GetText().ToString();

		InLoginMain->SignIn(AccountString, PasswordString);
	}
}

void UUI_Login::Register()
{
	if (UUI_LoginMain* InLoginMain = GetParents<UUI_LoginMain>())
	{
		InLoginMain->Register();
	}
}

void UUI_Login::NativeConstruct()
{
	Super::NativeConstruct();

	SignInButton->OnReleased.AddDynamic(this, &UUI_Login::SignIn);
	RegisterButton->OnReleased.AddDynamic(this, &UUI_Login::Register);
}

void UUI_Login::NativeDestruct()
{
	Super::NativeDestruct();
}