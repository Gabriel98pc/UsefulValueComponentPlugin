// Copyright 2023 Gabriel De la cruz, All rights reserved.

#include "UsefulValueComponent.h"

#include "PhysXSupportCore.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Net/UnrealNetwork.h"
#include "UsefulValueComponentPlugin/Actors/Timers/UsefulMainValueTimer.h"
#include "UsefulValueComponentPlugin/Actors/Timers/UsefulMaxMainValueTimer.h"
#include "UsefulValueComponentPlugin/Actors/Timers/UsefulMinMainValueTimer.h"


UUsefulValueComponent::UUsefulValueComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	SetIsReplicatedByDefault(true);
}


void UUsefulValueComponent::BeginPlay()
{
	Super::BeginPlay();
}


void UUsefulValueComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                          FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UUsefulValueComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UUsefulValueComponent, MainValue);
	DOREPLIFETIME(UUsefulValueComponent, MinMainValue);
	DOREPLIFETIME(UUsefulValueComponent, MaxMainValue);
}

void UUsefulValueComponent::OnRep_MainValue()
{
	OnMainValueUpdatedEvent.Broadcast(MainValue);
}

void UUsefulValueComponent::OnRep_MinMainValue()
{
	OnMinMainValueUpdatedEvent.Broadcast(MinMainValue);
}

void UUsefulValueComponent::OnRep_MaxMainValue()
{
	OnMaxMainValueUpdatedEvent.Broadcast(MaxMainValue);
}

//Main Value

void UUsefulValueComponent::SetMainValue(float Value)
{
	SetMainValue_Server(Value);
}

void UUsefulValueComponent::AddMainValue(float Amount)
{
	AddMainValue_Server(Amount);
}

void UUsefulValueComponent::RemoveMainValue(float Amount)
{
	RemoveMainValue_Server(Amount);
}

//

void UUsefulValueComponent::SetMainValue_Server_Implementation(float Value)
{
	CheckAndDeleteCurrentTimersForThisComponent();
	MainValue = UKismetMathLibrary::FClamp(Value, MinMainValue, MaxMainValue);
	SetMainValue_NetMulticast(MainValue);
}

void UUsefulValueComponent::AddMainValue_Server_Implementation(float Amount)
{
	CheckAndDeleteCurrentTimersForThisComponent();
	MainValue = UKismetMathLibrary::FClamp(MainValue + Amount, MinMainValue, MaxMainValue);
	AddMainValue_NetMulticast(MainValue);
}

void UUsefulValueComponent::RemoveMainValue_Server_Implementation(float Amount)
{
	CheckAndDeleteCurrentTimersForThisComponent();
	MainValue = UKismetMathLibrary::FClamp(MainValue - Amount, MinMainValue, MaxMainValue);
	RemoveMainValue_NetMulticast(MainValue);
}

//

void UUsefulValueComponent::SetMainValue_NetMulticast_Implementation(float Value)
{
	OnMainValueUpdatedEvent.Broadcast(MainValue);
}

void UUsefulValueComponent::AddMainValue_NetMulticast_Implementation(float Amount)
{
	OnMainValueUpdatedEvent.Broadcast(MainValue);
}

void UUsefulValueComponent::RemoveMainValue_NetMulticast_Implementation(float Amount)
{
	OnMainValueUpdatedEvent.Broadcast(MainValue);
}

//Min Main Value

void UUsefulValueComponent::SetMinMainValue(float Value)
{
	SetMinMainValue_Server(Value);
}

void UUsefulValueComponent::AddMinMainValue(float Amount)
{
	AddMinMainValue_Server(Amount);
}

void UUsefulValueComponent::RemoveMinMainValue(float Amount)
{
	RemoveMinMainValue_Server(Amount);
}

//

void UUsefulValueComponent::SetMinMainValue_Server_Implementation(float Value)
{
	CheckAndDeleteCurrentTimersForThisComponent();
	MinMainValue = Value;
	SetMinMainValue_NetMulticast(MinMainValue);
}

void UUsefulValueComponent::AddMinMainValue_Server_Implementation(float Amount)
{
	CheckAndDeleteCurrentTimersForThisComponent();
	MinMainValue = MinMainValue + Amount;
	AddMinMainValue_NetMulticast(MinMainValue);
}

void UUsefulValueComponent::RemoveMinMainValue_Server_Implementation(float Amount)
{
	CheckAndDeleteCurrentTimersForThisComponent();
	MinMainValue = MinMainValue - Amount;
	RemoveMinMainValue_NetMulticast(MinMainValue);
}

//

void UUsefulValueComponent::SetMinMainValue_NetMulticast_Implementation(float Value)
{
	OnMinMainValueUpdatedEvent.Broadcast(MinMainValue);
}

void UUsefulValueComponent::AddMinMainValue_NetMulticast_Implementation(float Amount)
{
	OnMinMainValueUpdatedEvent.Broadcast(MinMainValue);
}

void UUsefulValueComponent::RemoveMinMainValue_NetMulticast_Implementation(float Amount)
{
	OnMinMainValueUpdatedEvent.Broadcast(MinMainValue);
}

//Max Main Value

void UUsefulValueComponent::SetMaxMainValue(float Value)
{
	SetMaxMainValue_Server(Value);
}

