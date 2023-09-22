// Copyright 2023 Gabriel De la cruz, All rights reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UsefulValueComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnValueUpdated, float, Value);


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class USEFULVALUECOMPONENTPLUGIN_API UUsefulValueComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UUsefulValueComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

public:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public: //Base Variables
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Base Variables|Value")
	float BaseMainValue = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, ReplicatedUsing=OnRep_MainValue, Category="Base Variables|Value")
	float MainValue = 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Base Variables|MinValue")
	float BaseMinMainValue = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, ReplicatedUsing=OnRep_MinMainValue, Category="Base Variables|MinValue")
	float MinMainValue = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Base Variables|MaxValue")
	float BaseMaxMainValue = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, ReplicatedUsing=OnRep_MaxMainValue, Category="Base Variables|MaxValue")
	float MaxMainValue = 1;

public: //OnRepEvents

	UFUNCTION()
	void OnRep_MainValue();

	UFUNCTION()
	void OnRep_MinMainValue();

	UFUNCTION()
	void OnRep_MaxMainValue();

public: //Events

	UPROPERTY(BlueprintAssignable)
	FOnValueUpdated OnMainValueUpdatedEvent;

	UPROPERTY(BlueprintAssignable)
	FOnValueUpdated OnMinMainValueUpdatedEvent;

	UPROPERTY(BlueprintAssignable)
	FOnValueUpdated OnMaxMainValueUpdatedEvent;

public: //Basic Functions

	UFUNCTION(BlueprintCallable, Category="MainValue|Value")
	void SetMainValue(float Value);

	UFUNCTION(BlueprintCallable, Category="MainValue|Value")
	void AddMainValue(float Amount);

	UFUNCTION(BlueprintCallable, Category="MainValue|Value")
	void RemoveMainValue(float Amount);

	//

	UFUNCTION(Server, Reliable, Category="MainValue|Value")
	void SetMainValue_Server(float Value);

	UFUNCTION(Server, Reliable, Category="MainValue|Value")
	void AddMainValue_Server(float Amount);

	UFUNCTION(Server, Reliable, Category="MainValue|Value")
	void RemoveMainValue_Server(float Amount);


	UFUNCTION(NetMulticast, Reliable, Category="MainValue|Value")
	void SetMainValue_NetMulticast(float Value);

	UFUNCTION(NetMulticast, Reliable, Category="MainValue|Value")
	void AddMainValue_NetMulticast(float Amount);

	UFUNCTION(NetMulticast, Reliable, Category="MainValue|Value")
	void RemoveMainValue_NetMulticast(float Amount);

	//

	UFUNCTION(BlueprintCallable, Category="MainValue|MinValue")
	void SetMinMainValue(float Value);

	UFUNCTION(BlueprintCallable, Category="MainValue|MinValue")
	void AddMinMainValue(float Amount);

	UFUNCTION(BlueprintCallable, Category="MainValue|MinValue")
	void RemoveMinMainValue(float Amount);


	UFUNCTION(Server, Reliable, Category="MainValue|MinValue")
	void SetMinMainValue_Server(float Value);

	UFUNCTION(Server, Reliable, Category="MainValue|MinValue")
	void AddMinMainValue_Server(float Amount);

	UFUNCTION(Server, Reliable, Category="MainValue|MinValue")
	void RemoveMinMainValue_Server(float Amount);


	UFUNCTION(NetMulticast, Reliable, Category="MainValue|MinValue")
	void SetMinMainValue_NetMulticast(float Value);

	UFUNCTION(NetMulticast, Reliable, Category="MainValue|MinValue")
	void AddMinMainValue_NetMulticast(float Amount);

	UFUNCTION(NetMulticast, Reliable, Category="MainValue|MinValue")
	void RemoveMinMainValue_NetMulticast(float Amount);

	//

	UFUNCTION(BlueprintCallable, Category="MainValue|MaxValue")
	void SetMaxMainValue(float Value);

	UFUNCTION(BlueprintCallable, Category="MainValue|MaxValue")
	void AddMaxMainValue(float Amount);

	UFUNCTION(BlueprintCallable, Category="MainValue|MaxValue")
	void RemoveMaxMainValue(float Amount);


	UFUNCTION(Server, Reliable, Category="MainValue|MaxValue")
	void SetMaxMainValue_Server(float Value);

	UFUNCTION(Server, Reliable, Category="MainValue|MaxValue")
	void AddMaxMainValue_Server(float Amount);

	UFUNCTION(Server, Reliable, Category="MainValue|MaxValue")
	void RemoveMaxMainValue_Server(float Amount);


	UFUNCTION(NetMulticast, Reliable, Category="MainValue|MaxValue")
	void SetMaxMainValue_NetMulticast(float Value);

	UFUNCTION(NetMulticast, Reliable, Category="MainValue|MaxValue")
	void AddMaxMainValue_NetMulticast(float Amount);

	UFUNCTION(NetMulticast, Reliable, Category="MainValue|MaxValue")
	void RemoveMaxMainValue_NetMulticast(float Amount);

public: //Special Functions

	UFUNCTION(BlueprintCallable, Category="MainValue|Value")
	void SetMainValueInTime(float From, float To, float Speed);

	UFUNCTION(BlueprintCallable, Category="MainValue|MinValue")
	void SetMinMainValueInTime(float From, float To, float Speed);

	UFUNCTION(BlueprintCallable, Category="MainValue|MaxValue")
	void SetMaxMainValueInTime(float From, float To, float Speed);

	//

	UFUNCTION(Server, Reliable, Category="MainValue|Value")
	void SetMainValueInTime_Server(float From, float To, float Speed);

	UFUNCTION(Server, Reliable, Category="MainValue|MinValue")
	void SetMinMainValueInTime_Server(float From, float To, float Speed);

	UFUNCTION(Server, Reliable, Category="MainValue|MaxValue")
	void SetMaxMainValueInTime_Server(float From, float To, float Speed);

public:
	UFUNCTION()
	AActor* SpawnActor(const UObject* WorldContextObject, AActor* Owner, const TSubclassOf<AActor> ActorClass,
	                   FTransform Transform);

	UFUNCTION(BlueprintCallable, meta=(CompactNodeTitle="Remove All Timers"))
	void CheckAndDeleteCurrentTimersForThisComponent();
};
