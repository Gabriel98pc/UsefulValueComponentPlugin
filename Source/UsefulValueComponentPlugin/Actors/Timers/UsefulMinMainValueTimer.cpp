// Copyright 2023 Gabriel De la cruz, All rights reserved.

#include "UsefulMinMainValueTimer.h"

#include "Kismet/KismetMathLibrary.h"

void AUsefulMinMainValueTimer::OnLerpValueChanged(float CurrentLerpValue)
{
	Super::OnLerpValueChanged(CurrentLerpValue);

	if (!IsValid(UsefulValueComponent))
		return;

	UsefulValueComponent->SetMinMainValue(UKismetMathLibrary::Lerp(From, To, CurrentLerpValue));
}
