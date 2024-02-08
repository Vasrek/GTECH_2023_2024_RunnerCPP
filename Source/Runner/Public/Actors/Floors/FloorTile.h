#pragma once


#include "CoreMinimal.h"

#include "Components/ArrowComponent.h"
#include "GameFramework/Actor.h"
#include "FloorTile.generated.h"

class UStaticMeshComponent;
class USceneComponent;
class UBoxComponent;
class AObstacles;
class ACoinsItems;

UCLASS()
class RUNNER_API AFloorTile : public AActor
{
	GENERATED_BODY()
	
public:	
	AFloorTile();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Config)
	TSubclassOf<AObstacles> SmallObstacleClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Config)
	TSubclassOf<AObstacles> BigObstacleClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Config)
	TSubclassOf<ACoinsItems> CoinClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* FloorMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UArrowComponent* AttachPoint;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UArrowComponent* CenterLane;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UArrowComponent* RightLane;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UArrowComponent* LeftLane;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UBoxComponent* FloorTriggerBox;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Config)
	float SpawnPercent1 = 0.1f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Config)
	float SpawnPercent2 = 0.3f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Config)
	float SpawnPercent3 = 0.5f;

	FORCEINLINE const FTransform& GetAttachTransform() const
	{
		return AttachPoint->GetComponentTransform();
	}

	UFUNCTION(BlueprintCallable)
	void SpawnItems();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleInstanceOnly)
	class AGameModeRunner* RunGameMode;

	UPROPERTY()
	FTimerHandle DestroyHandle;

	UFUNCTION()
	void OnTriggerBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);

	UFUNCTION()
	void DestroyFloorTile();

	UFUNCTION()
	void SpawnLaneItem(UArrowComponent* Lane);
};
