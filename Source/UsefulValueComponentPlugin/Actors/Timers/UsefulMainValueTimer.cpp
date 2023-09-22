// Copyright 2023 Gabriel De la cruz, All rights reserved.

#include "UsefulMainValueTimer.h"

#include "Kismet/KismetMathLibrary.h"

void AUsefulMainValueTimer::OnLerpValueChanged(float CurrentLerpValue)
{
	Super::OnLerpValueChanged(CurrentLerpValue);

	if (!IsValid(UsefulValueComponent))
		return;

	UsefulValueComponent->SetMainValue(UKismetMathLibrary::Lerp(From, To, CurrentLerpValue));
}
