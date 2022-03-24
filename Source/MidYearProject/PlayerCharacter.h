// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ArenaCharacter.h"
#include "PlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class MIDYEARPROJECT_API APlayerCharacter : public AArenaCharacter
{
	GENERATED_BODY()

	void StartAttack();
	void EndAttack();

public:

	virtual void BeginPlay();

	virtual void Tick(float DeltaTime);

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent);
	
protected:

	void MoveForward(float Value);
	void MoveRight(float Value);


	void Mouse_X(float Value);
	void Mouse_Y(float Value);

};
