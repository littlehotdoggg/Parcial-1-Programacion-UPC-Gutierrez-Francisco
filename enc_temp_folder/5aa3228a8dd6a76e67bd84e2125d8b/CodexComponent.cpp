#include "CodexComponent.h"

UCodexComponent::UCodexComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UCodexComponent::RegisterEvidence(FEvidenceData NewEvidence)
{
	NewEvidence.bIsCaptured = true;
	CapturedEvidence.Add(NewEvidence);

	UE_LOG(LogTemp, Warning, TEXT("Evidencia Registrada: %s"), *NewEvidence.EvidenceName);
	OnEvidenceRecorded.Broadcast(NewEvidence);
}