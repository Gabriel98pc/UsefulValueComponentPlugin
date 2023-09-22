// Copyright 2023 Gabriel De la cruz, All rights reserved.
#pragma once

#include "CoreMinimal.h"
#include "UsefulValueActorTimer.h"
#include "UObject/Object.h"
#include "UsefulMinMainValueTimer.generated.h"

/**
 * 
 */
UCLASS()
class USEFULVALUECOMPONENTPLUGIN_API AUsefulMinMainValueTimer : public AUsefulValueActorTimer
{
	GENERATED_BODY()
public:

	virtual void OnLerpValueChanged(float CurrentLerpValue) override;
};
