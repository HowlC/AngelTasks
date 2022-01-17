/**
*
* Accomodate all macros/abbreviations for project to use.
*
* Original author: Howl Chang.
* Current maintainer: Howl Chang.
*
* Copyright EDanDan Studio.
*
* Just for convience.
*
***********************************************************************************/

#include "AngelTasksGameInstance.h"

/**
* ���������ƣ�@param:...:�����������, only for windows
* ������Send Account and Password to server
* ͨ��GameInstance���øú꣬�ݲ����Ǽ��ܣ����������ļ�����02A_05 03:15��
***********************************************************************************/
#if PLATFORM_WINDOWS
#define SEND_DATA(InProtocols,...) \
if (UAngelTasksGameInstance* InGameInstance_Macro = GetGameInstance<UAngelTasksGameInstance>()) \
{ \
	SIMPLE_CLIENT_SEND(InGameInstance_Macro->GetClient(), InProtocols,__VA_ARGS__); \
}
#else

/**
* mainly for mobile platform
***********************************************************************************/
#define SEND_DATA(InProtocols,args...) \
if (UAngelTasksGameInstance* InGameInstance_Macro = GetGameInstance<UAngelTasksGameInstance>()) \
{ \
	SIMPLE_CLIENT_SEND(InGameInstance_Macro->GetClient(), InProtocols, ##args); \
}
#endif