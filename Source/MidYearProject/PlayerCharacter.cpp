// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Engine/World.h"

void APlayerCharacter::BeginPlay() {

	Super::BeginPlay();
}

void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Mouse_X", this, &APlayerCharacter::Mouse_X);
	PlayerInputComponent->BindAxis("Mouse_Y", this, &APlayerCharacter::Mouse_Y);
	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &APlayerCharacter::StartAttack);
}

void APlayerCharacter::MoveForward(float Value)
{
	if (!bIsAlive)
		return;

	if (!bIsAttacking)
	{
		FRotator CamRot = GetControlRotation();
		CamRot.Pitch = 0.0f;
		FVector MoveDir = CamRot.Vector();

		GetCharacterMovement()->AddInputVector(MoveDir * Value);

	}
}

void APlayerCharacter::MoveRight(float Value)
{
	if (!bIsAlive)
		return;

	if (!bIsAttacking)
	{
		FRotator CamRot = GetControlRotation();
		CamRot.Pitch = 0.0f;
		FVector MoveDir = CamRot.RotateVector(FVector::RightVector);

		GetCharacterMovement()->AddInputVector(MoveDir * Value);

	}
}

void APlayerCharacter::Mouse_X(float Value)
{
	float Input = Value * 100.0f * GetWorld()->GetDeltaSeconds();
	AddControllerYawInput(Input);
}

void APlayerCharacter::Mouse_Y(float Value)
{
	float Input = Value * 100.0f * GetWorld()->GetDeltaSeconds();
	AddControllerPitchInput(Input);
}

void APlayerCharacter::StartAttack()
{
	bIsAttacking = true;
}

