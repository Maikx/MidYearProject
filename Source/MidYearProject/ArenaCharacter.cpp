// Fill out your copyright notice in the Description page of Project Settings.


#include "ArenaCharacter.h"

// Sets default values
AArenaCharacter::AArenaCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AArenaCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AArenaCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AArenaCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AArenaCharacter::StartAttack()
{
	UE_LOG(LogTemp, Warning, TEXT("Attack"));
	TakeDamage(0.2f);
	//bIsAttacking;
}

void AArenaCharacter::TakeDamage(float _damageAmount)
{
	UE_LOG(LogTemp, Warning, TEXT("Damage for %f points."), _damageAmount);
	health -= _damageAmount;

	if (health < 0.0f)
	{
		health = 0.0f;
		bIsAlive = false;
	}
}

