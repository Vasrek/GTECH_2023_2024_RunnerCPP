#include "GameMode/GameModeRunner.h"
#include "../../../../Source/Runner/Public/Actors/Floors/FloorTile.h"

void AGameModeRunner::BeginPlay()
{
	CreateInitialFloorTiles();
}

void AGameModeRunner::CreateInitialFloorTiles()
{
	AFloorTile* Tile = AddFloorTile(false);

	if (Tile)
	{
		LaneSwitchValues.Add(Tile->LeftLane->GetComponentLocation().Y);
		LaneSwitchValues.Add(Tile->CenterLane->GetComponentLocation().Y);
		LaneSwitchValues.Add(Tile->RightLane->GetComponentLocation().Y);
	}

	//for (float Val : LaneSwitchValues)
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("LANE VALUE: %f"), Val);
	//}

	AddFloorTile(false);
	AddFloorTile(false);


	for (int i = 0; i < NumItinitalFloorTiles; i++)
	{
		AddFloorTile(true);
	}
}

AFloorTile* AGameModeRunner::AddFloorTile(const bool bSpawnItems)
{
	UWorld* World = GetWorld();

	if (World)
	{
		AFloorTile* Tile = World->SpawnActor<AFloorTile>(FloorTileClass, NextSpawnPoint);

		if (Tile)
		{
			if (bSpawnItems)
			{
				Tile->SpawnItems();
			}

			NextSpawnPoint = Tile->GetAttachTransform();
		}

		return Tile;
	}

	return nullptr;

}

void AGameModeRunner::AddCoin()
{
	TotalCoins += 1;

	UE_LOG(LogTemp, Warning, TEXT("TOTAL COINS: %d"), TotalCoins);
}


