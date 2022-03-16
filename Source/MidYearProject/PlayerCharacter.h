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

public:

	virtual void BeginPlay() ovveride;

	virtual void Tick(float DeltaTime) ovveride;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) ovveride;
	
};
