// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bird.h"
#include "FlockManager.generated.h"


class ABird;
class ABigBird;

UCLASS()
class LEARN_API AFlockManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFlockManager();

	TArray<AActor*>AllBirds;

	TMap<int,TArray<AActor*>>Groups;



	UFUNCTION()
		void Initialize();

	UFUNCTION()
		void MergeFlock(TArray<AActor*>NewFlock);

	UFUNCTION()
		void DestroyFlock(TArray<AActor*>NewFlock, FVector spawnloc);


		void CheckUnique(TArray<AActor*>RF);

	UFUNCTION()
		void tf(); 


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "bigbird")
	TSubclassOf<ABigBird>BB;

	UPROPERTY(EditAnywhere, Category = "bigbird")
		TSubclassOf<ABird> MyActorClass = ABird::StaticClass();

	TArray<TArray<AActor*>>Cool;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
