// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ArenaCharacter.generated.h"

UCLASS()
class MIDYEARPROJECT_API AArenaCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AArenaCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Takes damage
	void TakeDamage(float _damageAmount);

	//The current ammount of health the character has.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health");
	float health;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		bool bIsAttacking = false;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		bool bIsAlive = true;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
