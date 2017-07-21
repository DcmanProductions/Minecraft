// Fill out your copyright notice in the Description page of Project Settings.

#include "Minecraft.h"
#include "Block.h"


// Sets default values
ABlock::ABlock()
{
	SM_Block = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BlockMesh"));

	Resistance = 20.f;

	BreakingStage = 0.f;
	MiniumMaterial = 0;
}

// Called when the game starts or when spawned
void ABlock::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABlock::Break()
{
	++BreakingStage;

	float CrackingValue = 1.0f - (BreakingStage / 5.f);

	UMaterialInstanceDynamic* MatInstance = SM_Block->CreateDynamicMaterialInstance(0);

	if (MatInstance != nullptr)
	{
		MatInstance->SetScalarParameterValue(FName("CrackingValue"), CrackingValue);
	}
	if (BreakingStage == 5.0f)
	{
		OnBroken(true);
	}
}

void ABlock::OnBroken(bool HasRequiredPickaxe)
{
	Destroy();
}


void ABlock::ResetBlock()
{

	BreakingStage = 0.f;

	UMaterialInstanceDynamic* MatInstance = SM_Block->CreateDynamicMaterialInstance(0);

	if (MatInstance != nullptr) 
	{
		MatInstance->SetScalarParameterValue(FName("CrackingValue"), 1.0f);
	}

}
