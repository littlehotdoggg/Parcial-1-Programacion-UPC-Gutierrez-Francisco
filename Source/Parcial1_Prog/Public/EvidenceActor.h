#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PhotographableInterface.h"
#include "EvidenceActor.generated.h"

UCLASS()
class PARCIAL1_PROG_API AEvidenceActor : public AActor, public IPhotographableInterface
{
	GENERATED_BODY()

public:
	AEvidenceActor();

	
	virtual FEvidenceData GetEvidenceData() const override;
	virtual bool IsPhotographable() const override;
	virtual void OnPhotographed() override;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Evidence Settings")
	FEvidenceData ObjectEvidenceData;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Evidence Settings")
	bool bHasBeenPhotographed = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* MeshComponent;
};