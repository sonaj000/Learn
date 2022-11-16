// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Bird.generated.h"


class UBoxComponent;
class ABirdController;


UCLASS()
class LEARN_API ABird : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABird();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Component")
		UBoxComponent* FlockPerimeter;

	UPROPERTY()
		bool bcanDetect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Component")
		UStaticMeshComponent* BirdMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "stats")
		int MergeNum;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "stats")
		int DamageNum;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "stats")
		int Health;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
		ABirdController* Remote;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
		virtual void BeginOverLap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		virtual void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};


