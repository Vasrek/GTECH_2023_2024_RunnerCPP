// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/GameModeRunner.h"
#include "../../../../Source/Runner/Public/Actors/Floors/FloorTile.h"

void AGameModeRunner::BeginPlay()
{
	CreateInitialFloorTiles();
}

void AGameModeRunner::CreateInitialFloorTiles()
{
	AFloorTile* Tile = AddFloorTile();

	if (Tile)
	{
		LaneSwitchValues.Add(Tile->LeftLane->GetComponentLocation().Y);
		LaneSwitchValues.Add(Tile->CenterLane->GetComponentLocation().Y);
		LaneSwitchValues.Add(Tile->RightLane->GetComponentLocation().Y);
	}

	for (float Val : LaneSwitchValues)
	{
		UE_LOG(LogTemp, Warning, TEXT("LANE VALUE: %f"), Val);
	}

	for (int i = 0; i < NumItinitalFloorTiles; i++)
	{
		AddFloorTile();
	}
}

AFloorTile* AGameModeRunner::AddFloorTile()
{
	UWorld* World = GetWorld();

	if (World)
	{
		AFloorTile* Tile = World->SpawnActor<AFloorTile>(FloorTileClass, NextSpawnPoint);

		if (Tile)
		{
			NextSpawnPoint = Tile->GetAttachTransform();
		}

		return Tile;
	}

	return nullptr;

}


