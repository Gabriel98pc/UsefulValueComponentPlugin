// Copyright 2023 Gabriel De la cruz, All rights reserved.

#include "UsefulValueActorTimer.h"

#include "Kismet/KismetMathLibrary.h"


AUsefulValueActorTimer::AUsefulValueActorTimer()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AUsefulValueActorTimer::BeginPlay()
{
	Super::BeginPlay();
}

void AUsefulValueActorTimer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!bReady)
		return;


	LerpValue = UKismetMathLibrary::FClamp(LerpValue + Speed * DeltaTime, 0, 1);

	OnLerpValueChanged(LerpValue);

	if (LerpValue == 1)
		K2_DestroyActor();
}

void AUsefulValueActorTimer::Setup(UUsefulValueComponent* _UsefulValueComponent, float _From, float _To, float _Speed)
{
	UsefulValueComponent = _UsefulValueComponent;
	From = _From;
	To = _To;
	Speed = _Speed;
	bReady = true;
}

void AUsefulValueActorTimer::OnLerpValueChanged(float CurrentLerpValue)
{
}
