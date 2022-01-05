/**
*
* Login Pawn
*
* Original author: Howl Chang.
* Current maintainer: Howl Chang.
*
* Copyright EDanDan Studio.
*
* Disable viewport movement comparing to default pawn class.
*
***********************************************************************************/

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "LoginPawn.generated.h"

UCLASS()
class ANGELTASKS_API ALoginPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ALoginPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
