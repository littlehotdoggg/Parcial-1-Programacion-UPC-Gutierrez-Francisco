#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhotographableInterface.h"
#include "CodexComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PARCIAL1_PROG_API UCodexComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UCodexComponent();

	UFUNCTION(BlueprintCallable, Category = "Codex")
	void RegisterEvidence(FEvidenceData NewEvidence);

	UPROPERTY(BlueprintAssignable, Category = "Codex|Events")
	FOnEvidenceRecordedSignature OnEvidenceRecorded;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Codex")
	TArray<FEvidenceData> CapturedEvidence;
};