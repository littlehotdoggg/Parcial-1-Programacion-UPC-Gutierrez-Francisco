#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PhotographableInterface.generated.h"

USTRUCT(BlueprintType)
struct FEvidenceData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Evidence")
	FName EvidenceID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Evidence")
	FString EvidenceName;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Evidence")
	bool bIsCaptured = false;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEvidenceRecordedSignature, const FEvidenceData&, RecordedEvidence);

UINTERFACE(MinimalAPI)
class UPhotographableInterface : public UInterface { GENERATED_BODY() };

class PARCIAL1_PROG_API IPhotographableInterface
{
	GENERATED_BODY()

public:
	virtual FEvidenceData GetEvidenceData() const = 0;
	virtual bool IsPhotographable() const = 0;
	virtual void OnPhotographed() = 0;
};