// Copyright 2023 Gabriel De la cruz, All rights reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UsefulValueComponentPlugin/Component/UsefulValueComponent.h"
#include "UsefulValueActorTimer.generated.h"

UCLASS()
class USEFULVALUECOMPONENTPLUGIN_API AUsefulValueActorTimer : public AActor
{
	GENERATED_BODY()

public:
	AUsefulValueActorTimer();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

protected:
	float LerpValue = 0;
	UUsefulValueComponent* UsefulValueComponent = nullptr;
	float From = 0;
	float To = 0;
	float Speed = 0;

	bool bReady = false;

public:
	UFUNCTION()
	void Setup(UUsefulValueComponent* _UsefulValueComponent, float _From, float _To, float _Speed);

	virtual void OnLerpValueChanged(float CurrentLerpValue);

	FORCEINLINE UUsefulValueComponent* GetUsefulValueComponent() const { return UsefulValueComponent; };
};
