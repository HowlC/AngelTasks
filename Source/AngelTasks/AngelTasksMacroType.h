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
* 定义宏的名称，@param:...:代表任意参数, only for windows
* 发包，Send Account and Password to server
* 通过GameInstance调用该宏，暂不考虑加密（可在配置文件加密02A_05 03:15）
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