void UUsefulValueComponent::AddMaxMainValue(float Amount)
{
	AddMaxMainValue_Server(Amount);
}

void UUsefulValueComponent::RemoveMaxMainValue(float Amount)
{
	RemoveMaxMainValue_Server(Amount);
}

//

void UUsefulValueComponent::SetMaxMainValue_Server_Implementation(float Value)
{
	CheckAndDeleteCurrentTimersForThisComponent();
	MaxMainValue = Value;
	SetMaxMainValue_NetMulticast(MaxMainValue);
}

void UUsefulValueComponent::AddMaxMainValue_Server_Implementation(float Amount)
{
	CheckAndDeleteCurrentTimersForThisComponent();
	MaxMainValue = MaxMainValue + Amount;
	AddMaxMainValue_NetMulticast(MaxMainValue);
}

void UUsefulValueComponent::RemoveMaxMainValue_Server_Implementation(float Amount)
{
	CheckAndDeleteCurrentTimersForThisComponent();
	MaxMainValue = MaxMainValue - Amount;
	RemoveMaxMainValue_NetMulticast(MaxMainValue);
}

//

void UUsefulValueComponent::SetMaxMainValue_NetMulticast_Implementation(float Value)
{
	OnMaxMainValueUpdatedEvent.Broadcast(MaxMainValue);
}

void UUsefulValueComponent::AddMaxMainValue_NetMulticast_Implementation(float Amount)
{
	OnMaxMainValueUpdatedEvent.Broadcast(MaxMainValue);
}

void UUsefulValueComponent::RemoveMaxMainValue_NetMulticast_Implementation(float Amount)
{
	OnMaxMainValueUpdatedEvent.Broadcast(MaxMainValue);
}

//Special Functions

void UUsefulValueComponent::SetMainValueInTime(float From, float To, float Speed)
{
	SetMainValueInTime_Server(From, To, Speed);
}

void UUsefulValueComponent::SetMinMainValueInTime(float From, float To, float Speed)
{
	SetMinMainValueInTime_Server(From, To, Speed);
}

void UUsefulValueComponent::SetMaxMainValueInTime(float From, float To, float Speed)
{
	SetMaxMainValueInTime_Server(From, To, Speed);
}

//

void UUsefulValueComponent::SetMainValueInTime_Server_Implementation(float From, float To, float Speed)
{
	CheckAndDeleteCurrentTimersForThisComponent();

	AUsefulMainValueTimer* UsefulValueActorTimer = Cast<AUsefulMainValueTimer>(
		SpawnActor(GetOwner(), GetOwner(), AUsefulMainValueTimer::StaticClass(), FTransform()));

	UsefulValueActorTimer->Setup(this, From, To, Speed);
}

void UUsefulValueComponent::SetMinMainValueInTime_Server_Implementation(float From, float To, float Speed)
{
	CheckAndDeleteCurrentTimersForThisComponent();

	AUsefulMinMainValueTimer* UsefulValueActorTimer = Cast<AUsefulMinMainValueTimer>(
		SpawnActor(GetOwner(), GetOwner(), AUsefulMinMainValueTimer::StaticClass(), FTransform()));

	UsefulValueActorTimer->Setup(this, From, To, Speed);
}

void UUsefulValueComponent::SetMaxMainValueInTime_Server_Implementation(float From, float To, float Speed)
{
	CheckAndDeleteCurrentTimersForThisComponent();

	AUsefulMaxMainValueTimer* UsefulValueActorTimer = Cast<AUsefulMaxMainValueTimer>(
		SpawnActor(GetOwner(), GetOwner(), AUsefulMaxMainValueTimer::StaticClass(), FTransform()));

	UsefulValueActorTimer->Setup(this, From, To, Speed);
}

//Others Functions

AActor* UUsefulValueComponent::SpawnActor(const UObject* WorldContextObject, AActor* Owner,
                                          const TSubclassOf<AActor> ActorClass, FTransform Transform)
{
	if (!WorldContextObject)
		return nullptr;

	if (!Owner)
		return nullptr;

	if (!ActorClass)
		return nullptr;

	const FTransform SpawnTransform = Transform;
	FActorSpawnParameters ActorSpawnParameters;

	ActorSpawnParameters.Owner = Owner;

	if (APawn* InstigatorPawn = Cast<APawn>(Owner))
		ActorSpawnParameters.Instigator = InstigatorPawn;

	ActorSpawnParameters.SpawnCollisionHandlingOverride =
		ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	AActor* SpawnedChaosMeterApplicatorActor = WorldContextObject->GetWorld()->SpawnActor(
		ActorClass, &SpawnTransform, ActorSpawnParameters);

	return SpawnedChaosMeterApplicatorActor;
}

void UUsefulValueComponent::CheckAndDeleteCurrentTimersForThisComponent()
{
	TArray<AActor*> FoundedActors;

	UGameplayStatics::GetAllActorsOfClass(GetOwner(), AUsefulValueActorTimer::StaticClass(), FoundedActors);

	for (AActor* Actor : FoundedActors)
	{
		AUsefulValueActorTimer* UsefulValueActorTimer = Cast<AUsefulValueActorTimer>(Actor);

		if (UsefulValueActorTimer->GetUsefulValueComponent() == this)
			UsefulValueActorTimer->K2_DestroyActor();
	}
}
