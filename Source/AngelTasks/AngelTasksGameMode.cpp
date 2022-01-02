// Copyright Epic Games, Inc. All Rights Reserved.

#include "AngelTasksGameMode.h"
#include "AngelTasksCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAngelTasksGameMode::AAngelTasksGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
