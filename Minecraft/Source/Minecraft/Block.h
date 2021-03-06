// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Block.generated.h"

UCLASS()
class MINECRAFT_API ABlock : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABlock();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
		UStaticMeshComponent* SM_Block;

	int32 MiniumMaterial;

	UPROPERTY(EditDefaultsOnly)
		float Resistance;
	UPROPERTY(BlueprintReadWrite)
		float BreakingStage;

	//Called Everytime we want to break the block further
	void Break();

	void ResetBlock();

	//Called once the block has hit the final breaking stage
	void OnBroken(bool HasRequiredPickaxe);

};
