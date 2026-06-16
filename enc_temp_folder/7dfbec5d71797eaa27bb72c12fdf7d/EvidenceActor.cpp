#include "EvidenceActor.h"

AEvidenceActor::AEvidenceActor()
{
	PrimaryActorTick.bCanEverTick = false;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;
}

FEvidenceData AEvidenceActor::GetEvidenceData() const
{
	return ObjectEvidenceData;
}

bool AEvidenceActor::IsPhotographable() const
{
	return !bHasBeenPhotographed;
}

void AEvidenceActor::OnPhotographed()
{
	bHasBeenPhotographed = true;

	
	if (MeshComponent)
	{
		MeshComponent->SetVisibility(false);
		MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
}