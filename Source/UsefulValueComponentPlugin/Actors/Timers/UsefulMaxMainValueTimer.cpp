// Copyright 2023 Gabriel De la cruz, All rights reserved.

#include "UsefulMaxMainValueTimer.h"

#include "Kismet/KismetMathLibrary.h"

void AUsefulMaxMainValueTimer::OnLerpValueChanged(float CurrentLerpValue)
{
	Super::OnLerpValueChanged(CurrentLerpValue);

	if (!IsValid(UsefulValueComponent))
		return;

	UsefulValueComponent->SetMaxMainValue(UKismetMathLibrary::Lerp(From, To, CurrentLerpValue));
}
